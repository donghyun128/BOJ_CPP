// 11866(요세푸스 문제 0).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main()
{
	int n, k;
	int arr[1000];
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < k; j++)
		{
			int tmp;
			tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		arr[i-1] = q.front();
		q.pop();
	}

	printf("<");
	for (int i = 0; i < n-1; i++)
	{
		printf("%d", arr[i]);
		printf(", ");
	}
	printf("%d>", arr[n-1]);

	return 0;

}

