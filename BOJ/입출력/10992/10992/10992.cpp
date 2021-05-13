// 10992.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int input;
	scanf_s("%d", &input);

	for (int i = 1; i <= input - 1; i++) {
		for (int j = 1; j <= input - i; j++)
			printf(" ");
		printf("*");
		if (i > 1) {
			for (int j = 1; j <= 2 * i - 3; j++)
				printf(" ");
			printf("*");
		}
		printf("\n");
	}
	for (int i = 1; i <= 2 * input - 1; i++)
		printf("*");

	return 0;
}

