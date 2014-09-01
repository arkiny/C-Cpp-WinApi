/*
	@author		Heedong Arkiny Lee
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	��ǥ���� ������ �ڵ��...
	���߿� �ʿ��ϸ� refactoring��..
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
			//�� ���� �Ѿ� ����
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
		// �ϴ� ���������� ����
		// ���� ������� if... ��ġ�� ������..
		if (_obstacle.size() > 0){
			// �÷��̾�� �ε����� �ʾ��� ���
			if (!EllipseCollider()){
				// ü�� ������ ��� ������Ʈ
				if (_obstacle[0]->getHP() > 0){
					if (_obstacle[0]->checkBound(_map)){
						// ��ֹ��� �Ʒ� �ʿ� �ε������� ó��
						Obstacle* ptr = _obstacle[0];
						delete ptr;
						ptr = nullptr;
						_obstacle.pop_back();
						_obstacle.shrink_to_fit();
					}
					else {
						if (_obstacle.size() > 0){
							// �Ⱥε�������� ������Ʈ
							_obstacle[0]->update(delta);
						}
					}
				}
				// ü�� �������� ����
				else {
					_obstacle.pop_back();
				}
			}
			// �÷��̾�� �ε����� ���
			else {
				// ���ӿ��� Ʈ����
				_gameOver = true;
				_obstacle.pop_back();
			}
		}
		else{
			Obstacle* ptr = new Obstacle({ rand() % _map.right + 50, 100 }, 50);
			_obstacle.push_back(ptr);
		}

		if (_player.checkBound(_map)){
			// TODO: �ٸ������δ� �����ϼ� �ְ� ���� �߰�
		}
		else {
			_player.update(delta);
		}

		// ������ �������� ��ſ� ������Ʈ ����

		// �ϴ� �ϳ���
		// ������ ���ϸ� ����ȭ ��������....
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

	// collider�� �� object���� ó���ϴ°� ���Ѱ� �ƴϸ�
	// world���� ó���ϴ°� ���Ѱ�.
	// �簢�� �浹? Ȥ�� �Ÿ��� ����ؼ� �浹?
	// �׷� �� �� �簢�� �浹�� ��� ó���ؾߵ���?
	// �Ÿ��� ���Ÿ� ����, �簢�� �Ÿ� ����?`
	// �簢���� Collider
	BOOL RectCollider(){
		// todo: �������� ���� ���������� �ٲ����
		if (_obstacle.size() > 0){
			int collidingRange = _player.getSize() + _obstacle[0]->getSize();
			int hRange = abs(_player.getPos().x - _obstacle[0]->getPos().x);
			int vRange = abs(_player.getPos().y - _obstacle[0]->getPos().y);
			return	(hRange <= collidingRange) &&
				(vRange <= collidingRange);
		}
		return false;
	}

	// �� �� Collider (��Ÿ����� �Լ��� �̿��Ѵ�)
	/*
		�� �����Ӹ��� sqrt����� �ϱ� ������ ���ϰ� ����� �ִ�.
		�� ���� ����� �����ΰ�?

		�׷� �纯�� �׳� �����ع����� �� ��
		�׷� sqrt���� ��ü�� �ʿ䰡 ��������.
		���� �̰��� Ȯ�� ���ߴµ� ��¥���� �Ѥ�
		��� ���� ����Ѱ� �ƴ��� ����, �ᱹ ������ ���� :D
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
		����� ���� ������ ������ ���� ��쿡��
		�ϳ��� ĸ���� ���� �����ų�,
		�� ������Ʈ(�ȴٸ�)�κп� ������ ������ �ٿ��� �浹ó���� �ǽ��Ѵ�.
		2D���� ���� ���ο� �浹ü�� ������ ������ �ǽ� (hitbox)
		(���� ū������ ���͸��ϰ�, ���� �κ��� ������ �ٽ� üŷ)
		*/
	/*
		������ ������쿡�� ������ ������ ������ �˾Ƴ��ų�
		������ �������� �̿��ؼ� ó���ϰ� �ȴ�.
		���� �����ϰ� �ϰ� �ʹ�.. �׷��� ��������
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