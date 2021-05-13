// 2741.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
int main()
{
    int input;
    scanf_s("%d", &input);
    for (int i = 0; i < input; i++) {
        printf("%d",i+1);
        printf("\n");
    }
    return 0;
}

