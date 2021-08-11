// 9461 (파도반 수열).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
using namespace std;
long long int dp[101];

void func(int n, int k)
{
	for (int i = k + 1; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}
}
int main()
{
	dp[0] = 0; 
	dp[1] = 1; 
	dp[2] = 1; 
	dp[3] = 1; 
	dp[4] = 2; 
	dp[5] = 2;

	int t;
	int max = 5;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		if (n > max)
		{
			func(n, max);
			max = n;
		}
		printf("%lld\n",dp[n]);
	}
}
