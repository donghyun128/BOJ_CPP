// 15650 (N과 M (2)).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int n, m;
int arr[8];
bool checked[8] = {0};
void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m-1; i++)
		{
			if (arr[i] > arr[i + 1])
				return;

		}

		for (int i = 0; i < k; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!checked[i])
		{
			checked[i] = 1;
			arr[k] = i+1;
			func(k + 1);
			checked[i] = 0;

		}
	}
}

int main()
{
	cin >> n >> m;
	func(0);
}

