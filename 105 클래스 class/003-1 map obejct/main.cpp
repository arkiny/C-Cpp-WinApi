/*
map class 만들기

의문?!]
binary로 저장했을 때, iostream으로 structure를 제대로 불러오지 못했다.
분명 예전 과제 004-2에서는 그냥 binary로 바로 저장했어도 잘됬는데,
아마 structure안에 저장 파일이 하나밖에 없어서 였을까?

현재대로 저장하면 저장파일은 좀더 직관적이 되겠지만, 보안성은....

Do more] (08032014 2119 시작)
State class를 만들어서 렌더해서 돌아다니게 할수 있다.

첨삭 ] 파일 저장 / 불러오기 과정은 버퍼(청크)를 만들어서
한번에 실시해주는 것이 프로세스 시간 절약에 큰도움이 된다. 
다음번에는 청크청크로 세이브/로드 를 실시하자.

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
	Map test_map2 = Map(5,5); // 비록 5*5로 만들었지만, 로딩중 메모리 재정리를 통해 3*3타일맵 로딩
	test_map2.loadMapFile("Data.dat");
	test_map2.renderMap();
	// 000
	// 100
	// 000
	system("pause");
}