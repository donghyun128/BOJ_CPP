// 11399 (ATM).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int p[1000];
	int t = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> p[i];
	}

	sort(p, p + N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			t += p[j];
		}
	}

	printf("%d", t);
}
