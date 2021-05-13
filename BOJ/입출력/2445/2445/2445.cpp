// 2445.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

int main()
{
    int input;;
    scanf_s("%d",&input);

    for (int i = 0; i < 2 * input ; i++)
    {
        if (i < input) {
            for (int j = 0; j < i + 1; j++)
                printf("*");
            for (int j = 0; j < 2 * (input - i-1); j++)
                printf(" ");
            for (int j = 0; j < i + 1; j++)
                printf("*");

            printf("\n");
        }

        if (i >input)
        {
            for (int j = 0; j < 2 * input - i; j++)
                printf("*");
            for (int j = 0; j < 2 * (i - input); j++)
                printf(" ");
            for (int j = 0; j < 2 * input - i; j++)
                printf("*");
            printf("\n");
        }
        
    }
    return 0;
}

