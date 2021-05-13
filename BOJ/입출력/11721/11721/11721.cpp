// 11721.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int line = s.size();

    for (int i = 0; i <s.size(); i++) {
        if (i % 10 == 0 && i>0) printf("\n");

        printf("%c", s[i]);
    }
    return 0;
}

// 랭커 코드:
/* #include<cstdio>
char s[11];
int main() {
    while (~scanf("%10s", s))puts(s);
    return 0;
}
*/