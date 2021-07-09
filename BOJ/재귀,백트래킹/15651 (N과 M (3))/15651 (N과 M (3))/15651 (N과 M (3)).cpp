// 15651 (N과 M (3)).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int n, m;
int arr[7];

void function(int k)
{
	if (m == k)
	{
		for (int i = 0; i < m; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		arr[k] = i + 1;
		function(k + 1);
	}
}

int main()
{
	cin >> n >> m;
	function(0);
}

