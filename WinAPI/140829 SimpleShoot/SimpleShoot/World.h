/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	대표적인 개병신 코드됨...
	나중에 필요하면 refactoring함..
*/

#pragma once

#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <vector>
#include "Object.h"


using std::vector;

class World{
public:
	World(){
		srand(time(NULL));
		_player = Player({ 300, 500 }, 25);
		_map = {};
	}

	World(Obstacle &obs){
		_obstacle.push_back(&obs);
		_map = {};
	}

	void updateMap(RECT& winRect){
		_map = winRect;
	}

	void kbDown(WPARAM& wParam){
		switch (wParam){
		case VK_RIGHT:
			_player.setDir(RIGHT);
			break;
		case VK_LEFT:
			_player.setDir(LEFT);
			break;
		case VK_UP:
			_player.setDir(UP);
			break;
		case VK_DOWN:
			_player.setDir(DOWN);
			break;
		case VK_SPACE:
			//맵 위에 총알 생성
			Bullet* ptr = new Bullet(_player.getPos().x, _player.getPos().y);
			_vbullets.push_back(ptr);
			ptr = nullptr;
			break;
		}
	}

	void kbUp(WPARAM& wParam){
		switch (wParam){
		case VK_RIGHT:
			_player.unsetDir(RIGHT);
			break;
		case VK_LEFT:
			_player.unsetDir(LEFT);
			break;
		case VK_UP:
			_player.unsetDir(UP);
			break;
		case VK_DOWN:
			_player.unsetDir(DOWN);
			break;
		}
	}

	void Update(float delta){
		// 일단 고정값으로 시작
		// 점점 길어지는 if... 고치기 귀찮다..
		if (_obstacle.size() > 0){
			// 플레이어와 부딪히지 않았을 경우
			if (!EllipseCollider()){
				// 체력 많으면 계쏙 업데이트
				if (_obstacle[0]->getHP() > 0){
					if (_obstacle[0]->checkBound(_map)){
						// 장애물이 아래 맵에 부딛혔을때 처리
						Obstacle* ptr = _obstacle[0];
						delete ptr;
						ptr = nullptr;
						_obstacle.pop_back();
						_obstacle.shrink_to_fit();
					}
					else {
						if (_obstacle.size() > 0){
							// 안부딪혔을경우 업데이트
							_obstacle[0]->update(delta);
						}
					}
				}
				// 체력 떨어지면 삭제
				else {
					_obstacle.pop_back();
				}
			}
			// 플레이어랑 부딪혔을 경우
			else {
				// 게임오버 트리거
				_gameOver = true;
				_obstacle.pop_back();
			}
		}
		else{
			Obstacle* ptr = new Obstacle({ rand() % _map.right + 50, 100 }, 50);
			_obstacle.push_back(ptr);
		}

		if (_player.checkBound(_map)){
			// TODO: 다른쪽으로는 움직일수 있게 차후 추가
		}
		else {
			_player.update(delta);
		}

		// 맞으면 렌더삭제 대신에 오브젝트 삭제

		// 일단 하나만
		// 여러번 콜하면 동기화 에러난다....
		if (_vbullets.size() > 0){
			for (int i = 0; i < _vbullets.size(); i++){
				_vbullets[i]->update(delta);
				if (BulletColliderHelper(*_vbullets[i])){
					Bullet* ptr = _vbullets[i];
					delete ptr;
					_vbullets.erase(_vbullets.begin() + i);
					_vbullets.shrink_to_fit();
					ptr = nullptr;
					//
					if (_obstacle.size() > 0){
						_obstacle[0]->getHitted();
					}
					//
				}
			}
			/*if (!_vbullets.empty()){
				if (_vbullets[0]->checkBound(_map)){
				Bullet* ptr = _vbullets[0];
				delete ptr;
				_vbullets.pop_back();
				ptr = nullptr;
				}
				}*/
		}


	}

	BOOL cursorCollider(int x, int y){

	}

	// collider를 각 object에서 처리하는게 편한가 아니면
	// world에서 처리하는게 편한가.
	// 사각형 충돌? 혹은 거리를 계산해서 충돌?
	// 그럼 원 대 사각형 충돌은 어떻게 처리해야되지?
	// 거리를 원거리 따로, 사각형 거리 따로?`
	// 사각형용 Collider
	BOOL RectCollider(){
		// todo: 고정값임 차후 유동값으로 바꿔야함
		if (_obstacle.size() > 0){
			int collidingRange = _player.getSize() + _obstacle[0]->getSize();
			int hRange = abs(_player.getPos().x - _obstacle[0]->getPos().x);
			int vRange = abs(_player.getPos().y - _obstacle[0]->getPos().y);
			return	(hRange <= collidingRange) &&
				(vRange <= collidingRange);
		}
		return false;
	}

	// 원 용 Collider (피타고라스의 함수를 이용한다)
	/*
		매 프레임마다 sqrt계산을 하기 때문에 부하가 생길수 있다.
		더 빠른 방법이 무엇인가?

		그럼 양변에 그냥 제곱해버리면 됨 ㅋ
		그럼 sqrt연산 자체가 필요가 없어진다.
		설마 이걸지 확신 못했는데 진짜였네 ㅡㅡ
		어떻게 보면 대단한게 아닐지 몰라도, 결국 생각의 차이 :D
		*/
	BOOL EllipseCollider(){
		if (_obstacle.size() > 0){
			int hRange = abs(_player.getPos().x - _obstacle[0]->getPos().x);
			int vRange = abs(_player.getPos().y - _obstacle[0]->getPos().y);

			int collidingRange = _player.getSize() + _obstacle[0]->getSize();
			int range = (hRange*hRange) + (vRange*vRange);

			return range <= collidingRange*collidingRange;
		}
		return false;
	}

	BOOL BulletColliderHelper(Bullet bullet){
		if (_obstacle.size() > 0){
			int hRange = abs(bullet.getPos().x - _obstacle[0]->getPos().x);
			int vRange = abs(bullet.getPos().y - _obstacle[0]->getPos().y);

			int collidingRange = bullet.getSize() + _obstacle[0]->getSize();
			int range = (hRange*hRange) + (vRange*vRange);

			return range <= collidingRange*collidingRange;
		}
		else return false;
	}

	/*
		비행기 같은 복잡한 도형이 있을 경우에는
		하나의 캡슐로 묶어 버리거나,
		각 오브젝트(팔다리)부분에 간단한 도형을 붙여서 충돌처리를 실시한다.
		2D에서 역시 내부에 충돌체를 여러개 가지고 실시 (hitbox)
		(가장 큰원에서 필터링하고, 작은 부분의 원에서 다시 체킹)
		*/
	/*
		직선과 만날경우에는 직선과 직선의 접전을 알아내거나
		직선의 방정식을 이용해서 처리하게 된다.
		정말 세밀하게 하고 싶다.. 그러면 직선쓰셈
		*/

	// getter
	vector<Obstacle*> getObstacle(){ return _obstacle; }
	Player getPlayer(){ return _player; }
	vector<Bullet*> getBullets(){ return _vbullets; }
	BOOL isGameOver(){ return _gameOver; }
	void setGameOver(BOOL in){ _gameOver = in; }

private:	
	RECT _map;
	Player _player;
	vector<Obstacle*> _obstacle;
	vector<Bullet*> _vbullets;
	BOOL _gameOver = false;
};