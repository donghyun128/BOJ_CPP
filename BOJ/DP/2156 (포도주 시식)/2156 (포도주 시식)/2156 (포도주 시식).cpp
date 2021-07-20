#include <iostream>
#include <algorithm>
using namespace std;

int juice[10001] = { 0 };
int dp[10001] = { 0 };

int cal(int n)
{
	int tmp = 0;
	for (int i = 3; i <= n; i++)
	{
		tmp = max(dp[i - 1], dp[i - 3] + juice[i] + juice[i - 1]);
		tmp = max(tmp, dp[i - 2] + juice[i]);
		dp[i] = tmp;
	}
	return dp[n];
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> juice[i];
	}
	dp[1] = juice[1];
	dp[2] = juice[1] + juice[2];

	printf("%d", cal(n));


}
