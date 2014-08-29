/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong
*/

#pragma once;

#include <cmath>
#include <vector>
#include "Object.h"

using std::vector;

class World{
public:
	World(){
		_obstacle = Obstacle({ 200, 200 }, 50);
		_player = Player({ 300, 500 }, 25);
		_map = {};
	}

	World(Obstacle &obs){
		_obstacle = obs;
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
		if (!EllipseCollider()){
			if (_obstacle.checkBound(_map)){
				switch (_obstacle.getDir())
				{
				case LEFT:
					_obstacle.setDir(RIGHT);
					break;
				case RIGHT:
					_obstacle.setDir(LEFT);
					break;
				default:
					break;
				}
			}
			else {
				// TODO: 부딪혔을때 처리 추가
				// 예를 들면 오브젝트를 월드에서 삭제 같은거?
			}
			_obstacle.update(delta);
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
		if (!_vbullets.empty()){
			_vbullets[0]->update(delta);
			if (BulletColliderHelper(*_vbullets[0])){
				Bullet* ptr = _vbullets[0];
				delete ptr;
				_vbullets.pop_back();
				ptr = nullptr;
				_obstacle.getHitted();
			}

			if (!_vbullets.empty()){
				if (_vbullets[0]->checkBound(_map)){
					Bullet* ptr = _vbullets[0];
					delete ptr;
					_vbullets.pop_back();
					ptr = nullptr;
				}
			}
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
		int collidingRange = _player.getSize() + _obstacle.getSize();
		int hRange = abs(_player.getPos().x - _obstacle.getPos().x);
		int vRange = abs(_player.getPos().y - _obstacle.getPos().y);
	
		return	(hRange <= collidingRange) &&
				(vRange <= collidingRange);		
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
		int hRange = abs(_player.getPos().x - _obstacle.getPos().x);
		int vRange = abs(_player.getPos().y - _obstacle.getPos().y);

		int collidingRange = _player.getSize() + _obstacle.getSize();
		int range = (hRange*hRange) + (vRange*vRange);

		return range <= collidingRange*collidingRange;
	}

	BOOL BulletColliderHelper(Bullet bullet){
		int hRange = abs(bullet.getPos().x - _obstacle.getPos().x);
		int vRange = abs(bullet.getPos().y - _obstacle.getPos().y);

		int collidingRange = bullet.getSize() + _obstacle.getSize();
		int range = (hRange*hRange) + (vRange*vRange);

		return range <= collidingRange*collidingRange;
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
	Obstacle getObstacle(){	return _obstacle;}	
	Player getPlayer(){ return _player; }
	vector<Bullet*> getBullets(){ return _vbullets; }

private:	
	RECT _map;
	Obstacle _obstacle;
	Player _player;
	vector<Bullet*> _vbullets;
};