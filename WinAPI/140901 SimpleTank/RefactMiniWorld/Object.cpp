#include "Object.h"

BOOL Enemy::isHittedbyBullet(Bullet &bullet){
	int vcollidingRange = bullet.getSize() + (_reg.bottom - _reg.left);
	int hcollidingRange = bullet.getSize() + (_reg.right - _reg.left);
	int hRange = abs(_pos.x - bullet.getPos().x);
	int vRange = abs(_pos.y - bullet.getPos().y);
	return	(hRange <= vcollidingRange) &&
		(vRange <= hcollidingRange);
}