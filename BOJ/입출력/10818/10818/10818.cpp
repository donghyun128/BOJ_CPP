// 10818.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
    int max = -1000001;
    int min = 1000001;
    int input;
    scanf_s("%d", &input);
    int data;
    for (int i = 0; i < input; i++)
    {
        scanf_s("%d", &data);
        if (data < min) {
            min = data;
        }
        if (data > max) {
            max = data;
        }

        
    }
    printf("%d %d", min, max);
}

