// There may be some way, but I could not find the way to get arrow key
// from the scanf function.
// 방법이 있을 수있겠지만, 저는 방향키를 scanf 함수를 이용해 받는 법을 찾아내지 못했습니다.
// Therefore, I googled some, and decide to use the getch() function which is in conio.h
// 그래서, 구글링을 했고, Dos콘솔 명령어 라이브러리 conio.h 에 포함된 getch() 
// 함수를 이용하기로 결정하였습니다.
// About getch() function, please refer the link below
// getch() 함수에 대해서는 아래의 리퍼런스를 참조 바랍니다.
// Ref) http://msdn.microsoft.com/en-us/library/078sfkak.aspx

#include<stdio.h>	// standard input/output library 표준 입출력 라이브러리
#include<stdlib.h>	// For clear screen and pause screen, 화면 정리 및 정지를 위한 라이브러리
#include<conio.h>	// library for DOS console 도스 콘솔창을 위한 라이브러리

int main(){
	// 변수 초기화
	// Variable Initialization
	int cur_ver = 0, cur_hor = 0; // Variable for Current coordinator of the tile
	char input_key = 0; // To store input_key from user

	while (input_key != 27){	// While input_key is not 27 (Escape key)
		////////////////////////////////////////////////////////////////////////
		// Signature, 이름 표기
		printf("Heedong Lee\n");
		printf("SGA 51A\n");
		printf("tileMap Coordination moving Home Assignment\n\n");
		printf("그만 두려면 esc키를 2번 눌러주세요\n");
		// 세로 그리기
		for (int i = 0; i <= 8; i++){
			// 가로 그리기
			for (int j = 0; j <= 9; j++){
				if (i == cur_ver && j == cur_hor) {
					// 이 부분은 뻘짓
					// Did some studpid stuff
					if (input_key == 72){
						printf("△");
					}
					if (input_key == 80){
						printf("▽");
					}
					if (input_key == 75){
						printf("◁");
					}
					if (input_key == 77){
						printf("▷");
					}
					if (input_key != 72 && input_key != 80 && input_key != 75 && input_key != 77){
						printf("□");
					}
				}
				if (i != cur_ver || j != cur_hor) {
					printf("■");
				}
			} // end inner for
			printf("\n"); // 개행
		} // end outer for
		////////////////////////////////////////////////////////////////////////


		// get key from the user
		_getch();
		input_key = _getch();	// 한번 실행을 통해 앞쪽 주소 삭제
		// because arrow key has two byte address
		// we have to get rid of the front address using one more getch


		// 아직 "else if"나 "else"를 안배웠으므로,
		// if문을 이용해 모든 경우의 수를 처리함
		// we haven't yet learned "else if" or "else"
		// therefore we have to count all possibility in the condition			

		if (input_key == 72){ // 위 방향키, up 
			if (cur_ver == 0){	// 현재 가장자리인데 이동하려고 할때의 처리 (border handling)
				printf("out of ceiling \n");
				system("pause");
			}	// endif
			if (cur_ver > 0){	
				cur_ver--;				
			}	// endif		
		}// endif
		if (input_key == 80){ // 아래 방향키, down arrow
			if (cur_ver == 8){ // 현재 가장자리인데 이동하려고 할때의 처리 (border handling)
				printf("out of bottom\n");
				system("pause");
			}
			if (cur_ver < 8){	
				cur_ver++;
			}
		}

		// 경계처리를 하는 다른 방법
		// Different way
		// 일단 이동을 하고, 그곳이 경계 밖인지 확인하는 방법
		// move first, and check border
		if (input_key == 75) {// left
			cur_hor--; // mover first
			if (cur_hor < 0){ // 현재 가장자리인데 이동하려고 할때의 처리 (border handling)
				cur_hor++; // reset the position
				printf("out of port border \n");
				system("pause");
			}
		}
		if (input_key == 77) {// right
			cur_hor++;
			if (cur_hor > 9){ // 현재 가장자리인데 이동하려고 할때의 처리 (border handling)
				cur_hor--;
				printf("out of starboard border \n");
				system("pause");
			}
		}
		//
		// Error handling part, usually do nothing
		// 원래는 else를 이용해, error 핸들링을 해야하나 생략
		//

		system("cls");		// 화면 정리
	}
}
