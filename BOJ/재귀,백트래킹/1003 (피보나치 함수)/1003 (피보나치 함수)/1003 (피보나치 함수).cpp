// 1003 (피보나치 함수).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
int zero_cnt[41];
int one_cnt[41];

void fibonacci(int n) {
   
    for (int i = 2; i <= n; i++)
    {
        zero_cnt[i] = zero_cnt[i - 2] + zero_cnt[i - 1];
        one_cnt[i] = one_cnt[i - 2] + one_cnt[i - 1];
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    zero_cnt[0] = 1;
    one_cnt[0] = 0;
    zero_cnt[1] = 0;
    one_cnt[1] = 1;

    int T, n;
	cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        fibonacci(n);
        printf("%d %d", zero_cnt[n], one_cnt[n]);
        printf("\n");
    }
}
