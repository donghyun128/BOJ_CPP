// 11057 (오르막 수).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#define mod 10007
using namespace std;
long long int d[1001][10];

int func(int N)
{
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                d[i][j] += d[i - 1][k];
                d[i][j] = d[i][j] % mod;
            }
        }
        
    }
    
    int ret = 0;

    for (int i = 0; i < 10; i++)
    {
        ret += d[N][i];
    }

    return ret % mod;
}



int main()
{
    int N;
    cin >> N;

    for (int i = 0; i <10; i++)
    {
       d[1][i] = 1;
    }

    printf("%lld", func(N));
}
