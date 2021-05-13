// 10991.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int input;
    scanf_s("%d", &input);

    for (int i = 1; i <= input; i++) {
        for (int j = 1; j <= input -i; j++)
            printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j % 2 == 1) printf("*");
            else printf(" ");

        }
        printf("\n");
    }
    return 0;
}
