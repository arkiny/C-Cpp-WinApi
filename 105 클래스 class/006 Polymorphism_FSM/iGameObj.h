/*
	IGameObj 게임 오브젝트
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

	// 상태를 변경
	void ChangeState(iState* pnew);
	void update();


	// helper;
	void SetHealth(int h) { 
		m_health = h; 
	}

	void attack(Player* in);

	// const는 수치변환이 일어나지 않는다는 보장, get으로 가져올때 보증한다.
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
	// 굳이 왜 포인터인가? state를 switching 해주기 위해서	
	iState *pstate = nullptr;		// 현재 상태, AI State
									// state layer를 여러개를 주면된다.
									// 음흠? 그럼 전투에 관련된 state레이어를 만들수 있겠군!
									// 다음번에는 그렇게 맹궈보자

	int m_health = 20;				// 체력지수	
	int m_position = 10;			// 오크의 위치(직선 기준)
	int m_speed = 2;				// 도망갈때 이동속도
	int m_attack = 2;				// 공격력- 일단은 고정
	int m_range = 3;				// 사정거리
	int m_dist_enemy = 10;			// 인식한 적과의 거리
	int m_enemy_health = 50;		// 인식한 적 체력
	bool m_aggro = false;			// 적을 인식했는가
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
	void move(){ // 평면이동
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
	int m_position = 0;			// 현재위치 (직선 기준)
	int m_health = 50;			// 초기 체력
	int m_speed = 1;			// 이동속도	
	int m_attack = 5;			// 초기 공격력
	int m_range = 3;			// 사정거리
};


#endif