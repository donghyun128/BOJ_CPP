// 10950.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
	int input;
	cin >> input;
	int* sum = (int*)malloc(sizeof(int) * input);
	memset(sum,0,sizeof(int) * input);

	int a = 0;
	int b = 0;
	for (int i = 0; i < input; i++) {
		cin >> a >> b;
		sum[i] = a + b;
	}
	for (int i = 0; i < input; i++) {
		printf("%d", sum[i]);
		printf("\n");
	}

	return 0;
}
