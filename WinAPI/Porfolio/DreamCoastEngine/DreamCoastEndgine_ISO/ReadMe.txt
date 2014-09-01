
08302014 // ver 0.02

1. 고정값을 통한 IsoMectric pick 완료
2. 타일 안 계산은 직선의 방정식을 통한 계산으로 확인.
(5개로 나눠서 하는 방법은 시도했다가 실패)
3. 일단 pick된 좌표는 msgbox로 출력


TODO :
1. class refactoring -> time based로 수정하면서 refactoring
2. 화면에 클릭한 좌표를 화면에 textout으로 출력하며,
 해당칸을 네모로 출력하기..

//////////////////////////////
08282014 // DreamCoast_ISO Engine 0.01 

최초 클래스 디자인
World
World를 구성하는 클래스  
(World는 철저히 게임 플레잉 화면만을 관리한다)

World has below classes as variable

map -> 맵을 구성하는 클래스
		- x*y의 isometric 맵정보를 2차열 배열로 가지고 있고, 그 정보에 따라서 상호작용을 실시한다(차후 추가)		
		
KeyControl -> 
유저의 키 컨트롤 관련 정보를 관리하는 클래스
마우스 위치 정보, 키보드 입력 정보등 입력기기로서의 입력을 관리한다.

UI -> 게임 UI를 구성하는 클래스 // 자식 클래스로 스탯창, 인벤창을
		- 좌상단: 체력, 스탯창, 메뉴 클릭창 등등

Object -> 화면상의 Object들을 관리하는 클래스
		- 플레이의 경우 좌표를 가지고 있어야하며,
			힛박스를 이용한 타격이 아닌, isometric기반의
			스킬 사용, 타격을 계산한다. (차후 추가)

		- 플레이어 및 몬스터 캐릭터를 관리하는 클래스	 
		- 몬스터 - AI FSM 추가			

WorldRenderer-> WorldRenderer Refers World Class 
		- LineTo를 이용, IsoMetric으로 Render하되, 각 마름모 중앙에 좌표를 Text로 렌더한다.
		
과 정

0. 창 생성시, 창이 리사이징 되지 않도록 고정한 후 실시한다. 

1. Map 정보를 기반으로 맵을 Isometric으로 렌더한다. (WorldRenderer) - 카메라 뷰를 이용한 이동관리는 차후 실시

1-1 수업과제로서 해당 맵 윗부분에 User Interface를 만들어서 렌더링한다. 따로 클래스를 만들고 관리할수 있도록 한다.
레이어는 가장 아래부터 맵, 오브젝트, UI순으로 렌더한다.

2. User가 해당 좌표를 픽했을 시에, 해당 좌표위에 Object를 생성한다. 
그냥 Render만 해도 되겠지만 차후 Object관리를 위한 Picker로서의 기능(확장성)을 생각하여 실시한다.
- Picker의 경우에 각 타일이 각자의 히트박스를 가지게 만들어야하나?

-일단 기본적인 원리는,
* Click시 좌표값을 가지고 그 좌표가 마름모 안에 있을 경우에, 해당 타일의 좌표를 얻어서 오브젝트를 생성하거나,
 렌더를 해준다. 인데,
  좌표가 마름모 안에 있는 것을 어떻게 

3. Player Object를 맵위에 추가한 뒤, 이동할수 있게 한다. (화살표키)
 - 이동 시 처리를 어떻게 할지 고민해보자(위로 움직이면 IsoMetric 기반으로는 오른쪽 위로 움직이는 애니메이션이 된다.)
 - 내가 만들고자 하는 게임은 키보드 기반의 액션형 게임이므로 IsoMetric이 과연 맡는 방법인지 고민해본다.
 - IsoMetric말고 변형된 Top View로 렌더할수 있는 방법을 고민해보자.
 - 타격 범위는 Hitbox가 아닌 타일 기반으로 타격 범위나 스킬 범위를 정한다. (과거 라그나로크 온라인이 그랬던 것처럼)
 - 이동 시 엔진은 플레이어가 위치한 타일 위치를 화면에 출력한다.
 
 4. Monster Object를 맵위에 추가한 뒤 공방 구현 (한참 뒤의 일)


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