// ������Ʈ�� �������� ��ǥ�� ������.
// ���� Ÿ������ �� �������̽� ��������
// �÷��̾�� ���͸� �ٲܼ� �ִ�.

#pragma once

#include <Windows.h>

class Object{
public:
	Object(){
		_pos = {};
	}
	Object(int x, int y){
		_pos = { x, y };
	}

	POINT getObject(){ return _pos; }
	void setObject(int x, int y){
		_pos = { x, y };		
	};

private:
	POINT _pos;
};