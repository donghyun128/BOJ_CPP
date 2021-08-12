#include <iostream>
#define mod 1000000000 
using namespace std;
long long int dp[101][10] = { 0 };

long long int func(int n)
{
    long long int sum = 0;
    dp[1][0] = 0;
    for (int j = 1; j <= 9; j++)
    {
        dp[1][j] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
                dp[i + 1][j + 1] += dp[i][j] % mod;
            else if (j == 9)
                dp[i + 1][j - 1] += dp[i][j] % mod;
            else
            {
                dp[i + 1][j + 1] += (dp[i][j] % mod);
                dp[i + 1][j - 1] += (dp[i][j] % mod);
            }
        }
    }

    for (int j = 0; j <= 9; j++)
    {
        sum += dp[n][j] % mod;
    }
    return sum % mod;

}

int main()
{
    int N;
    cin >> N;
    printf("%lld",func(N));
}
