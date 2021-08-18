#include <iostream>
using namespace std;
long long int dp[1001];

long long int func(int n)
{
    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] % 10007 + 2 * dp[i - 2] % 10007;
    }

    return dp[n] % 10007;

}

int main()
{
    int n;
    cin >> n;

    cout << func(n);
}
