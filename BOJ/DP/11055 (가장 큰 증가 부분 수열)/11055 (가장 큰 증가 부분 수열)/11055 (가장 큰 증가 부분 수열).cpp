// 11055 (가장 큰 증가 부분 수열).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int S[1001];


int main()
{
    int N;
    cin >> N;
    arr[0] = 0;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        int tmp = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                sum = max(sum, S[j] + arr[i]);
            }
        }
        S[i] = sum;
    }

    int max = 0;
    for (int i = 1; i <= N; i++)
    {
        if (S[i] > max)
            max = S[i];
    }
    printf("%d", max);
}


