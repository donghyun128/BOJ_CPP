// 10610 (30).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//30배수 : 자릿 수의 합 : 3의 배수, 맨 끝자리 수: 0

int main()
{
	string N;
	int d_sum = 0;
	int isZero = 0;
	int arr[100000];
	cin >> N;

	for (int i = 0; i < N.length(); i++)
	{
		int num = N[i] - '0';
		arr[i] = num;
		d_sum += num;
		if (num == 0)
			isZero = 1;
	}

	if (isZero == 0 || d_sum % 3 != 0)
		printf("%d", -1);
	else
	{
		sort(arr, arr + N.length(),greater<int>());
		for (int i = 0; i < N.length(); i++)
		{
			printf("%d", arr[i]);
		}
	}
   
}
