#pragma once

#include <vector>
#include <queue>
#include "Object.h"

using std::vector;
using std::queue;

class World{
public:
	World();
	~World();

	

	void update(float delta);
	void render(HDC &hdc);
	
	// EnemyControl
	void addEnemy(float delta);
	void updateEnemy(float delta);
	void checkCollisionEnemy(float delta);

	// map control
	void updateMap(RECT rect);

	// bullet control
	void bulletBoundaryCheck();
	void updateBullets(float delta);
	void bulletHitCheck();
	void addBullet(float delta);

	// key control
	void onMouseMove(int x, int y);
	void onKeyDown(KeyInput in);
	void onKeyUp(KeyInput in);
	void movePlayer(float delta);

	BOOL checkBound(Object* obj);



	// Game Control
	void continueGame(){
		_gameOver = false;
		player->setHP(3);
	}
	BOOL retGameover(){	return _gameOver;}
	BOOL happyEnding(){	return _happyEnding;}
	void setGameover(BOOL in){ _gameOver = in; }
	void setPlayerHP(int in){ player->setHP(in); }

private:
	float _totaldelta = 0.0f;
	float _diffdelta = 0.0f;
	float _checker2 = 0.0f;
	float _checker = 0.0f;
	BOOL _shotchecker = false;
	BOOL _gameOver = false;
	BOOL _happyEnding = false;
	RECT _mapRect;
	int _score = 0;
	int _difficulty = 1;
	float _timeLapseBtwDif = 10.0f;

	KeyContrl _kc;
	Player* player;	

	//EBase* ebase;
	
	vector<Enemy*> _vEnemy;
	queue<Enemy*> _qEnemy;
	vector<Bullet*> _vbullets;
	queue<Bullet*> _qbullets;
};

