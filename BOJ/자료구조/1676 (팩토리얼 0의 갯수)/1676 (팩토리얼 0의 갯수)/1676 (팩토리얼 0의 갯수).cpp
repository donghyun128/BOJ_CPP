// 1676 (팩토리얼 0의 갯수).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int n_5 = n / 5;
    int n_25 = n / 25;
    int n_125 = n / 125;

   
    cout << n_5 + n_25 + n_125;
}

