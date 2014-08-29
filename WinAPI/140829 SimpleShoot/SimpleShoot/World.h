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
				// TODO: �ε������� ó�� �߰�
				// ���� ��� ������Ʈ�� ���忡�� ���� ������?
			}
			_obstacle.update(delta);
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

	// collider�� �� object���� ó���ϴ°� ���Ѱ� �ƴϸ�
	// world���� ó���ϴ°� ���Ѱ�.
	// �簢�� �浹? Ȥ�� �Ÿ��� ����ؼ� �浹?
	// �׷� �� �� �簢�� �浹�� ��� ó���ؾߵ���?
	// �Ÿ��� ���Ÿ� ����, �簢�� �Ÿ� ����?`
	// �簢���� Collider
	BOOL RectCollider(){
		int collidingRange = _player.getSize() + _obstacle.getSize();
		int hRange = abs(_player.getPos().x - _obstacle.getPos().x);
		int vRange = abs(_player.getPos().y - _obstacle.getPos().y);
	
		return	(hRange <= collidingRange) &&
				(vRange <= collidingRange);		
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
	Obstacle getObstacle(){	return _obstacle;}	
	Player getPlayer(){ return _player; }
	vector<Bullet*> getBullets(){ return _vbullets; }

private:	
	RECT _map;
	Obstacle _obstacle;
	Player _player;
	vector<Bullet*> _vbullets;
};