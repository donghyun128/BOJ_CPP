// 8393.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
    int input;
    scanf("%d", &input);
    int sum= 0;
    for (int i = 1; i <= input; i++) {
        sum += i;
    }
    printf("%d", sum);
    return 0;
    
}
