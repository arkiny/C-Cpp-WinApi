1. 상단에 적군이 왔다 갔다.
2. 하단 플레이어가 키보드 방향(좌우) 이동
3. 스페이스 누르면 플레이어로부터 총알 발사
4. 총알과 적군 충돌 처리
	- 총알은 충돌하면 사라짐
	- 적군은 3방 맞으면 사라짐

<과제>
- 적군이 랜덤하게 위에서 등장해서 아래로 아래로 이동(지나가며 맵밖으로 나가면 삭제)
- 적군과 플레이어가 충돌하면 플레이어 사망

- 총알이 화면 밖으로 나가면 다시쏠수 있다.
- 총알은 100발 (vector를 사용하면 과부하가 걸리나? 그렇다고 하면  array를 이용해본다)
- 충돌되면 총알이 사라진다
- 적군은 3발 맞으면 사라진다
- 적군이 죽으면 게임 종료

<보너스>
HP표시
게임 종료처리(메시지, 확인 누르면 어플리케이션 종료)

<특별 과제>
stl 컨테이너 써서 동적생성, 최적의 stl 선택
총알 무한 생성( 유저에게 보이기에), 메모리는 무한 생성하면 안댐.
(Heap Size도 제한이 있다. 유저에게만 무한생성되는것처럼 연출 / 
맵밖으로 나가면 삭제, 충돌시 삭제)

---------------------------------------------------

vector를 쓰고 재사용 

std::vector<cBullet*> m_vBulletList;
 std::queue<cBullet*> m_qBulletReUseList;

 재활용
 cbullet* pbullet = NULL;
 if (m_qBuleltReUseList.size() <= 0){
	pBullet = new cBullet;
	m_vBulletList.push_back(pBullet);
 } else {
	pBullet = (cBullet*)m_qBulletReUseList.front();
	m_qBulletReUseList.pop();
 }

 if (pBullet!=NULL)
 {
  pBullet->startMove();
 }

 생성한 놈(class)에서 해제를 해야함

for size of queue{
if (m_vBulletList[i] i= NULL)
	delete statc_cast<cBullet*>(m_vBulletList[i])

m_vBulletList.clear();

while(!m_quBulletReUseList.empty()){
	m_qbulletReUseList.pop();
}

1. 과제.... 
- 과제 그리드 위에 클릭하면, 회색처리.
- 탱크에서 총알이 나가면 그리드 위의 충돌 타일(회색)과 충돌 체크

- 삼각함수 (싸인, 코싸인, 탄젠트) 예습
- 각도를 가지고 회전을 시키기 (내일 배우기는 할것)

2. 내일 할것
- 마우스로 누르면 장애물이 생기고
- 탱크 구현