// 9095 (1,2,3 더하기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>
#include <cstring>
using namespace std;
int dp[11] = { 0 };


int main()
{
    int max = 3;
    int T;
    cin >> T;
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        if (n > max)
        {
            for (int k = max+1; k <= n; k++)
                dp[k] = dp[k - 1] + dp[k - 2] + dp[k - 3];
            max = n;
        }
        printf("%d\n", dp[n]);
    }
}
