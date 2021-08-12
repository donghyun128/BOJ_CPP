// 9465 (스티커).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;
int arr[2][100001];
int dp[2][100001];

int func(int n)
{
	dp[0][1] = arr[0][1];
	dp[1][1] = arr[1][1];
	dp[0][2] = arr[0][2] + arr[1][1];
	dp[1][2] = arr[1][2] + arr[0][1];

	for (int i = 3; i <= n; i++)
	{
		dp[0][i] = max(dp[0][i - 2], dp[1][i - 2]) + arr[0][i];
		dp[0][i] = max(dp[1][i - 1] + arr[0][i], dp[0][i]);

		dp[1][i] = max(dp[0][i - 2], dp[1][i - 2]) + arr[1][i];
		dp[1][i] = max(dp[0][i - 1] + arr[1][i], dp[1][i]);
	}

	return max(dp[0][n], dp[1][n]);

}
int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;

		for (int j = 1; j <= n; j++)
			cin >> arr[0][j];
		for (int j = 1; j <= n; j++)
			cin >> arr[1][j];

		printf("%d\n", func(n));

	}
}
