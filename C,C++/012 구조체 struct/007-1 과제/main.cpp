/*
	@author		Heedong Arkiny Lee
	@date		07182014
	@git		https://github.com/arkiny/SGA-Learning-Heedong

	���� ]] Enemy�� �ʿ��� �̵��ϱ�
	����������������������������
	����������������������������
	����������������������������
	����������������������������
	����������������������������
	������������������Ÿ��������
	����������������������������
	����������������������������
	�����������������񤱤�������
	����������������������������
	����������������������������
	����������������������������

	Enemy ����ü�� start ��ġ���� Enemy ����
	Dest ��ġ�� �߰��� �ְ�
	�����ð� ���� �������� �̵��ϱ�
	
	�̰� Union Find �Ἥ ������ ����� ������ġ ã�ư��� �ص� �ɰ� ������

	_sleep(1000) 1000 = �� 1��
*/

//���� ������ ->
//struct point
// point�� ���� �ִ� �ٸ� ����Ʈ���� �����ͷ� ������ ����
// 
//struct cctv
//struct thief
//struct map
//function
//void mapload (random terrain loading) 
// -> int[][]�� 0�� ��� �Ұ�, 1�� ��� ����
// -> load �Ŀ� ������  Starting Point���� 
//				������  Target Point���� �̵��������� Ȯ���ϰ� �Ұ����ҽÿ�
//				��ε�
//void mapupdate(cctv, thief)
// -> map�� cctv�� thief(starting point)�� �ѷ���, 
// -> �� ��ġ�� Ȯ���ɶ�����
// -> reload �ǰԲ� ��
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

// mapũ�� ����, �Է� �������� ������ �ϴ� ���������� ����� ����
const int MAP_VERTICAL = 18;
const int MAP_HORIZONTAL = 18;

// Ÿ�� Ÿ�� ����
enum type{movable, not_movable, thief, tower, start, dest, border};
// ��ã�� AI�� ���� ���� ����
enum direc{right, up, left, down};

// AI����
enum pathAI{noAI, turnLeft};

// ���� object ����
typedef struct game_map{
	// ���� point �� ������Ʈ�ʹ� ������ �����̹Ƿ�
	// ���� point�� �� �ʿ�� ������ �ϴ�
	// (i % MAP_HORIZONTAL)[x��ǥ] + ( i/MAP_HORIZONTAL )[y��ǥ]
	// 1���� ������ ���� ������ ����
	// �˰��� ������ �����̳��� ���ϰ� �ϱ����ؼ�...��
	int map_point[MAP_VERTICAL * MAP_HORIZONTAL];

	// Random Map ����
	// random�Լ��� ���� �̵� ������ Ÿ�ϰ� �̵� �Ұ����� Ÿ���� �����Ѵ�.
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

	// �׳� ��� ����
	void initmap_empty(){
		for (int i = 0; i < (MAP_VERTICAL * MAP_HORIZONTAL); i++){
				map_point[i] = 0;			
		}
	}

	// �ش� ��ü object ��ġ
	// @param int x x��ǥ
	// @param int y y��ǥ
	// @param int type object Ÿ��
	void setObject(int x, int y, int type){
		map_point[(x * MAP_HORIZONTAL) + y] = type;
	} 

	// �Է� ���� ��ġ�� �����ϼ� �ִ� ������ Ȯ��
	// @param int x x��ǥ
	// @param int y y��ǥ
	bool isMovable(int x, int y){
		return map_point[(x * MAP_HORIZONTAL) + y] == movable
			|| map_point[(x * MAP_HORIZONTAL) + y] == dest
			|| map_point[(x * MAP_HORIZONTAL) + y] == start;
	}

	// �̵� �Ұ����� �ڸ����� ����, �̵� ������ �ڸ����� ��
	// ���Ŀ� render������ �������� �� �ҽ�
	// �ϴ��� �׽�Ʈ........�� ��� ������ �ε����� �ҽ��� ����� �ɷ�...
	// A*�� class�� Data Structure�� �ȹ�� c���� �����ϱ⿡�� �ʹ��� ������ �ִ�....
	void printMap(){
		for (int i = 0; i < (MAP_VERTICAL * MAP_HORIZONTAL); i++){
			if (i % MAP_HORIZONTAL == 0){
				printf("\n");
			}
			if (map_point[i] == movable){
				printf("%s", "��");
			}
			else if (map_point[i] == not_movable){
				printf("%s", "��");
			}
			else if (map_point[i] == thief){
				printf("%s", "��");
			}
			else if (map_point[i] == tower){
				printf("%s", "��");
			}
			else if (map_point[i] == start){
				printf("%s", "��");
			}
			else if (map_point[i] == dest){
				printf("%s", "��");
			}
			else{
			}
		}
		printf("\n");
	}
}GAME_MAP;

// �ʾȿ��� ǥ���� ������Ʈ
typedef struct point{
	// ��ǥ
	float x, y; 
	// target�� �ڽŰ� �Ÿ��� ���ؼ� target�� �ڽ��� �þ� �ȿ� �ִ���
	// Ȯ�� �ϴ� �Լ�
	// @param point *target Ÿ���� �� point ��
	bool isinRange(point *target, int range){
		// �� ������ �Ÿ���(��Ÿ��� ���� �̿�) �þ� �Ÿ����� ������? ������ true
		// ���� ������ false;
		return  this->distanceTo(target) <= range;
	}// is in Range

	// target�� �ڽŰ��� �Ÿ��� ���ؼ� �����ִ� �Լ�
	// @param point *target �Ÿ������� �� target
	float distanceTo(point *target){
		float a, b;
		// x�� �Ÿ� ���
		if (x == target->x){		// ���� ���ڰ� ������ 0
			a = 0;
		}
		else if (x < target->x){	// this.fX�� �����ÿ� Ÿ���� fX���� this.fX�� ��
			a = target->x - x;
		}
		else {						// �ݴ��� ���
			a = x - target->x;
		}// if()

		// y�� �Ÿ� ���
		if (y == target->y){		// ���� ���ڰ� ���� �� 0
			b = 0;
		}
		else if (y < target->y){	// this.fY�� �����ÿ� Ÿ���� fY���� fY�� ��
			b = target->y - y;
		}
		else {						// �ݴ��� ���
			b = y - target->y;
		} //if()

		// �� �������� �Ÿ��� ��Ÿ����� ������Ģ�� �̿��Ͽ� ���
		// sqrt(x�࿡�� ���������� �Ÿ�^2 + y�࿡���� ���� ������ �Ÿ�^2)
		return  sqrt(pow(a, 2) + pow(b, 2));
	}

	// �Է¹��� ��ǥ�� �ڽ��� ���� ��ǥ���� Ȯ��
	// @param point *target �Է¹��� ��ǥ
	// @return bool �ڽŰ� ������ ��ǥ���� Ȯ��
	bool equalTo(point *target){
		return (x == target->x && y == target->y);
	}
}POINT;

typedef struct thief{
	POINT cur_pos; // ������ġ
	POINT destination; // ������
	int direction; // ���� �����ϴ� ���� : AI��
	
	// ��ã�� AI����ٰ� ����...
	// �Ƹ� Graph�˰��� �̿��ؼ� A*�� �ٟ彺Ʈ�� ��ã�⸦ �ؾ��Ұ� ������..
	// ������ Turn Right�� �̿��ϴٺ��� �������� ���� ���� �ɵ��� ������ ����
	// Graph Structure�� ���� ����ϴ� ����� �ְ�����...
	// �ϴ� C�� �ʹ� �߻�ȭ �ܰ谡 ���Ƽ� �ʹ� �����ϴ�...
	bool one_step_AI(game_map *map_info){
		// base case�� �̹� ���� �������� ���� �����ǰ� �����Ҷ�
		if (cur_pos.x == destination.x && cur_pos.y == destination.y){
			// ���������� �ൿ�� ���Ѵ�
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
			printf("�̵� �Ҽ� �����ϴ�.\n");
		}// end outer if
	}

	// �׳� ����϶� 100�ۼ�Ʈ �����ϴ� �˰���
	// �ڱ� ��ǥ�� ������ ��ǥ�� ���� ������.
	bool one_step_noAI(game_map *map_info){
		if (cur_pos.x == destination.x && cur_pos.y == destination.y){
			printf("���� : Ż��!\n");
			// ���������� �ൿ�� ���Ѵ�
			return true;
		}
		// ���ൿ
		else if (cur_pos.x < destination.x && map_info->isMovable(cur_pos.x + 1, cur_pos.y)){
			cur_pos.x++;
			return false;
		}
		else if (cur_pos.x > destination.x&& map_info->isMovable(cur_pos.x - 1, cur_pos.y)){
			cur_pos.x--;
			return false;
		} // ���� ���ൿ ����
		// Ⱦ�ൿ
		else if (cur_pos.y < destination.y&& map_info->isMovable(cur_pos.x, cur_pos.y + 1)){
			cur_pos.y++;
			return false;
		}
		else if (cur_pos.y > destination.y&& map_info->isMovable(cur_pos.x, cur_pos.y - 1)){
			cur_pos.y--;
			return false;
		} // ���� Ⱦ�ൿ ����		
		else {
			printf("��... ���� ������ �޷����ٴ�...\n");
			return true;
		}
	}
} THIEF;

// ���� �׳� cctv�� �ƴ϶� ������ �߰��ϸ� ���󰡴� �κ� ...
typedef struct cctv{
	POINT cur_pos;		// ������ġ
	POINT target_pos;	// ��ǥ ��ġ
	int vision;			// �þ߹���

	// Ÿ����ġ ������Ʈ
	// @param point target Ÿ���� ��ġ
	void update_Target_pos(POINT *target){
		target_pos.x = target->x;
		target_pos.y = target->y;
	}

	// �׳� ����϶� 100�ۼ�Ʈ �����ϴ� �˰���
	// �ڱ� ��ǥ�� ������ ��ǥ�� ���� ������.
	// źȯ�� ��ֹ��� ���ع��� �ʰ�, ��ֹ��� �μ��鼭 �����δ�.
	// ���ϰ��� �ٸ��� �밢�� �����ӵ� ����
	bool persuit(POINT *target){
		// Ÿ�� ��ġ ����, ���� Ÿ���� ��ġ�� �޾Ƽ� �ڽ��� ������ �ִ� Ÿ���� ��ġ�� �����Ѵ�.
		this->update_Target_pos(target);
		// BaseCase ������������ ������
		if (cur_pos.x == target_pos.x && cur_pos.y == target_pos.y){
			// ���������� �ൿ�� ���Ѵ�
			return true;
		}
		// �밢�ൿ
		else if (cur_pos.x < target_pos.x && cur_pos.y < target_pos.y){
			cur_pos.x++;
			cur_pos.y++;
			return false;
		}
		else if (cur_pos.x > target_pos.x && cur_pos.y > target_pos.y){
			cur_pos.x--;
			cur_pos.y--;
			return false;
		} // �밢 �ൿ ����
		// �̹� ������ �ٸ� ���� �ٻ����Ƿ� y�� x�� �����ô� �ɼǿ� �ȳ־��൵�ɵ�
		// ���ൿ
		else if (cur_pos.x < target_pos.x){
			cur_pos.x++;
			return false;
		}
		else if (cur_pos.x > target_pos.x){
			cur_pos.x--;
			return false;
		} // ���� ���ൿ ����
		// Ⱦ�ൿ
		else if (cur_pos.y < target_pos.y){
			cur_pos.y++;
			return false;
		}
		else if (cur_pos.y > target_pos.y){
			cur_pos.y--;
			return false;
		} // ���� Ⱦ�ൿ ����		
		else {
			printf("�̵� �Ҽ� �����ϴ�.\n");
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
// ������ �̷��� �ϸ� �ȵǴµ�, �ϴ� ���ϰ��� ���Ǽ��� ���� ������ ��


void main(){
	// seeding
	srand(time(NULL));

	// main menu��
	int type = -1;

	// ���� ���� flag
	bool arrived = false;

	// Game map
	GAME_MAP new_map;

	// Game object
	THIEF player;
	CCTV watcher;

	// �Ŀ� ����ó�� �Լ�
	
	// main_menu loading
	type = mainMenu();

	// main menu���� ������ ���ӷε�	///////////////////////////
	// ���� UserInterface�� �Űܵ� �ɵ�
	switch (type)
	{
	case 1:
	case 2:
	case 3:
		gameload(&new_map, &player, &watcher, &type);
		break;
	case 4:
		printf("�����մϴ�.\n");
		return;
		break;
	default:
		break;
	}
	//////////////////////////////////////////////////////////.

	system("cls");
	new_map.printMap();
	printf("�� ���� ��, object �����Ϸ�. \n �����մϴ�.\n");
	system("pause");
	system("cls");

	while (arrived!=true){
		arrived = mapUpdate(&new_map, &player, &watcher, &type);		// update
		printUI();														// UI ���
		new_map.printMap();												// render map
		_sleep(500);													
		if (arrived){
			printf("������ �Ϸ�Ǿ����ϴ�.\n");
			system("pause");
		}
		system("cls");
	}
}

// object���� ���� ������ �޾Ƽ� object�� �����ϴ� �Լ�
// �������� ������Ʈ���� ��ġ�� �����Ѵ�.
// ���� �޴� �ɼǿ� ���� ������ �þ� ���� �����Ѵ�.
// @param THIEF *player ����
// @param CCTV *watcher ����
// @param int *option ���θ޴����� ������ �ɼ�
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

// �ʱ�ȭ�� ������Ʈ���� ���� �ε��ϴ� �Լ�
// �ɼǿ� ���� ���� �޶�����.
// 1, 2�� �ɼ��� ���, 3�� �ɼ��� ��ֹ��� ���� ���� �ε��Ѵ�.
// @param GAME_MAP *new_map �������� ������ ���� �ּ�
// @param THIEF *player ����
// @param CCTV *watcher ����
// @param int *option ���θ޴����� ������ �ɼ�
void mapLoading(GAME_MAP *new_map, THIEF *player, CCTV *watcher, int *option){
	// �ɼǿ� ���� �� �ʱ�ȭ
	if (*option == 1 || *option == 2){
		new_map->initmap_empty();
	}
	else if (*option == 3){
		new_map->initmap_ob();
	}
	// �ʿ� ������Ʈ ���� �Է�
	new_map->setObject(player->cur_pos.x, player->cur_pos.y, thief);
	new_map->setObject(player->destination.x, player->destination.y, dest);
	new_map->setObject(watcher->cur_pos.x, watcher->cur_pos.y, tower);	
}

// ������, Ȥ�� �����Ӹ��� �������� ������Ʈ���ִ� �Լ�
// �ɼǿ� ���� �������� �޶�����.
// 1, 3�� �ɼ��� ������ ������ �߰��ϸ� ���ӿ���
// 2�� �ɼ��� ������ ���Ͽ��� �ٰ����� ü���ϸ� ���ӿ���
// @param GAME_MAP *new_map �������� ������ ���� �ּ�
// @param THIEF *player ����
// @param CCTV *watcher ����
// @param int *option ���θ޴����� ������ �ɼ�
bool mapUpdate(GAME_MAP *new_map, THIEF *player, CCTV *watcher, int *option){
	// ������ �������� ������ ����
	bool static ret = false;

	// ���� ������ ��ġ�� �ٽ� �����ϼ� �ִ� Ÿ�Ϸ� �ٲ��ش�.
	new_map->setObject(player->cur_pos.x, player->cur_pos.y, movable);

	// ���� 1,2��(��ã�� AI�� ���� �ɼ�)�� ��� �ش� �Լ��� ȣ���� ������ �̵�
	if (*option == 1 || *option == 2){
		if (ret == false){
			ret = player->one_step_noAI(new_map);
		}
		else{
			//
		}
	}
	// ���� 3��(��ã�� AI)�� ��� �ش� �Լ��� ȣ���� ������ �̵�
	else if (*option == 3){
		if (ret == false){
			ret = player->one_step_AI(new_map);
		}
		else {
			//
		}
	}
	// ���������� ������ ��ġ�� �������ش�.
	new_map->setObject(player->cur_pos.x, player->cur_pos.y, thief);


	// ���� ������ ������ ������Ʈ
	// ���� ������ �߰������� �������� �޼��� (1, 3�� �ɼ�)
	if (*option == 1 || *option == 3){
		if (watcher->cur_pos.isinRange(&player->cur_pos, watcher->vision)){
			printf("\a Alert triggered, Game over\n");
			ret = true;
		}
	}
	// 2�� �ɼ�, ������ ������ �����ҽ�
	else if (*option == 2){
		// cctv�� ������ �߰������� �������� �޼���
		if (watcher->cur_pos.isinRange(&player->cur_pos, watcher->vision) && ret != true){
			printf("\a������ Ȯ��, ������ \n");
			// ������ ������ġ�� �����ϼ� �ִ� Ÿ�Ϸ� �������ش�.(Prodecessor�� �Ұ����ϹǷ� �ϴ� �̷���.._
			// �̷��� �������� ������ movable���� �ٸ� Ÿ��(ex ������)�� ��� ����������
			// ������ �Ұ����ϴٴ� ������ �ִ�.
			new_map->setObject(watcher->cur_pos.x, watcher->cur_pos.y, movable);
			// ������ �����Լ��� ���� ������ ������ġ�� ����
			watcher->persuit(&player->cur_pos);
			// ���������� ������Ʈ
			new_map->setObject(watcher->cur_pos.x, watcher->cur_pos.y, tower);	
			
			// ������ ������ �������� Ȯ��
			ret = player->cur_pos.equalTo(&(watcher->cur_pos));
			
			// ���������
			if (ret){
				printf("����� ü���մϴ�. ö��ö��\n");
				// ������ if �����ȿ� ������� return�� �ݵǾ��� ��� �Լ��� ������ ����ȴ�.
				return ret;
			}
			return ret;
		}
	}
	return ret;
}

// �⺻ UI���
void printUI(){
	printf("������ �ڵ����� �������� ã�ư��� ���α׷�\n");
	printf("���� : ��, ���� : ��, ������ : ��\n");
}

// Main menu ���� �� ���
int mainMenu(){
	int ret = -1;
	while (true){
		print_signature();
		printf("1. �� ��, no��ã�� AI, ���� �þ߰Ÿ��� ���� �߽߰� ����over\n");
		printf("2. �� ��, no��ã��, ������ ��������, ü���� ���� over\n");
		printf("3. ��ֹ� ��, ��ã�� AI(�׽�Ʈ��), no źȯ, �þ߰Ÿ��� ���� over\n");
		printf("0. ����\n");
		printf("�Է� : ");
		scanf("%d", &ret);
		if (ret != 1 && ret != 2 && ret != 3 && ret !=0){
			printf("�ɼ��߿� �ٽ� ����ּ���.\n");
		}
		return ret;
	}
}

// ������ �ɼǿ� ���� �ε��ϴ� �Լ�
// ��Ȳ�� ���� �ε�ȭ���� ���ʿ� ����־� ���� ��ų�� �ִ�.
// ���� �񵿱������ ������ ������ ���, �ε�ȭ�� ������ �ε��� ���ÿ� ���డ��
void gameload(GAME_MAP *new_map, THIEF *player, CCTV *watcher, int *type){	
	system("cls");
	printf("�ε���...\n");
	_sleep(2000);
	objectLoading(player, watcher, type);				// loading object
	mapLoading(new_map, player, watcher, type);		// loading map
}

// ����
void print_signature(){
	printf("����\n");
	printf("SGA51A\n");
	printf("07182014 ����\n");
	printf("============================================================\n");
	printf("���ϰ� ����\n\n");
}