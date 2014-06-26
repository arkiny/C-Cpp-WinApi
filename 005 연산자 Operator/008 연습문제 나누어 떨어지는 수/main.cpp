/*
	숫자를 입력 : ____

	7로 나눠서...

	나누어 떨어지면					= 몫
	나누어 떨어지지 않으면		= 나머지
	*/

#include <stdio.h>
int main(){
	//init
	int nInput = -1;		// Input variable
	int nMod = -1;			// for modular value
	int nDiv = -1;			// for Division value
	int outResult = -1;	// our Return value

	//scaning part
	printf("숫자를 입력해주세요 : \n");
	scanf("%d", &nInput);

	if (nInput <= 0){
		printf("0이나 음수는 취급하지 않습니다. \n");
		return -1;
	}

	//compute and printing part
	nMod = nInput % 7;
	nDiv = nInput / 7;
	nMod != 0 ? outResult = nMod : outResult = nInput / 7;
	nMod != 0 ? printf("나머지가 남습니다 : %d\n", nMod) : printf("나누어 떨어집니다 - 몫 : %d\n", nDiv);

	return 0;
}