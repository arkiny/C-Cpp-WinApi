/*
	���� �����ϱ�
	fopen()
	fclose()
*/

#include <stdio.h>		// fopen(), fclose(), printf(), scanf()

int main(){
	FILE* pfile = nullptr;

	//1. ������ ����.
	//data.txt�� ���� ( "w" ) mode write
	pfile = fopen("data.txt", "w");
	{
		//3. �ѱ��ھ� ����
		fputc('M', pfile);
		// My name
		fputc('y', pfile);
		fputc(' ', pfile);
		fputc('n', pfile);
		fputc('a', pfile);
		fputc('m', pfile);
		fputc('e', pfile);

		// ���൵ �ߴ�
		fputs("July\n 22\n", pfile);
		
		//My Age : xx , weight : XX, %d
		fprintf(pfile, "My Age : %d, weight : %d\nz", 28, 54);
	}

	//2. ������ �ݴ´�.
	fclose(pfile);

	return 0;
}
