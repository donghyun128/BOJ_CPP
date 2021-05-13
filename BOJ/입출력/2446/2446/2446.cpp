#include "pch.h"
#include <iostream>

int main()
{
    int input;
    scanf_s("%d", &input);

    for (int i = 0; i < 2 * input ; i++)
    {
        if (i < input)
        {
            for (int j = 0; j < i; j++)
                printf(" ");
            for (int j = 0; j < 2 * (input - i)-1; j++)
                printf("*");
            printf("\n");
        }

        if (i > input)
        {
            for (int j = 0; j < 2 * (input) - i-1; j++)
                printf(" ");
            for (int j = 0; j < 2 * (i - input)+1; j++)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}
