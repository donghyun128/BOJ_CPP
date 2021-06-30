// 2011 (암호코드).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#define MOD 1000000
using namespace std;
int dp[5000] = {0};

int code_case(char* number, int size)
{
    dp[0] = 1;

    if (number[0] == '0')
    {
        return 0;
    }

    if (size >= 2)
    {
        int front1 = number[0] - '0';
        int front2 = number[1] - '0';
        if (front2 == 0)
        {
            if (front1 == 1 || front1 == 2)
            {
                dp[1] = 1;

            }
            else return 0;
        }
        else if (1<=front1 *10 + front2 && front1 *10 + front2 <=26)
        {
            dp[1] = 2;
        }

        else dp[1] = 1;

        for (int i = 2; i < size; i++)
        {
     
            int last1 = number[i - 1]-'0';
            int last2 = number[i]-'0';
            int last_d = last1 * 10 + last2;

            if (last2 == 0)
            {
                if (last1 == 1 || last1 == 2)
                {
                    dp[i] = dp[i - 2] % MOD;

                }

                else return 0;
            }

            else if (last1 == 0 && last2 != 0)
            {
                dp[i] = dp[i - 1] % MOD;
            }

            else if (1 <= last_d && last_d <= 26)
            {
                dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
            }

            else dp[i] = dp[i - 1] % MOD;
        }
    }
    return dp[size - 1] % MOD;
}


int main()
{
    int result = 0;
    int isRange = 1;
    char number[5001] = { NULL };
    cin >> number;
    int size = 0;
    while (!(number[size] == NULL))
    {
        if (!('0' <= number[size] && number[size] <= '9'))
        {
            isRange = 0;
            break;
        }
        size++;

    }
    if ((isRange == 0 && number[size] != NULL))
        printf("0");
    
    else
    {
        printf("%d", code_case(number, size) % MOD);
    }
    

}

