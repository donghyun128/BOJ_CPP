// 1699.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>
using namespace std;

int dp[100001];

int power_sum(int n) {
    dp[0] = 1;
    dp[1] = 1;
    int tmp;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = i; // 이 부분을 제대로 초기화를 못했다.
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], 1 + dp[i - j * j]); // 최소의 제곱수의 합이 꼭 1+dp[i-가장 큰제곱수]인 것은 아니다. 하나하나 다 살펴야 한다.
            if (i == j * j) dp[i] = 1;
       }
    }
    return dp[n];
}

int main()
{
   
    int n;
    cin >> n;
    printf("%d",power_sum(n));

    return 0;
    
}

