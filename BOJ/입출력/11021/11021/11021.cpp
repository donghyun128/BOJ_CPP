// 11021.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
int main()
{
    int input;
    int n1, n2;
    cin >> input;
    for (int i = 1; i <= input; i ++ ) {
        cin >> n1 >> n2;
        printf("Case #%d: %d \n", i, n1 + n2);
    }
    return 0;
}

