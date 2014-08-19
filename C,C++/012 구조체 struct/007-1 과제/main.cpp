/*
	@author		Heedong Arkiny Lee
	@date		07182014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	과제 ]] Enemy를 맵에서 이동하기
	ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ
	ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ
	ㅁㅁㅁ유ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ
	ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ
	ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ
	ㅁㅁㅁㅁㅁㅁㅁㅁㅁ타ㅁㅁㅁㅁ
	ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ
	ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ
	ㅁㅁㅁㅁㅁㅁㅁㅁ목ㅁㅁㅁㅁㅁ
	ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ
	ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ
	ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ

	Enemy 구조체의 start 위치에서 Enemy 시작
	Dest 위치를 추가로 넣고
	일정시간 마다 목적지로 이동하기
	
	이거 Union Find 써서 메이즈 만들고 목적위치 찾아가기 해도 될거 같은데

	_sleep(1000) 1000 = 약 1초
*/

//최초 디자인 ->
//struct point
// point는 갈수 있는 다른 포인트들을 포인터로 가지고 있음
// 
//struct cctv
//struct thief
//struct map
//function
//void mapload (random terrain loading) 
// -> int[][]로 0은 통과 불과, 1은 통과 가능
// -> load 후에 고정된  Starting Point에서 
//				고정된  Target Point까지 이동가능한지 확인하고 불가능할시에
//				재로딩
//void mapupdate(cctv, thief)
// -> map에 cctv를 thief(starting point)를 뿌려서, 
// -> 새 위치가 확정될때마다
// -> reload 되게끔 함
//
//bool cango (union find) 
//void update - in the forloop
//bool shortwayfind (bfs b/c undirected graph)
// -
//bool move(point from, point to)


#include <stdio.h>	// printf()
#include <stdlib.h>	// rand(), srand()
#include <time.h>	// time()
#include <math.h>	// sqrt(), pow()

// map크기 지정, 입력 받을수도 있으나 일단 복잡해지니 상수로 지정
const int MAP_VERTICAL = 18;
const int MAP_HORIZONTAL = 18;

// 타일 타입 지정
enum type{movable, not_movable, thief, tower, start, dest, border};
// 길찾기 AI를 위한 방향 지정
enum direc{right, up, left, down};

// AI지정
enum pathAI{noAI, turnLeft};

// 지도 object 설정
typedef struct game_map{
	// 맵은 point 곧 오브젝트와는 별개의 구조이므로
	// 굳이 point를 쓸 필요는 없을듯 하다
	// (i % MAP_HORIZONTAL)[x좌표] + ( i/MAP_HORIZONTAL )[y좌표]
	// 1차원 구조로 만든 이유는 차후
	// 알고리즘 적용을 조금이나마 편하게 하기위해서...ㅣ
	int map_point[MAP_VERTICAL * MAP_HORIZONTAL];

	// Random Map 생성
	// random함수에 의해 이동 가능한 타일과 이동 불가능한 타일을 생성한다.
	void initmap_ob(){
		for (int i = 0; i < (MAP_VERTICAL * MAP_HORIZONTAL); i++){
			// boardering
			if (i % (MAP_HORIZONTAL) == 0 || i % MAP_HORIZONTAL == MAP_HORIZONTAL - 1
				|| i < MAP_HORIZONTAL || i > (MAP_HORIZONTAL * (MAP_VERTICAL-1))){
				map_point[i] = 1;
			}
			else if (rand() % 100 > 1){
				map_point[i] = 0; 
			}
			else{
				map_point[i] = 1;
			}
		}
	}

	// 그냥 빈맵 생성
	void initmap_empty(){
		for (int i = 0; i < (MAP_VERTICAL * MAP_HORIZONTAL); i++){
				map_point[i] = 0;			
		}
	}

	// 해당 위체 object 설치
	// @param int x x좌표
	// @param int y y좌표
	// @param int type object 타입
	void setObject(int x, int y, int type){
		map_point[(x * MAP_HORIZONTAL) + y] = type;
	} 

	// 입력 받은 위치가 움직일수 있는 곳인지 확인
	// @param int x x좌표
	// @param int y y좌표
	bool isMovable(int x, int y){
		return map_point[(x * MAP_HORIZONTAL) + y] == movable
			|| map_point[(x * MAP_HORIZONTAL) + y] == dest
			|| map_point[(x * MAP_HORIZONTAL) + y] == start;
	}

	// 이동 불가능한 자리에는 ■을, 이동 가능한 자리에는 ┼
	// 차후에 render맵으로 빼기전에 쓸 소스
	// 일단은 테스트........는 잠시 난관에 부딪혀서 소스만 남기는 걸로...
	// A*를 class와 Data Structure를 안배운 c에서 구현하기에는 너무나 갈길이 멀다....
	void printMap(){
		for (int i = 0; i < (MAP_VERTICAL * MAP_HORIZONTAL); i++){
			if (i % MAP_HORIZONTAL == 0){
				printf("\n");
			}
			if (map_point[i] == movable){
				printf("%s", "┼");
			}
			else if (map_point[i] == not_movable){
				printf("%s", "■");
			}
			else if (map_point[i] == thief){
				printf("%s", "◈");
			}
			else if (map_point[i] == tower){
				printf("%s", "◎");
			}
			else if (map_point[i] == start){
				printf("%s", "출");
			}
			else if (map_point[i] == dest){
				printf("%s", "목");
			}
			else{
			}
		}
		printf("\n");
	}
}GAME_MAP;

// 맵안에서 표현할 오브젝트
typedef struct point{
	// 좌표
	float x, y; 
	// target과 자신과 거리를 구해서 target이 자신의 시야 안에 있는지
	// 확인 하는 함수
	// @param point *target 타겟이 될 point 점
	bool isinRange(point *target, int range){
		// 두 점간의 거리가(피타고라스 정리 이용) 시야 거리보다 작은가? 작으면 true
		// 작지 않으면 false;
		return  this->distanceTo(target) <= range;
	}// is in Range

	// target과 자신과의 거리를 구해서 돌려주는 함수
	// @param point *target 거리측정을 할 target
	float distanceTo(point *target){
		float a, b;
		// x축 거리 계산
		if (x == target->x){		// 양쪽 숫자가 같을때 0
			a = 0;
		}
		else if (x < target->x){	// this.fX가 작을시에 타겟의 fX에서 this.fX를 뺌
			a = target->x - x;
		}
		else {						// 반대일 경우
			a = x - target->x;
		}// if()

		// y축 거리 계산
		if (y == target->y){		// 양쪽 숫자가 같을 때 0
			b = 0;
		}
		else if (y < target->y){	// this.fY가 작을시에 타겟의 fY에서 fY를 뺌
			b = target->y - y;
		}
		else {						// 반대의 경우
			b = y - target->y;
		} //if()

		// 두 점끼리의 거리를 피타고라스의 정리법칙을 이용하여 계산
		// sqrt(x축에서 두점사이의 거리^2 + y축에서의 두점 사이의 거리^2)
		return  sqrt(pow(a, 2) + pow(b, 2));
	}

	// 입력받은 좌표와 자신이 같은 좌표인지 확인
	// @param point *target 입력받은 좌표
	// @return bool 자신과 동일한 좌표인지 확인
	bool equalTo(point *target){
		return (x == target->x && y == target->y);
	}
}POINT;

typedef struct thief{
	POINT cur_pos; // 현재위치
	POINT destination; // 목적지
	int direction; // 현재 진행하는 방향 : AI용
	
	// 길찾기 AI만들다가 망함...
	// 아마 Graph알고리즘 이용해서 A*나 다잌스트라 길찾기를 해야할거 같은데..
	// 무조건 Turn Right를 이용하다보니 무한으로 같은 곳을 맴도는 문제가 생김
	// Graph Structure를 만들어서 사용하는 방법도 있겠지만...
	// 일단 C는 너무 추상화 단계가 낮아서 너무 불편하다...
	bool one_step_AI(game_map *map_info){
		// base case는 이미 현재 포지션이 목적 포지션과 동일할때
		if (cur_pos.x == destination.x && cur_pos.y == destination.y){
			// 도착했을때 행동을 콜한다
			return true;
		}
		else if (direction == right){
			if (!map_info->isMovable(cur_pos.x, cur_pos.y + 1)){
				direction = direction++;
				this->one_step_AI(map_info);
			}
			else {
				cur_pos.y++;
				return false;
			}// end inner if
		}
		else if (direction == up){
			if (!map_info->isMovable(cur_pos.x-1, cur_pos.y)){
				direction = direction++;
				this->one_step_AI(map_info);
			}
			else {
				cur_pos.x--;
				return false;
			}// end inner if
		}
		else if (direction == left){
			if (!map_info->isMovable(cur_pos.x, cur_pos.y - 1)){
				direction = direction++;
				this->one_step_AI(map_info);
			}
			else {
				cur_pos.y--;
				return false;
			}// end inner if
		}
		else if (direction == down){
			if (!map_info->isMovable(cur_pos.x + 1, cur_pos.y)){
				direction = right;
				this->one_step_AI(map_info);
			}
			else {
				cur_pos.x++;
				return false;
			}// end inner if
		}
		else {
			printf("이동 할수 없습니다.\n");
		}// end outer if
	}

	// 그냥 빈맵일때 100퍼센트 동작하는 알고리즘
	// 자기 좌표를 목적지 좌표에 맞춰 나간다.
	bool one_step_noAI(game_map *map_info){
		if (cur_pos.x == destination.x && cur_pos.y == destination.y){
			printf("도둑 : 탈출!\n");
			// 도착했을때 행동을 콜한다
			return true;
		}
		// 종행동
		else if (cur_pos.x < destination.x && map_info->isMovable(cur_pos.x + 1, cur_pos.y)){
			cur_pos.x++;
			return false;
		}
		else if (cur_pos.x > destination.x&& map_info->isMovable(cur_pos.x - 1, cur_pos.y)){
			cur_pos.x--;
			return false;
		} // 먼저 종행동 종료
		// 횡행동
		else if (cur_pos.y < destination.y&& map_info->isMovable(cur_pos.x, cur_pos.y + 1)){
			cur_pos.y++;
			return false;
		}
		else if (cur_pos.y > destination.y&& map_info->isMovable(cur_pos.x, cur_pos.y - 1)){
			cur_pos.y--;
			return false;
		} // 먼저 횡행동 종료		
		else {
			printf("헉... 경찰 앞으로 달려가다니...\n");
			return true;
		}
	}
} THIEF;

// 실은 그냥 cctv가 아니라 도둑을 발견하면 따라가는 로봇 ...
typedef struct cctv{
	POINT cur_pos;		// 현재위치
	POINT target_pos;	// 목표 위치
	int vision;			// 시야범위

	// 타겟위치 업데이트
	// @param point target 타겟의 위치
	void update_Target_pos(POINT *target){
		target_pos.x = target->x;
		target_pos.y = target->y;
	}

	// 그냥 빈맵일때 100퍼센트 동작하는 알고리즘
	// 자기 좌표를 목적지 좌표에 맞춰 나간다.
	// 탄환은 장애물에 구해받지 않고, 장애물을 부수면서 움직인다.
	// 도둑과는 다르게 대각선 움직임도 가능
	bool persuit(POINT *target){
		// 타겟 위치 수정, 현재 타겟의 위치를 받아서 자신이 가지고 있는 타겟의 위치를 수정한다.
		this->update_Target_pos(target);
		// BaseCase 명중했을때의 움직임
		if (cur_pos.x == target_pos.x && cur_pos.y == target_pos.y){
			// 명중했을때 행동을 콜한다
			return true;
		}
		// 대각행동
		else if (cur_pos.x < target_pos.x && cur_pos.y < target_pos.y){
			cur_pos.x++;
			cur_pos.y++;
			return false;
		}
		else if (cur_pos.x > target_pos.x && cur_pos.y > target_pos.y){
			cur_pos.x--;
			cur_pos.y--;
			return false;
		} // 대각 행동 종료
		// 이미 위에서 다른 경우는 다뺏으므로 y나 x가 같을시는 옵션에 안넣어줘도될득
		// 종행동
		else if (cur_pos.x < target_pos.x){
			cur_pos.x++;
			return false;
		}
		else if (cur_pos.x > target_pos.x){
			cur_pos.x--;
			return false;
		} // 먼저 종행동 종료
		// 횡행동
		else if (cur_pos.y < target_pos.y){
			cur_pos.y++;
			return false;
		}
		else if (cur_pos.y > target_pos.y){
			cur_pos.y--;
			return false;
		} // 먼저 횡행동 종료		
		else {
			printf("이동 할수 없습니다.\n");
			return true;
		}
	}
} CCTV;

// prototype
bool mapUpdate(GAME_MAP *new_map, THIEF *player, CCTV *watcher, int *type);
void mapLoading(GAME_MAP *new_map, THIEF *player, CCTV *watcher, int *type);
void objectLoading(THIEF *player, CCTV *watcher, int *type);
void printUI();
void gameload(GAME_MAP *new_map, THIEF *player, CCTV *watcher, int *type);
int mainMenu();
void print_signature();

// global variable
// 원래는 이렇게 하면 안되는데, 일단 단일과제 편의성을 위해 밖으로 뺌


void main(){
	// seeding
	srand(time(NULL));

	// main menu용
	int type = -1;

	// 게임 종료 flag
	bool arrived = false;

	// Game map
	GAME_MAP new_map;

	// Game object
	THIEF player;
	CCTV watcher;

	// 후에 랜덤처리 함수
	
	// main_menu loading
	type = mainMenu();

	// main menu에서 선택한 게임로드	///////////////////////////
	// 차후 UserInterface로 옮겨도 될득
	switch (type)
	{
	case 1:
	case 2:
	case 3:
		gameload(&new_map, &player, &watcher, &type);
		break;
	case 4:
		printf("종료합니다.\n");
		return;
		break;
	default:
		break;
	}
	//////////////////////////////////////////////////////////.

	system("cls");
	new_map.printMap();
	printf("맵 생성 및, object 생성완료. \n 시작합니다.\n");
	system("pause");
	system("cls");

	while (arrived!=true){
		arrived = mapUpdate(&new_map, &player, &watcher, &type);		// update
		printUI();														// UI 출력
		new_map.printMap();												// render map
		_sleep(500);													
		if (arrived){
			printf("게임이 완료되었습니다.\n");
			system("pause");
		}
		system("cls");
	}
}

// object들의 최초 변수를 받아서 object를 시작하는 함수
// 랜덤으로 오브젝트들의 위치를 조정한다.
// 또한 메뉴 옵션에 따라 경찰의 시야 역시 조정한다.
// @param THIEF *player 도둑
// @param CCTV *watcher 경찰
// @param int *option 메인메뉴에서 선택한 옵션
void objectLoading(THIEF *player, CCTV *watcher, int *option){
	player->cur_pos = { rand() % MAP_VERTICAL, rand() % MAP_HORIZONTAL };
	player->destination = { rand() % MAP_VERTICAL, rand() % MAP_HORIZONTAL };
	player->direction = right;
	watcher->cur_pos = { rand() % MAP_VERTICAL, rand() % MAP_HORIZONTAL };
	if (*option == 1 || *option == 3){
		watcher->vision = 5;
	}
	else {
		watcher->vision = 10;
	}
}

// 초기화된 오브젝트들을 최초 로딩하는 함수
// 옵션에 따라 맵이 달라진다.
// 1, 2번 옵션은 빈맵, 3번 옵션은 장애물이 섞인 맵을 로딩한다.
// @param GAME_MAP *new_map 맵정보를 저장할 변수 주소
// @param THIEF *player 도둑
// @param CCTV *watcher 경찰
// @param int *option 메인메뉴에서 선택한 옵션
void mapLoading(GAME_MAP *new_map, THIEF *player, CCTV *watcher, int *option){
	// 옵션에 따른 맵 초기화
	if (*option == 1 || *option == 2){
		new_map->initmap_empty();
	}
	else if (*option == 3){
		new_map->initmap_ob();
	}
	// 맵에 오브젝트 정보 입력
	new_map->setObject(player->cur_pos.x, player->cur_pos.y, thief);
	new_map->setObject(player->destination.x, player->destination.y, dest);
	new_map->setObject(watcher->cur_pos.x, watcher->cur_pos.y, tower);	
}

// 프레임, 혹은 움직임마다 맵정보를 업데이트해주는 함수
// 옵션에 따라 움직임이 달라진다.
// 1, 3번 옵션은 경찰이 도둑을 발견하면 게임오버
// 2번 옵션은 경찰이 도둑에게 다가가서 체포하면 게임오버
// @param GAME_MAP *new_map 맵정보를 저장할 변수 주소
// @param THIEF *player 도둑
// @param CCTV *watcher 경찰
// @param int *option 메인메뉴에서 선택한 옵션
bool mapUpdate(GAME_MAP *new_map, THIEF *player, CCTV *watcher, int *option){
	// 게임이 끝났는지 리턴할 변수
	bool static ret = false;

	// 현재 도둑의 위치는 다시 움직일수 있는 타일로 바꿔준다.
	new_map->setObject(player->cur_pos.x, player->cur_pos.y, movable);

	// 만약 1,2번(길찾기 AI가 없는 옵션)인 경우 해당 함수를 호출해 도둑을 이동
	if (*option == 1 || *option == 2){
		if (ret == false){
			ret = player->one_step_noAI(new_map);
		}
		else{
			//
		}
	}
	// 만약 3번(길찾기 AI)인 경우 해당 함수를 호출해 도둑을 이동
	else if (*option == 3){
		if (ret == false){
			ret = player->one_step_AI(new_map);
		}
		else {
			//
		}
	}
	// 맵정보에서 도둑의 위치를 수정해준다.
	new_map->setObject(player->cur_pos.x, player->cur_pos.y, thief);


	// 이후 경찰의 움직임 업데이트
	// 경찰 도둑을 발견했을때 내보내는 메세지 (1, 3번 옵션)
	if (*option == 1 || *option == 3){
		if (watcher->cur_pos.isinRange(&player->cur_pos, watcher->vision)){
			printf("\a Alert triggered, Game over\n");
			ret = true;
		}
	}
	// 2번 옵션, 경찰이 도둑을 추적할시
	else if (*option == 2){
		// cctv가 도둑을 발견했을때 내보내는 메세지
		if (watcher->cur_pos.isinRange(&player->cur_pos, watcher->vision) && ret != true){
			printf("\a용의자 확인, 추적중 \n");
			// 경찰의 현재위치는 움직일수 있는 타일로 수정해준다.(Prodecessor가 불가능하므로 일단 이렇게.._
			// 이러한 움직임의 문제는 movable외의 다른 타일(ex 목적지)를 밟고 지나갔을시
			// 복구가 불가능하다는 단점이 있다.
			new_map->setObject(watcher->cur_pos.x, watcher->cur_pos.y, movable);
			// 경찰의 추적함수를 통해 경찰의 현재위치를 수정
			watcher->persuit(&player->cur_pos);
			// 지도정보에 업데이트
			new_map->setObject(watcher->cur_pos.x, watcher->cur_pos.y, tower);	
			
			// 경찰과 도둑이 만났는지 확인
			ret = player->cur_pos.equalTo(&(watcher->cur_pos));
			
			// 만났을경우
			if (ret){
				printf("당신을 체포합니다. 철컹철컹\n");
				// 리턴이 if 구문안에 있을경우 return이 콜되었을 경우 함수는 무조건 종료된다.
				return ret;
			}
			return ret;
		}
	}
	return ret;
}

// 기본 UI출력
void printUI(){
	printf("도둑이 자동으로 목적지를 찾아가는 프로그램\n");
	printf("도둑 : ◈, 경찰 : ◎, 목적지 : 목\n");
}

// Main menu 렌더 및 출력
int mainMenu(){
	int ret = -1;
	while (true){
		print_signature();
		printf("1. 빈 맵, no길찾기 AI, 경찰 시야거리내 도둑 발견시 게임over\n");
		printf("2. 빈 맵, no길찾기, 경찰이 도둑추적, 체포시 게임 over\n");
		printf("3. 장애물 맵, 길찾기 AI(테스트중), no 탄환, 시야거리내 게임 over\n");
		printf("0. 종료\n");
		printf("입력 : ");
		scanf("%d", &ret);
		if (ret != 1 && ret != 2 && ret != 3 && ret !=0){
			printf("옵션중에 다시 골라주세요.\n");
		}
		return ret;
	}
}

// 게임을 옵션에 따라서 로딩하는 함수
// 상황에 따라 로딩화면을 이쪽에 집어넣어 렌더 시킬수 있다.
// 만약 비동기식으로 렌더가 가능할 경우, 로딩화면 렌더와 로딩을 동시에 진행가능
void gameload(GAME_MAP *new_map, THIEF *player, CCTV *watcher, int *type){	
	system("cls");
	printf("로딩중...\n");
	_sleep(2000);
	objectLoading(player, watcher, type);				// loading object
	mapLoading(new_map, player, watcher, type);		// loading map
}

// 서명
void print_signature(){
	printf("이희동\n");
	printf("SGA51A\n");
	printf("07182014 과제\n");
	printf("============================================================\n");
	printf("도둑과 경찰\n\n");
}