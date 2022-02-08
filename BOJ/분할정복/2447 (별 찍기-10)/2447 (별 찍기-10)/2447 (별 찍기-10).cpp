// 2447 (별 찍기-10).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
using namespace std;

void printStar()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                printf(" ");
            else
                printf("*");
        }
            //printf("\n");
    }
    printf("***");
}

void printEmpty(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}

void printWhole(int size)
{

    int div_size = size / 3;

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            if (i % 3 == 2 && j % 3 == 2)
            {
                printf(" ");
            }
            else
            {
                printWhole(div_size);
                printf("*");
            }
        }
        printf("\n");
    }

}

int main()
{
    //printStar();

    int N;
    cin >> N;

    printWhole(N);
}


