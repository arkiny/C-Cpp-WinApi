/*
map class �����

�ǹ�?!]
binary�� �������� ��, iostream���� structure�� ����� �ҷ����� ���ߴ�.
�и� ���� ���� 004-2������ �׳� binary�� �ٷ� �����߾ �߉�µ�,
�Ƹ� structure�ȿ� ���� ������ �ϳ��ۿ� ��� ������?

������ �����ϸ� ���������� ���� �������� �ǰ�����, ���ȼ���....

Do more] (08032014 2119 ����)
State class�� ���� �����ؼ� ���ƴٴϰ� �Ҽ� �ִ�.

÷�� ] ���� ���� / �ҷ����� ������ ����(ûũ)�� ����
�ѹ��� �ǽ����ִ� ���� ���μ��� �ð� ���࿡ ū������ �ȴ�. 
���������� ûũûũ�� ���̺�/�ε� �� �ǽ�����.

*/

#include "Map.h"

/*
	test main
*/
void main(){	
	Map test_map;
	test_map.createMap(3, 3);
	test_map.renderMap();
	// assert
	// 000
	// 000
	// 000
	test_map = Map(5, 5);
	test_map.renderMap();
	// assert
	// 00000
	// 00000
	// 00000
	// 00000
	// 00000
	test_map = Map(3, 3);
	test_map.renderMap();
	// 000
	// 000
	// 000
	test_map.setTile(1, 0, enemy);
	test_map.renderMap();
	// 000
	// 100
	// 000
	test_map.saveMapFile("Data.dat");
	test_map.setTile(1, 1, enemy); 
	test_map.setTile(1, 2, enemy);
	test_map.renderMap();
	// 000
	// 111
	// 000
	Map test_map2 = Map(5,5); // ��� 5*5�� ���������, �ε��� �޸� �������� ���� 3*3Ÿ�ϸ� �ε�
	test_map2.loadMapFile("Data.dat");
	test_map2.renderMap();
	// 000
	// 100
	// 000
	system("pause");
}