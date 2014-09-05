#include "Object.h"

Enemy::Enemy(){
	_hp = 1;
}

Enemy::Enemy(RECT& in){
	_reg = in;
}

void Enemy::update(float delta){};
void Enemy::render(HDC &hdc){}

BOOL Enemy::isHittedbyBullet(Bullet &bullet){
	int hcollidingRange = bullet.getSize() + (_reg.right - _reg.left) / 2;
	int vcollidingRange = bullet.getSize() + (_reg.bottom - _reg.top) / 2;
	int hRange = abs(bullet.getPos().x - (_reg.left + (_reg.right - _reg.left) / 2));
	int vRange = abs(bullet.getPos().y - (_reg.top + (_reg.bottom - _reg.top) / 2));
	return	(hRange <= hcollidingRange) && (vRange <= vcollidingRange);
}

void Enemy::getHitted(){
	_hp--;
}

BOOL Enemy::isDead(){
	return _hp <= 0;
}