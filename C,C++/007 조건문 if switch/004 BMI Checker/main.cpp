/*
	BMI check
	(비만도 측정)
	BMI = 몸무게(kg) / (키(m) * 키(m))

	결과 수치
	20 미만 이면 -> 저체중
	20~23 이면 -> 정상체중
	23 초과면 -> 과체중
	26 이상 -> 비만
*/
#include <stdio.h>
void main(){
	// variable initialization
	float weight = 0.0f;
	float height = 0.0f;
	float bmi = 0.0f;

	// Interface
	printf("BMI Checker \n");
	printf("Put your weight(kg), and height(m) in metric system\n");
	
	// scan phase
	printf("Weight : ");
	scanf("%f", &weight);
	printf("Height : ");
	scanf("%f", &height);

	// calculation and printing phase
	bmi = weight / (height * height);
	printf("bmi : %.2f\n", bmi);
	if (bmi > 0 && bmi < 20.0f){		// less than 20
		printf("low-weight\n");
	}
	else if (bmi >= 20.0f && bmi <= 23.0f){ // bmi = 20~23
		printf("normal\n");
	}
	else if (bmi > 23.0f && bmi < 26.0f){	// bmi = more than 23, less than 26
		printf("over-weight\n");
	}
	else if (bmi >= 26){	// bmi == more than 26
		printf("obesity\n");
	}
	else{	// error handling
		printf("input error");
	}

}