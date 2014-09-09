#include <stdio.h>
#include <time.h>
#include "World.h"

World::World(){
	srand(time(NULL));
	player = new Player(514, 500, &_kc);
}

World::~World(){
	if (player != NULL){
		delete player;
	}
	player = nullptr;

	Enemy* ptr;
	while (!_vEnemy.empty()){
		ptr = _vEnemy.back();
		if (ptr != nullptr){
			delete ptr;
		}
		_vEnemy.pop_back();
		_vEnemy.shrink_to_fit();
	}

	Bullet* bptr;
	while (!_qbullets.empty()){
		bptr = _qbullets.front();
		if (bptr != nullptr){
			delete bptr;
		}
		_qbullets.pop();
	}
	bptr = nullptr;
}


void World::updateMap(RECT rect){
	_mapRect.top = rect.top + 50;
	_mapRect.left = rect.left + 50;
	_mapRect.right = rect.right - 50;
	_mapRect.bottom = rect.bottom - 50;
}

void World::onMouseMove(int x, int y){
	_kc.mouseX = x;
	_kc.mouseY = y;
}

void World::onKeyDown(KeyInput in){
	switch (in)
	{
	case NOINPUT:
		_kc._up = false;
		_kc._down = false;
		_kc._left = false;
		_kc._right = false;
		_kc._space = false;
		_kc._lbutton = false;
		_kc.mouseX = 0;
		_kc.mouseY = 0;
		break;
	case UP:
		if (_kc._down = true) _kc._down = false;
		_kc._up = true;
		break;
	case DOWN:
		if (_kc._up = true) _kc._up = false;
		_kc._down = true;
		break;
	case LEFT:
		if (_kc._right = true) _kc._right = false;
		_kc._left = true;
		break;
	case RIGHT:
		if (_kc._left = true) _kc._left = false;
		_kc._right = true;
		break;
	case SPACE:
		_kc._space = true;
		break;
	case LBUTTON:
		/*_kc._lbutton = true;*/
		_kc._space = true;
		break;
	default:
		break;
	}
}

void World::onKeyUp(KeyInput in){
	switch (in)
	{
	case NOINPUT:
		_kc._up = false;
		_kc._down = false;
		_kc._left = false;
		_kc._right = false;
		_kc._space = false;
		_kc._lbutton = false;
		_kc.mouseX = 0;
		_kc.mouseY = 0;
		break;
	case UP:
		_kc._up = false;
		break;
	case DOWN:
		_kc._down = false;
		break;
	case LEFT:
		_kc._left = false;
		break;
	case RIGHT:
		_kc._right = false;
		break;
	case SPACE:
		_kc._space = false;
		break;
	case LBUTTON:
		/*_kc._lbutton = false; */
		_kc._space = false;
		break;
	default:
		break;
	}
}

BOOL World::checkBound(Object* obj){
	BOOL ret = (obj->getPos().x - obj->getSize() <= _mapRect.left ||
		obj->getPos().x + obj->getSize() >= _mapRect.right ||
		obj->getPos().y - obj->getSize() <= _mapRect.top ||
		obj->getPos().y + obj->getSize() >= _mapRect.bottom);
	return ret;
}

void World::addBullet(float delta){
	// 총알 간격 조절은 차후 수정
	Bullet* ptr = nullptr;
	if (_checker2 <= (150.0f / 1000.0f) && !_shotchecker){
		if ((_kc._lbutton == true || _kc._space == true)){
			ptr = new Bullet(player->getPos(), player->getDir());
			_qbullets.push(ptr);
		}
		_checker2 += delta;
		_shotchecker = true;
	}
	else if (_checker > (150.0f / 10000.f) && _shotchecker){
		_checker2 = 0;
		_shotchecker = false;
	}
	else {
		_checker2 += delta;
	}
	ptr = nullptr;
}

void World::bulletHitCheck(){
	Enemy* eptr = nullptr;
	Bullet* ptr = nullptr;
	bool hitted = false;
	// 피탄 처리
	while (!_qbullets.empty()){
		ptr = _qbullets.front();
		_qbullets.pop();

		while (!_vEnemy.empty()){
			eptr = _vEnemy.back();
			_vEnemy.pop_back();

			if (eptr->isHittedbyBullet(*ptr)){
				eptr->getHitted();
				hitted = true;
				if (eptr->getHP() <= 0){
					delete eptr;
					_score++;
					if (_score >= 100) { _happyEnding = true; }
				}
				else {
					_qEnemy.push(eptr);
				}
			}
			else {
				_qEnemy.push(eptr);
			}
		}

		while (!_qEnemy.empty()){
			eptr = _qEnemy.front();
			_qEnemy.pop();
			_vEnemy.push_back(eptr);
		}

		// 중복 충돌 처리
		if (hitted){
			delete ptr;
		}
		else {
			_vbullets.push_back(ptr);
		}
		hitted = false;
	}

	while (!_vbullets.empty()){
		ptr = _vbullets.back();
		_vbullets.pop_back();
		_qbullets.push(ptr);
	}

	ptr = nullptr;
	eptr = nullptr;
}

void World::updateBullets(float delta){
	Bullet* ptr = nullptr;
	// 업데이트
	while (!_qbullets.empty()){
		ptr = _qbullets.front();
		_qbullets.pop();
		ptr->update(delta);
		_vbullets.push_back(ptr);
	}
	while (!_vbullets.empty()){
		ptr = _vbullets.back();
		_vbullets.pop_back();
		_qbullets.push(ptr);
	}
	ptr = nullptr;

}

void World::bulletBoundaryCheck(){
	Bullet* ptr = nullptr;
	// 벽처리
	while (!_qbullets.empty()){
		ptr = _qbullets.front();
		_qbullets.pop();

		if (checkBound(ptr)){
			delete ptr;
		}
		else{
			_vbullets.push_back(ptr);
		}

	}
	while (!_vbullets.empty()){
		ptr = _vbullets.back();
		_vbullets.pop_back();
		_qbullets.push(ptr);
	}
	ptr = nullptr;

}

void World::addEnemy(float delta){
	Enemy* eptr = nullptr;
	_diffdelta += delta;

	if (_diffdelta >= _timeLapseBtwDif){
		_difficulty++;
		_diffdelta = 0;
	}

	// 좀비가 10명 이하일 경우, 일정 시간 간격마다
	if (_vEnemy.size() <= (10 * _difficulty) && _checker > (1.0f *(1.0f - (_difficulty / 10.0f)))){
		int point = rand() % 4;

		int height = _mapRect.bottom - _mapRect.top;
		int width = _mapRect.right - _mapRect.left;

		// 4방위중 랜덤하게 적을 넣는다.		
		switch (point)
		{
		case 0:
			eptr = new Enemy((rand() % width) + _mapRect.left, _mapRect.top, player->getPos());
			break;
		case 1:
			eptr = new Enemy((rand() % width) + _mapRect.left, _mapRect.bottom, player->getPos());
			break;
		case 2:
			eptr = new Enemy(_mapRect.left, (rand() % height) + _mapRect.top, player->getPos());
			break;
		case 3:
			eptr = new Enemy(_mapRect.right, (rand() % height) + _mapRect.top, player->getPos());
			break;
		default:
			eptr = new Enemy(100, 100, player->getPos());
			break;
		}
		_vEnemy.push_back(eptr);
		eptr = nullptr;
		_checker = 0.0f;
	}
	else {
		_checker += delta;
	}
}

void World::render(HDC &hdc){
	TCHAR in[128];
	wsprintf(in, L"포탄수 : %d", _qbullets.size());
	::TextOut(hdc, 0, 0, in, wcslen(in));

	wsprintf(in, L"죽인 적 수 : %d", _score);
	::TextOut(hdc, 100, 0, in, wcslen(in));

	swprintf(in, L"지난 시간 : %.2f", _totaldelta);
	::TextOut(hdc, 250, 0, in, wcslen(in));

	swprintf(in, L"현재 난이도 : %d", _difficulty);
	::TextOut(hdc, 450, 0, in, wcslen(in));

	wsprintf(in, L"이동 : 화살표 혹은 qwer \t 조준 : 마우스커서 \t 발사 : 마우스왼쪽");
	::TextOut(hdc, 0, _mapRect.bottom + 20, in, wcslen(in));

	::Rectangle(hdc,
		_mapRect.left,
		_mapRect.top,
		_mapRect.right,
		_mapRect.bottom);

	//ebase->render(hdc);

	player->render(hdc);

	Enemy* eptr = nullptr;
	while (!_vEnemy.empty()){
		eptr = _vEnemy.back();
		_vEnemy.pop_back();
		eptr->render(hdc);
		_qEnemy.push(eptr);
	}
	while (!_qEnemy.empty()){
		eptr = _qEnemy.front();
		_qEnemy.pop();
		_vEnemy.push_back(eptr);
	}

	Bullet* ptr = nullptr;
	while (!_qbullets.empty()){
		ptr = _qbullets.front();
		_qbullets.pop();
		ptr->render(hdc);
		_vbullets.push_back(ptr);
	}
	while (!_vbullets.empty()){
		ptr = _vbullets.back();
		_vbullets.pop_back();
		_qbullets.push(ptr);
	}
}

void World::update(float delta){
	// 맵과 충돌처리
	if (checkBound(player)){
		VECTOR2D pp = player->getPos();
		if (player->getPos().x - player->getSize() <= _mapRect.left){
			player->setVector(pp.x + 1, pp.y);
		}
		else if (player->getPos().x + player->getSize() >= _mapRect.right){
			player->setVector(pp.x - 1, pp.y);
		}
		else if (player->getPos().y - player->getSize() <= _mapRect.top){
			player->setVector(pp.x, pp.y + 1);
		}
		else if (player->getPos().y + player->getSize() >= _mapRect.bottom){
			player->setVector(pp.x, pp.y - 1);
		}
	}
	else {
		player->update(delta);
	}
	//player->update(delta);		

	////////// add procedure
	addEnemy(delta);
	addBullet(delta);
	////////////////////////////

	// check and update procedure
	// Enemy
	updateEnemy(delta);
	checkCollisionEnemy(delta);	

	// Bullets
	updateBullets(delta);
	bulletBoundaryCheck();
	bulletHitCheck();

	_totaldelta += delta;
}

void World::updateEnemy(float delta){
	Enemy* eptr = nullptr;
	// 적 이동 처리
	while (!_vEnemy.empty()){
		eptr = _vEnemy.back();
		eptr->updateTarget(player->getPos());
		eptr->update(delta);
		_vEnemy.pop_back();
		_qEnemy.push(eptr);
	}
	while (!_qEnemy.empty()){
		eptr = _qEnemy.front();
		_vEnemy.push_back(eptr);
		_qEnemy.pop();
	}
	eptr = nullptr;
}

void World::checkCollisionEnemy(float delta){
	Enemy* eptr = nullptr;
	// 적 충돌
	while (!_vEnemy.empty()){
		eptr = _vEnemy.back();
		_vEnemy.pop_back();
		if (player->isHittedbyEnemy(*eptr)){
			player->getHitted();
			// 경직 처리 넣고 싶지만 귀찮다..
			if (player->getHP() <= 0){
				_gameOver = true;
			}
			delete eptr;
		}
		else {
			_qEnemy.push(eptr);
		}
	}
	while (!_qEnemy.empty()){
		eptr = _qEnemy.front();
		_vEnemy.push_back(eptr);
		_qEnemy.pop();
	}
	eptr = nullptr;
}