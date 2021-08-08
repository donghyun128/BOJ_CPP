// 2225 (합분해).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#define mod 1000000000
using namespace std;
long long int dp[201][201] = { 0 };

long long int func(int n, int k)
{
    for (int i = 2; i<=k; i++)
        for (int j = 0; j <= n; j++)
        {
            for (int t = 0; t <= n; t++)
            {
                if (j - t >= 0)
                {
                    dp[j][i] += dp[j - t][i - 1];
                    dp[j][i] %= mod;   // mod의 위치는 항상 dp 갱신할 때 써주어야 함.
                }
            }
        }
    return dp[n][k] % mod;
}

int main()
{
    int n,k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++)
    {
        dp[i][1] = 1;
    }

    cout << func(n, k);
}
