//////////////////////////////////////////////////////////////////////////////////
// @author Heedong Lee															//
// * Introduction																//
//	솔직히 제가 봐도 좀 바보같이 만든 프로그램입니다.								//
//	조건구문과 반복문을 사용할수 없으므로(일단 안배웠다는 가정하에)					//
//	순수 연산자와 수업시간에 배운 것들로만 프로그램을 짰으며,						//
//	그러다보니 더 짧아질수 있던 코드들이 기하급수적으로 길어지게 되었습니다.			//
//	중간 중간에 영어 주석이 달려있지만 크게 읽어 보실 필요는 없고,					//
//	(그냥 어떻게 짤까 디자인 하면서 이것저것 적어넣은 것들입니다. 참고가 되긴 될득..)	//
//	최대한 참고가 되셨으면 좋겠어서 이것저것 쓸데 없이 주석 많이 달았습니다.			//
//	코드 자체는 수업시간에 들은 모든 것을 넣어서 짜보려고 노력했습니다.				//
//	찾아보면 좀더 최적화할 거리는 있을거라 봅니다만, 축구를 보기위해....				//
//																				//
// * 기능																		//
//	1. 2진수를 10진수로 변환														//
//	2. 10진수를 2진수로 변환														//
//	3. 2진수 4칙연산 (4자리수만)													//
//	4. 마스킹(정확히는 그중 쉬프트를 이용한) 2진수 연산								//
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
// 주어진 과제 Spec																//
//																				//
// 10진수 -> printf ("%d");														//
// 8진수 -> %o																	//
// 16진수 -> %x																	//
// 2진수 -> 우리가 과제로 만들기													//
//																				//
// 2진수를 입력 : __ __ __ __ 4bit												//
// (*8 *4 *2 *1 sum = ?)														//
// 10진수로 변환하여 출력 = __													//
//																				//
// 10진수를 입력 : __ (15까지 가능)												//
// 2진수로 변환 = __																//
//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

int main(){

	// check what kind of calculation
	// 1. Binary to Decimal
	// 2. Decimal To Binary
	// 3. Binary Calculations (Add, Sub, Multi, Div) 
	//		- I will use binary masking if I can use

	// is logical operator ? support lambda function?
	// Yes, we can.

	// variable initialization part
	// ** 수업시간에 배운 초기화 **
	// ** 코딩중에는 필요한 곳마다 넣었다가, 마지막에 주석과 함께 앞쪽에 몰아두시는 습관을
	// ** 들이시는게 나중을 위해 도움이 될것입니다.

	int nIndexChoice = -1;
	int nf_Fourth = -1, nf_Third = -1, nf_Second = -1, nf_First = -1;	// first operand or binary
	int ns_Fourth = -1, ns_Third = -1, ns_Second = -1, ns_First = -1;	// second operand 
	int nf_Decimal = -1, ns_Decimal = -1;								// decimal num first and second operand 
	int n_Decimal = -1;													// for only binary converting
	int n_RetDecimal = -1;												// for return value
	int n_shift = -1;													// number of shifting


	// ** 일단 저의 경우에는 파트를 크게 초기화, 메뉴 선택, 입력(스캐닝), 계산/출력으로 나누어서 디자인했습니다.

	// ** 메뉴선택
	// First, Program index
	// ** 수업시간에 배운 printf를 통한 간단한 프로그램 레이아웃 **
	// ** 아마 도스 쓰던분들은 익숙하실득... 색 매크로는 패스... **
	printf("=========================================================\n");
	printf("| 희동's Stupid Decimal-Binary Converter/Calculator	|\n");
	printf("| 본 프로그램은 Seoul Game Academy 과제용이며,		|\n");
	printf("| 비영리적 목적으로 얼마든지 사용 가능합니다.		|\n");
	printf("| 버그 제보따위 안받음 ㅡㅡ				|\n");
	printf("=========================================================\n");
	printf("| 필요하신 작업을 선택하세요.				|\n");
	printf("=========================================================\n");
	printf("| 1. 2진수를 10진수로 변환				|\n");
	printf("| 2. 10진수를 2진수로 변환				|\n");
	printf("| 3. 2진수 덧셈						|\n");
	printf("| 4. 2진수 뺄셈						|\n");
	printf("| 5. 2진수 곱셈						|\n");
	printf("| 6. 2진수 나눗셈					|\n");
	printf("| 7. 2진수 숫자 * ( 2 ^ n ) 계산 (마스킹 이용)		|\n");
	printf("| 8. 2진수 숫자 / ( 2 ^ n ) 계산 (마스킹 이용)		|\n");
	printf("=========================================================\n");
	printf("입력 : ");
	scanf("%d", &nIndexChoice);
	printf("\n");

	//////////////////////////////////////////////////////////////////////////////////
	// Now we got the choice for working.											//
	// If we can use condition statement, the process would be easy.				//
	// However, for education purpose,												//
	// We will using ? operator which we learned from last lecture.					//
	// Because, this operator will accept just one statement per condition,			//
	// I will code this programing as stupid method.								//
	//////////////////////////////////////////////////////////////////////////////////
	// ** 쓸데없는 잡담... 여기서 의문이 든게 내가 조건구문을 못쓰면 어떤 방법으로 각 **
	// ** 메뉴 선택을 실행할까 고민했고 나온 궁금점중에 하나가
	// ** (조건) ? (참, 실행) : (거짓, 새로운 조건) ? (참 , 실행) : (거짓, 새로운 조건 : ...) **
	// ** 과 같이 중복하여 겹쳐서 조건을 주는 것이었습니다.
	// ** 저리 쓰면 복잡해보이는데, 결국
	// ** (조건) ? (참, 실행) :
	// **	(새로운 조건) ? (참, 실행) :
	// **	(새로운 조건) ? (참, 실행) :
	// **		(모든 조건에 안맞을시.. 곧 else 실행할 구문)
	// ** 과 같은 간단한 구조입니다.
	// ** 물론 조건 구문과는 달리 여러 state을 한번에 줄수 없다는 단점이 있었지만,
	// ** 그 부분은 아래와 같이 하드코딩(...)을 통해 보완했습니다.
	// ** 저렇게 쓰다보니 느낀건데, 결국 Java에서의 Switch Case 구문과 비슷하단걸(혹은 같을수도..) 느꼈습니다....


	// ** 입력파트 **
	//////////////////////////////
	// Scanning Part			//
	//////////////////////////////
	// Scanning part, printing	//
	nIndexChoice == 1 ? // if nIndexChoice is 1, we have to do converting binary to decimal
		printf("2진수 네자리를 입력하세요. _ _ _ _\n") :
		nIndexChoice == 2 ? // if nIndexChoice is 2, we have to do converting decimal to binary
		printf("10진수를 입력하세요 (0~15)\n") :
		nIndexChoice == 3 ? // if nIndexChoice is 3, binary addition
		printf("_ _ _ _ + _ _ _ _ (2진수)\n") :
		nIndexChoice == 4 ? // if nIndexChoice is 4, binary subtraction
		printf("_ _ _ _ - _ _ _ _ (2진수)\n") :
		nIndexChoice == 5 ? // if nIndexChoice is 5, binary multification
		printf("_ _ _ _ * _ _ _ _ (2진수)\n") :
		nIndexChoice == 6 ? // if nIndexChoice is 6, binary division
		printf("_ _ _ _ / _ _ _ _ (2진수)\n") :
		nIndexChoice == 7 ? // shifting to left
		printf("_ _ _ _ * ( 2 ^ _ ) \n") :
		nIndexChoice == 8 ? // shifting to right
		printf("_ _ _ _ / ( 2 ^ _ ) \n") :
		perror("Error : 메뉴에 없는 번호입니다.\n"); // Error handling

	// Scanning part, scanning	//
	nIndexChoice == 1 ? // Scanning each digit
		scanf("%d %d %d %d", &nf_Fourth, &nf_Third, &nf_Second, &nf_First) :
		nIndexChoice == 2 ? // Scanning Decimal number
		scanf("%d", &n_Decimal) :
		// Scanning two binary operands
		nIndexChoice == 3 || nIndexChoice == 4 || nIndexChoice == 5 || nIndexChoice == 6 ? 
		scanf("%d %d %d %d %d %d %d %d",
		&nf_Fourth, &nf_Third, &nf_Second, &nf_First, &ns_Fourth, &ns_Third, &ns_Second, &ns_First) :
		nIndexChoice == 7 || nIndexChoice == 8 ? // Scanning each digit
		scanf("%d %d %d %d %d", &nf_Fourth, &nf_Third, &nf_Second, &nf_First, &n_shift) :
		printf(""); // Error handling Do nothing


	// ** 계산/출력 부분 
	// ** 계산/출력 부분은 각자의 취향이기 때문에 따로 자세히 주석을 달진 않습니다.
	//////////////////////////////
	//Computing Part			//
	//////////////////////////////
	

	// 1. Binary to Decimal is EASY	//
	nIndexChoice == 1 ?
		printf("Binary to Decimal Converting Result : %d\n", 
				((nf_Fourth * 8) + (nf_Third * 4) + (nf_Second * 2) + (nf_First))) :
		printf(""); // do nothing



	// 2. Decimal to Binary Converting	//

	// Because we cannot use for or condition statement, 
	// we cannot soft coding for this compute
	// Let's do shitty-hard coding
	// However we forced put the input number, under 15, 
	// program will not compute division more than 4.

	// Fourth digit (*8)
	nIndexChoice == 2 && (n_Decimal != 0 || n_Decimal != 1) ?
		nf_First = n_Decimal % 2 :
		printf(""); // do nothing
	nIndexChoice == 2 && (n_Decimal != 0 || n_Decimal != 1) ?
		n_Decimal /= 2 :
		printf(""); // do nothing
	// Third digit (*4)
	nIndexChoice == 2 && (n_Decimal != 0 || n_Decimal != 1) ?
		nf_Second = n_Decimal % 2 :
		printf(""); // do nothing
	nIndexChoice == 2 && (n_Decimal != 0 || n_Decimal != 1) ?
		n_Decimal /= 2 :
		printf(""); // do nothing
	// Second digit (*2)
	nIndexChoice == 2 && (n_Decimal != 0 || n_Decimal != 1) ?
		nf_Third = n_Decimal % 2 :
		printf(""); // do nothing
	nIndexChoice == 2 && (n_Decimal != 0 || n_Decimal != 1) ?
		n_Decimal /= 2 :
		printf(""); // do nothing
	// First digit (*1)
	nIndexChoice == 2 && (n_Decimal == 0 || n_Decimal == 1) ?
		nf_Fourth = n_Decimal : 
		printf(""); // Error handling, should be 0 or 1

	nIndexChoice == 2 && (n_Decimal == 0 || n_Decimal == 1) ?
		printf("Converting Result : %d %d %d %d\n", nf_Fourth, nf_Third, nf_Second, nf_First) :
		printf(""); // this condition should not happend

	// 3 ~ 6. Basic Caculations	//

	// computing part for 3 ~ 8
	// We will convert the binary number to decimal first
	// Because the format of binary code is literaly made by us.
	// Compiler will not recognize that shit.

	// First Operand Conversion, 7 ~ 8 will using only this conversion set
	nIndexChoice == 3 || nIndexChoice == 4 || nIndexChoice == 5 || nIndexChoice == 6 
		|| nIndexChoice == 7 || nIndexChoice == 8 ?
		nf_Decimal = ((nf_Fourth * 8) + (nf_Third * 4) + (nf_Second * 2) + (nf_First)) :
		printf("");

	// Second Operand Conversion
	nIndexChoice == 3 || nIndexChoice == 4 || nIndexChoice == 5 || nIndexChoice == 6 ?
		ns_Decimal = ((ns_Fourth * 8) + (ns_Third * 4) + (ns_Second * 2) + (ns_First)) :
		printf("");

	// Do calculate
	nIndexChoice == 3 ? // addition
		n_RetDecimal = nf_Decimal + ns_Decimal : printf("");

	nIndexChoice == 4 ? // subtraction
		n_RetDecimal = nf_Decimal - ns_Decimal : printf("");

	nIndexChoice == 5 ? // division
		n_RetDecimal = nf_Decimal * ns_Decimal : printf("");

	nIndexChoice == 6 ? // multiplicaion
		n_RetDecimal = nf_Decimal / ns_Decimal : printf("");

	nIndexChoice == 7 ? // shifting left
		n_RetDecimal = nf_Decimal << n_shift : printf("");
	
	nIndexChoice == 8 ? // shifting right
		n_RetDecimal = nf_Decimal >> n_shift : printf("");

	// Convert result to binary from decimal number
	// We will not support the number over 15. (will just show 4 digits)
	
	// Fourth digit (*8)
	nIndexChoice == 3 || nIndexChoice == 4 || nIndexChoice == 5 || nIndexChoice == 6
		|| nIndexChoice == 7 || nIndexChoice == 8 ?
			nf_First = n_RetDecimal % 2 :
			printf(""); // do nothing
	nIndexChoice == 3 || nIndexChoice == 4 || nIndexChoice == 5 || nIndexChoice == 6 
		|| nIndexChoice == 7 || nIndexChoice == 8 ?
			n_RetDecimal /= 2 :
			printf(""); // do nothing
	// Third digit (*4)
	nIndexChoice == 3 || nIndexChoice == 4 || nIndexChoice == 5 || nIndexChoice == 6 
		|| nIndexChoice == 7 || nIndexChoice == 8 ?
		nf_Second = n_RetDecimal % 2 :
		printf(""); // do nothing
	nIndexChoice == 3 || nIndexChoice == 4 || nIndexChoice == 5 || nIndexChoice == 6 
		|| nIndexChoice == 7 || nIndexChoice == 8 ?
		n_RetDecimal /= 2 :
		printf(""); // do nothing
	// Second digit (*2)
	nIndexChoice == 3 || nIndexChoice == 4 || nIndexChoice == 5 || nIndexChoice == 6 
		|| nIndexChoice == 7 || nIndexChoice == 8 ?
		nf_Third = n_RetDecimal % 2 :
		printf(""); // do nothing
	nIndexChoice == 3 || nIndexChoice == 4 || nIndexChoice == 5 || nIndexChoice == 6 
		|| nIndexChoice == 7 || nIndexChoice == 8 ?
		n_RetDecimal /= 2 :
		printf(""); // do nothing
	// First digit (*1)
	nIndexChoice == 3 || nIndexChoice == 4 || nIndexChoice == 5 || nIndexChoice == 6 
		|| nIndexChoice == 7 || nIndexChoice == 8 ?
		nf_Fourth = n_RetDecimal % 2 :
		printf("\n"); // Error handling, should be 0 or 1

	// print out result
	nIndexChoice == 3 || nIndexChoice == 4 || nIndexChoice == 5 || nIndexChoice == 6 
		|| nIndexChoice == 7 || nIndexChoice == 8 ?
		printf("Calculation Result : %d %d %d %d\n", nf_Fourth, nf_Third, nf_Second, nf_First) :
		printf(""); // this condition should not happend	

	return 0;
}
