// 1992 (쿼드 트리).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>
#include <string>
using namespace std;
short arr[65][65];

int check(int y, int x, int size)
{
	int item = arr[y][x];

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (item != arr[i][j])
				return -1;
		}
	}

	return item;
}

void func(int y, int x, int size)
{
	int chk = check(y, x, size);
	int div_size = size / 2;

	if (chk == -1) {
		printf("(");

		if (size == 2)
		{
			for (int i = y; i < y + size; i++)
			{
				for (int j = x; j < x + size; j++)
				{
					printf("%d", arr[i][j]);
				}
			}
		}
		else
		{
			for (int i = y; i < y + size; i+=div_size)
			{
				for (int j = x; j < x + size; j+=div_size)
				{
					func(i, j, div_size);
				}
			}
		}
	}
	else
		printf("%d", chk);

	if (chk == -1)
		printf(")");
}

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 1; j <= N; j++)
		{
			arr[i][j] = tmp[j - 1]-48;
		}
	}

	func(1, 1, N);

}

