// 11074 (동전 0).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>
using namespace std;

int main()
{
    int N, K;
    int arr[10];
    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ans = 0;
    int div = K;

    for (int i = N - 1; i >= 0; i--)
    {
        ans += div / arr[i];
        div = div % arr[i];
    }

    printf("%d", ans);

}

