/*
	���� �ҷ�����
*/

#include <stdio.h>

// int �����ϴ� ���� void �����ϴ� ���� �ϴ� �ٸ��� �ٸ�
int main(){
	FILE* pfile = nullptr;

	pfile = fopen("data.txt", "r");
	{
		//
		int buff = 0;
		while (true){
			// ���ڸ� �ѱ��ھ� �о�´�.
			if (buff == EOF) break;
			buff = fgetc(pfile);
			printf("%c", buff);	
					
		}
	}
	fclose(pfile);


	return 0;
}

/*
���� ]]

����Ʈ�� ����Ÿ�� �����ϰ� �ҷ�����
*/