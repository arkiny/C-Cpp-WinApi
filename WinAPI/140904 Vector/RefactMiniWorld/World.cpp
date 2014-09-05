#include "World.h"

World::World(){
	_player = new Player();
	_vEnemy.clear();
}

World::World(int nRow, int nColumn){
	_player = new Player();
	_numRow = nRow + 1;
	_numColumn = nColumn + 1;

}

World::~World(){
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

	if (_player != nullptr){
		delete _player;
		_player = nullptr;
	}
}

void World::updateMap(RECT &clientRect){
	_tile.left = clientRect.left;
	_tile.top = clientRect.top;
	_tile.right = (clientRect.right - 200) / _numColumn;
	_tile.bottom = clientRect.bottom / _numRow;

	_tileWidth = _tile.right - _tile.left;
	_tileHeight = _tile.bottom - _tile.top;

	_tileMap.left = clientRect.left + (_tileWidth / 2);
	_tileMap.top = clientRect.top + (_tileHeight / 2);
	_tileMap.right = _tileMap.left + (_tileWidth * (_numColumn - 1));
	_tileMap.bottom = _tileMap.top + (_tileHeight * (_numRow - 1));
}

void World::update(float delta){

	// 플레이어 맵 충돌처리
	if (_player->checkBound(_tileMap)){
		POINT pp = _player->getPos();
		if (_player->getPos().x - _player->getSize() <= _tileMap.left){
			_player->setPos(pp.x + 1, pp.y);
		}
		else if (_player->getPos().x + _player->getSize() >= _tileMap.right){
			_player->setPos(pp.x - 1, pp.y);
		}

		else if (_player->getPos().y - _player->getSize() <= _tileMap.top){
			_player->setPos(pp.x, pp.y + 1);
		}
		else if (_player->getPos().y + _player->getSize() >= _tileMap.bottom){
			_player->setPos(pp.x, pp.y - 1);
		}
	}
	else {
		_player->update(delta);
	}

	// bullet add
	if (_player->getKC().space == true){
		Bullet* ptr = new Bullet(_player->getPos().x, _player->getPos().y, _player->getDegree());
		_qbullets.push(ptr);
		ptr = nullptr;
	}

	// queue와 stack을 이용한 데이터 주고받기를 통해 조건 업데이트 실시
	// 가장 원초적인 건데 왜 안쓰려고 하고 있었을까.....
	// updating and border check
	// 강사님이 가르쳐준 다른 방법으로는
	// 45개를 미리 queue에 넣어두고
	// vector를 이용해서 그 45개를 순환시키는 방법이 있다.
	Bullet* ptr = nullptr;
	Enemy* eptr = nullptr;
	while (!_qbullets.empty()){
		ptr = _qbullets.front();
		_qbullets.pop();
		ptr->update(delta);
		if (ptr->checkBound(_tileMap)){
			delete ptr;
		}
		else{
			_vbullets.push_back(ptr);
		}

		while (!_vEnemy.empty()){
			eptr = _vEnemy.back();
			_vEnemy.pop_back();
			if (eptr->isHittedbyBullet(*ptr)){
				_vbullets.pop_back();
				delete eptr;
				delete ptr;
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
	}
	while (!_vbullets.empty()){
		ptr = _vbullets.back();
		_vbullets.pop_back();
		_qbullets.push(ptr);
	}

	ptr = nullptr;
	eptr = nullptr;
}

void World::render(HDC hdc){
	TCHAR in[20];
	wsprintf(in, L"포탄수 : %d", _qbullets.size());
	::TextOut(hdc, 828, 200, in, wcslen(in));
	wsprintf(in, L"적타일 수 : %d", _vEnemy.size());
	::TextOut(hdc, 828, 220, in, wcslen(in));

	for (int i = 0; i < getNumRow() - 1; i++){
		for (int j = 0; j < getNumColumn() - 1; j++){
			::Rectangle(hdc,
				(getTile().left + (i*getTile().right) + (getTile().right / 2)),
				(getTile().top + (j*getTile().bottom) + (getTile().bottom / 2)),
				(getTile().right + (i*getTile().right) + (getTile().right / 2)),
				(getTile().bottom + (j*getTile().bottom) + (getTile().bottom / 2)));
		}
	}

	HBRUSH myBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
	if (!getObjects().empty()){
		for (int i = 0; i < getObjects().size(); i++){
			RECT obj = getTileRect(getObjects()[i]->getPos().x, getObjects()[i]->getPos().y);
			::Rectangle(hdc, obj.left, obj.top, obj.right, obj.bottom);
		}
	}

	SelectObject(hdc, oldBrush);
	DeleteObject(myBrush);

	_player->render(hdc);

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

void World::mbLbuttonDown(int x, int y){
	if (!inList(getTileCoordinate(x, y).x,
		getTileCoordinate(x, y).y)){
		addObject(x, y);
	}
}

void World::mbRbuttonDowns(int x, int y){
	if (inList(getTileCoordinate(x, y).x,
		getTileCoordinate(x, y).y)){
		deleteObject(x, y);
	}
}

void World::kbDown(WPARAM& wParam){
	switch (wParam){
	case VK_RIGHT:
		_player->setDir(RIGHT);
		break;
	case VK_LEFT:
		_player->setDir(LEFT);
		break;
	case VK_UP:
		_player->setDir(UP);
		break;
	case VK_DOWN:
		_player->setDir(DOWN);
		break;
	case VK_SPACE:
		//맵 위에 총알 생성
		_player->setDir(SPACE);
		//Bullet* ptr = new Bullet(_player->getPos().x, _player->getPos().y, _player->getDegree());
		//_qbullets.push(ptr);			
		//ptr = nullptr;
		break;
	}
}

void World::kbUp(WPARAM& wParam){
	switch (wParam){
	case VK_RIGHT:
		_player->unsetDir(RIGHT);
		break;
	case VK_LEFT:
		_player->unsetDir(LEFT);
		break;
	case VK_UP:
		_player->unsetDir(UP);
		break;
	case VK_DOWN:
		_player->unsetDir(DOWN);
		break;
	case VK_SPACE:
		_player->unsetDir(SPACE);
		break;
	}
}