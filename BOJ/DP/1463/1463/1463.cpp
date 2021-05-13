// 1463.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

int dp[10000001] = {0};

int calc(int number) {
    int tmp = number;
    dp[1] = 0;
        for (int i = 2; i <= tmp; i++)
        {
            dp[i] = dp[i - 1] + 1;
            if (i % 3 == 0) { dp[i] = min(dp[i], 1 + dp[i / 3]); }
            if (i % 2 == 0) { dp[i] = min(dp[i], 1 + dp[i / 2]); }
        }
    return dp[number];
}

int main()
{
    int input;
    int c;
    cin >> input;
    cout << calc(input);

    return 0;
}
