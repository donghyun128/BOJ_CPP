// 2133 (타일 채우기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
int dp[31] = {0};

void three_tile(int n)
{
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			dp[i] = dp[i - 2] * dp[2];
			for (int j = 4; j <= i; j += 2)
			{
				dp[i] += dp[i - j] * 2;
			}
		}
		else
			dp[i] = 0;
	}
}

int main()
{
	int n;
	cin >> n;
	three_tile(n);
	printf("%d", dp[n]);

}
