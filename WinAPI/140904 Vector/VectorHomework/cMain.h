#pragma once

#include <Windows.h>
#include "Object.h"

class cMainGame{
public:
	cMainGame(){ 
		m_fVLen = 0.0f; 
		_tank.setX(100.0f);
		_tank.setY(100.0f);
		_from.setX(_tank.getX());
		_from.setY(_tank.getX());
		_target.setX(_from.getX());
		_target.setY(_from.getY());
	}
	~cMainGame(){}

	void render(HDC hdc);
	void update(float delta);

	void moveTO(){
		Vector2D dir = _target - _from; // 방향
		dir.Normalize();	// 노말라이즈
		Vector2D v3 = dir* m_fVLen; // 시간동안 이동
		if (abs(_tank.getX() - _target.getX()) < 1.0f &&
			abs(_tank.getY() - _target.getY()) < 1.0f){
			// 만약 탱크가 목적지에 도착했다면 아무것도 안함
			// float이기 때문에 완전히 동일한 수가 나오기 힘드므로
			// 근사치에 도달하면 아무것도 안함
			// 격렬하게 아무것도 안함
		}
		else {
			_tank = _from + v3;
		}
	}

	void onclick(float x, float y){
		_from.setX(_tank.getX());
		_from.setY(_tank.getY());
		_target.setX(x);
		_target.setY(y);
		m_fVLen = 0;
	}

private:
	float m_fVLen;
	Vector2D _tank;
	Vector2D _from;
	Vector2D _target;
};

void cMainGame::render(HDC hdc){

	::Ellipse(hdc, 
		_from.getX() - 25, 
		_from.getY() - 25, 
		_from.getX() + 25, 
		_from.getY() + 25);
	::TextOut(hdc, _from.getX() - 15, _from.getY(), L"출발", 2);
	::Ellipse(hdc, 
		_target.getX() - 25, 
		_target.getY() - 25, 
		_target.getX() + 25, 
		_target.getY() + 25);
	::TextOut(hdc, _target.getX() - 15, _target.getY(), L"목적", 2);
	
	::MoveToEx(hdc, _from.getX(), _from.getY(), NULL);
	::LineTo(hdc, _tank.getX(), _tank.getY());	
	::Rectangle(hdc, _tank.getX() - 25, _tank.getY() - 25,
		_tank.getX() + 25, _tank.getY() + 25);
	::TextOut(hdc, _tank.getX() - 15, _tank.getY(), L"탱크", 2);
}

void cMainGame::update(float delta)
{
	m_fVLen += 100.0f*delta; // 시간동안 100pixel씩 이동
	::cMainGame::moveTO();
}