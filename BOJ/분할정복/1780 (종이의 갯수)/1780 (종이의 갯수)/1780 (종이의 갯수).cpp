// 1780 (종이의 갯수).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>
using namespace std;

short arr[2188][2188];
int cnt[3] = { 0 };

bool checkSame(int y, int x, int size)
{
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (arr[y][x] != arr[i][j])
				return false;
		}
	}
	return true;
}

void func(int y, int x, int size)
{
	int div_size = size / 3;

	if (checkSame(y, x, size))
	{
		cnt[arr[y][x] + 1]++;
		return;
	}

	for (int i = y; i < y + size; i +=div_size)
	{
		for (int j = x; j < x + size; j += div_size)
		{
			func(i, j, div_size);
		}
	}

	return;
	
}

int main()
{

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	func(1, 1, N);

	for (int i = 0; i < 3; i++)
		printf("%d\n", cnt[i]);
}

