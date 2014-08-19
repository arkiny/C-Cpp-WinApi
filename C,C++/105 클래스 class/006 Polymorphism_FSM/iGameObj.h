/*
	IGameObj ���� ������Ʈ
*/

#ifndef _ORC_H_
#define _ORC_H_

#include "State.h"

class iGameObj{
public:
	virtual ~iGameObj(){};

//public:
//	virtual void update() = 0;
//
//	virtual void SetHealth(int) {};
//	virtual int GetHealth() const = 0;
//	virtual void attack(iGameObj* in) {};
//	virtual int getPosition() = 0;

private:
	int m_speed;	
	int m_attack;
	int m_position;
	int m_health;
};

class Player;

class Orc : public iGameObj
{
public:
	Orc();
	~Orc();

public: // interface

	// ���¸� ����
	void ChangeState(iState* pnew);
	void update();


	// helper;
	void SetHealth(int h) { 
		m_health = h; 
	}

	void attack(Player* in);

	// const�� ��ġ��ȯ�� �Ͼ�� �ʴ´ٴ� ����, get���� �����ö� �����Ѵ�.
	int GetHealth() const { 
		return m_health;
	}

	int getPosition() const {
		return m_position;
	}	

	int move(){
		m_position = m_position + m_speed;
	}	

	void setAggro(bool in){
		m_aggro = in;
	}

	bool getAggro(){
		return m_aggro;
	}

	void setDist(int in){
		m_dist_enemy = in;
	}

	void setRange(Player* in);

	int getDist() {
		return m_dist_enemy;
	}

	int getRange(){
		return m_range;
	}

	void setEnemyHealth(int in){
		m_enemy_health = in;
	}

	int getEnemyHealth(){
		return m_enemy_health;
	}

	int getSpeed(){
		return m_speed;
	}

	void setEnemyRange(int in){
		m_dist_enemy = in;
	}

private:
	// ���� �� �������ΰ�? state�� switching ���ֱ� ���ؼ�	
	iState *pstate = nullptr;		// ���� ����, AI State
									// state layer�� �������� �ָ�ȴ�.
									// ����? �׷� ������ ���õ� state���̾ ����� �ְڱ�!
									// ���������� �׷��� �ͱź���

	int m_health = 20;				// ü������	
	int m_position = 10;			// ��ũ�� ��ġ(���� ����)
	int m_speed = 2;				// �������� �̵��ӵ�
	int m_attack = 2;				// ���ݷ�- �ϴ��� ����
	int m_range = 3;				// �����Ÿ�
	int m_dist_enemy = 10;			// �ν��� ������ �Ÿ�
	int m_enemy_health = 50;		// �ν��� �� ü��
	bool m_aggro = false;			// ���� �ν��ߴ°�
};

/*
	Player (User will control this object)
*/
class Player : public iGameObj
{
public:
	Player();
	~Player();

public: // interface
	void update(Orc* in);
	void attack(Orc* in);

	// helper
	void move(){ // ����̵�
		m_position = m_position + m_speed;
	}

	int GetHealth(){
		return m_health;
	}	

	void SetHealth(int in){
		m_health = in;
	}

	int getPosition(){
		return m_position;
	}

private:
	int m_position = 0;			// ������ġ (���� ����)
	int m_health = 50;			// �ʱ� ü��
	int m_speed = 1;			// �̵��ӵ�	
	int m_attack = 5;			// �ʱ� ���ݷ�
	int m_range = 3;			// �����Ÿ�
};


#endif