// 이친수 (2139).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

long long int dp[91][2];

long long int func(int n)
{
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    return dp[n][0] + dp[n][1];
}

int main()
{
    dp[1][0] = 0; dp[1][1] = 1;
    int n;
    cin >> n;

    printf("%lld", func(n));
}

