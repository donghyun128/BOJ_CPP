// 1003 (피보나치 함수).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
int zero = 0;
int one = 0;
int fibo_data[41];

void fibonacci(int n) {
    if (n == 0) {
        //printf("0");
        zero++;
        return;
    }
    else if (n == 1) {
        //printf("1");
        one++;
        return;
    }
    else {
        fibo_data[n] = fibo_data[n-1] + fibo_data[n-2];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fibo_data[0] = 0;
    fibo_data[1] = 1;

    int T, n;
	cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        fibonacci(n);
        printf("%d %d", zero, one);
        printf("\n");
        zero = 0;
        one = 0;
    }
}
