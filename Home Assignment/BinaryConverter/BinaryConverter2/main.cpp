//////////////////////////////////////////////////////////////////////////////////
// @author Heedong Lee															//
// * Introduction																//
//	������ ���� ���� �� �ٺ����� ���� ���α׷��Դϴ�.								//
//	���Ǳ����� �ݺ����� ����Ҽ� �����Ƿ�(�ϴ� �ȹ���ٴ� �����Ͽ�)					//
//	���� �����ڿ� �����ð��� ��� �͵�θ� ���α׷��� ®����,						//
//	�׷��ٺ��� �� ª������ �ִ� �ڵ���� ���ϱ޼������� ������� �Ǿ����ϴ�.			//
//	�߰� �߰��� ���� �ּ��� �޷������� ũ�� �о� ���� �ʿ�� ����,					//
//	(�׳� ��� ©�� ������ �ϸ鼭 �̰����� ������� �͵��Դϴ�. ���� �Ǳ� �ɵ�..)	//
//	�ִ��� ���� �Ǽ����� ���ھ �̰����� ���� ���� �ּ� ���� �޾ҽ��ϴ�.			//
//	�ڵ� ��ü�� �����ð��� ���� ��� ���� �־ ¥������ ����߽��ϴ�.				//
//	ã�ƺ��� ���� ����ȭ�� �Ÿ��� �����Ŷ� ���ϴٸ�, �౸�� ��������....				//
//																				//
// * ���																		//
//	1. 2������ 10������ ��ȯ														//
//	2. 10������ 2������ ��ȯ														//
//	3. 2���� 4Ģ���� (4�ڸ�����)													//
//	4. ����ŷ(��Ȯ���� ���� ����Ʈ�� �̿���) 2���� ����								//
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
// �־��� ���� Spec																//
//																				//
// 10���� -> printf ("%d");														//
// 8���� -> %o																	//
// 16���� -> %x																	//
// 2���� -> �츮�� ������ �����													//
//																				//
// 2������ �Է� : __ __ __ __ 4bit												//
// (*8 *4 *2 *1 sum = ?)														//
// 10������ ��ȯ�Ͽ� ��� = __													//
//																				//
// 10������ �Է� : __ (15���� ����)												//
// 2������ ��ȯ = __																//
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
	// ** �����ð��� ��� �ʱ�ȭ **
	// ** �ڵ��߿��� �ʿ��� ������ �־��ٰ�, �������� �ּ��� �Բ� ���ʿ� ���Ƶνô� ������
	// ** ���̽ô°� ������ ���� ������ �ɰ��Դϴ�.

	int nIndexChoice = -1;
	int nf_Fourth = -1, nf_Third = -1, nf_Second = -1, nf_First = -1;	// first operand or binary
	int ns_Fourth = -1, ns_Third = -1, ns_Second = -1, ns_First = -1;	// second operand 
	int nf_Decimal = -1, ns_Decimal = -1;								// decimal num first and second operand 
	int n_Decimal = -1;													// for only binary converting
	int n_RetDecimal = -1;												// for return value
	int n_shift = -1;													// number of shifting


	// ** �ϴ� ���� ��쿡�� ��Ʈ�� ũ�� �ʱ�ȭ, �޴� ����, �Է�(��ĳ��), ���/������� ����� �������߽��ϴ�.

	// ** �޴�����
	// First, Program index
	// ** �����ð��� ��� printf�� ���� ������ ���α׷� ���̾ƿ� **
	// ** �Ƹ� ���� �����е��� �ͼ��Ͻǵ�... �� ��ũ�δ� �н�... **
	printf("=========================================================\n");
	printf("| ��'s Stupid Decimal-Binary Converter/Calculator	|\n");
	printf("| �� ���α׷��� Seoul Game Academy �������̸�,		|\n");
	printf("| �񿵸��� �������� �󸶵��� ��� �����մϴ�.		|\n");
	printf("| ���� �������� �ȹ��� �Ѥ�				|\n");
	printf("=========================================================\n");
	printf("| �ʿ��Ͻ� �۾��� �����ϼ���.				|\n");
	printf("=========================================================\n");
	printf("| 1. 2������ 10������ ��ȯ				|\n");
	printf("| 2. 10������ 2������ ��ȯ				|\n");
	printf("| 3. 2���� ����						|\n");
	printf("| 4. 2���� ����						|\n");
	printf("| 5. 2���� ����						|\n");
	printf("| 6. 2���� ������					|\n");
	printf("| 7. 2���� ���� * ( 2 ^ n ) ��� (����ŷ �̿�)		|\n");
	printf("| 8. 2���� ���� / ( 2 ^ n ) ��� (����ŷ �̿�)		|\n");
	printf("=========================================================\n");
	printf("�Է� : ");
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
	// ** �������� ���... ���⼭ �ǹ��� ��� ���� ���Ǳ����� ������ � ������� �� **
	// ** �޴� ������ �����ұ� ����߰� ���� �ñ����߿� �ϳ���
	// ** (����) ? (��, ����) : (����, ���ο� ����) ? (�� , ����) : (����, ���ο� ���� : ...) **
	// ** �� ���� �ߺ��Ͽ� ���ļ� ������ �ִ� ���̾����ϴ�.
	// ** ���� ���� �����غ��̴µ�, �ᱹ
	// ** (����) ? (��, ����) :
	// **	(���ο� ����) ? (��, ����) :
	// **	(���ο� ����) ? (��, ����) :
	// **		(��� ���ǿ� �ȸ�����.. �� else ������ ����)
	// ** �� ���� ������ �����Դϴ�.
	// ** ���� ���� �������� �޸� ���� state�� �ѹ��� �ټ� ���ٴ� ������ �־�����,
	// ** �� �κ��� �Ʒ��� ���� �ϵ��ڵ�(...)�� ���� �����߽��ϴ�.
	// ** ������ ���ٺ��� �����ǵ�, �ᱹ Java������ Switch Case ������ ����ϴܰ�(Ȥ�� ��������..) �������ϴ�....


	// ** �Է���Ʈ **
	//////////////////////////////
	// Scanning Part			//
	//////////////////////////////
	// Scanning part, printing	//
	nIndexChoice == 1 ? // if nIndexChoice is 1, we have to do converting binary to decimal
		printf("2���� ���ڸ��� �Է��ϼ���. _ _ _ _\n") :
		nIndexChoice == 2 ? // if nIndexChoice is 2, we have to do converting decimal to binary
		printf("10������ �Է��ϼ��� (0~15)\n") :
		nIndexChoice == 3 ? // if nIndexChoice is 3, binary addition
		printf("_ _ _ _ + _ _ _ _ (2����)\n") :
		nIndexChoice == 4 ? // if nIndexChoice is 4, binary subtraction
		printf("_ _ _ _ - _ _ _ _ (2����)\n") :
		nIndexChoice == 5 ? // if nIndexChoice is 5, binary multification
		printf("_ _ _ _ * _ _ _ _ (2����)\n") :
		nIndexChoice == 6 ? // if nIndexChoice is 6, binary division
		printf("_ _ _ _ / _ _ _ _ (2����)\n") :
		nIndexChoice == 7 ? // shifting to left
		printf("_ _ _ _ * ( 2 ^ _ ) \n") :
		nIndexChoice == 8 ? // shifting to right
		printf("_ _ _ _ / ( 2 ^ _ ) \n") :
		perror("Error : �޴��� ���� ��ȣ�Դϴ�.\n"); // Error handling

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


	// ** ���/��� �κ� 
	// ** ���/��� �κ��� ������ �����̱� ������ ���� �ڼ��� �ּ��� ���� �ʽ��ϴ�.
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
