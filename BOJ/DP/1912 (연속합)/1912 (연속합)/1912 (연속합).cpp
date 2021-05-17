// 1912 (연속합).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

int dp[1002][1002] = {-100000};

int succ_sum(int input,int arr[])
{
    int num = input;
    for (int j = 0; j < input-1; j++)
    {
        dp[2][j] = arr[j] + arr[j + 1];
    }

    for (int i = 3; i < num-1; i++)
    {
        for (int j = 0; j < num - i;)
        {
            dp[i][j] = dp[i - 1][j] + arr[j + 2];
        }
    }
    int max= -100000;
    
    for (int i = 2; i < num - 1; i++)
    {
        for (int j = 0; j < num - i; j++)
        {
            if (dp[i][j] > max)
            {
                max = dp[i][j];
            }
        }
    }

    return max;
}


int main()
{
    int input;
    int arr[100000];
    cin >> input;
    
    for (int i = 0; i < input; i++)
    {
        cin >> arr[i];
    }
     int result = succ_sum(input, arr);
     cout << result << endl;


     return 0;

}

