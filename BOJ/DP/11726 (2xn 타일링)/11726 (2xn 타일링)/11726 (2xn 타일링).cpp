// 11726 (2xn 타일링).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstring>
using namespace std;

int dp[1001];

int result(int n)
{
    memset(dp, -1, sizeof(dp));
    dp[1] = 1; dp[2] = 2;

    for (int i = 3; i<=n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    return dp[n];
}



int main()
{
    int n;
    cin >> n;

    cout << result(n);

    return 0;
}

