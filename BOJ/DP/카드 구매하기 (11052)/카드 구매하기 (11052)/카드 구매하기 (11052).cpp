#include <iostream>
#include <algorithm>
using namespace std;
int price[1001];
int dp[1001];

int func(int n)
{
	price[0] = 0;
	for (int i = 0; i <= n; i++)
	{
		dp[i] = price[i];
	}

	for (int i = 2; i <= n; i++)
	{
			for (int j = 0; j <= i / 2; j++)
			{
				int m = max(dp[i], dp[i - j] + dp[j]);
				dp[i] = m;
			}
	}
	return dp[n];
}
int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> price[i];
	}

	printf("%d", func(N));
}
