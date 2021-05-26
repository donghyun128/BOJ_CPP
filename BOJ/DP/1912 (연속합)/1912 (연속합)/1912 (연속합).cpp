// 1912 (연속합).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001] = {0};

int main()
{
    int input;
    int arr[100000];
    cin >> input;
    
    for (int i = 0; i < input; i++)
    {
        cin >> arr[i];
    }

    
    dp[0] = arr[0];
    
    for (int i = 1; i < input; i++)
    {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);

    }
    int max_value = dp[0];
    for (int i = 1; i < input; i++)
    {
        if (dp[i] > max_value)
        {
            max_value = dp[i];
        }
    }

    printf("%d", max_value);

     return 0;
     
}

