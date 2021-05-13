// 2438.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

int main()
{
    int rep = 0;

    scanf_s("%d", &rep);

    for (int i = 0; i < rep; ++i)
    {
        for (int j = 0; j < i + 1; j++) {
            printf("*");
            
        }
        printf("\n");
    }
    return 0;
}

