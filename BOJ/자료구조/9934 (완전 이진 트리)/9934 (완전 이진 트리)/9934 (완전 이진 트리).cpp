// 9934 (완전 이진 트리).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <math.h>
using namespace std;
int city[1023] = { 0 };
bool checked[1023] = { 0 };
int main()
{
    int k;
    cin >> k;
    int p = pow(2, k) - 1;
    for (int i = 0; i<p; i++)
        cin >> city[i];

   checked[p / 2] = 1;
   printf("%d\n", city[p / 2]);

    for (int l = k-1; l > 1; l--)
    {
        for (int i = 0; i < p; i++)
        {
            int mod = i % ((int)pow(2, l-1));
            if ((mod == (int)(pow(2, l - 1)) - 1) && checked[i] == 0)
            {
                checked[i] = 1;
                printf("%d ", city[i]);
            }
        }
        printf("\n");
    }
    for (int i = 0; i < p; i+=2)
    {
     
            printf("%d ", city[i]);
    }
}

