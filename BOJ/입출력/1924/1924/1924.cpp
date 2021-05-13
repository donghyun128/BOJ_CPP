// 1924.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
// ※인터넷 풀이 참고함.
#include "pch.h"
#include <string.h>
#include <iostream>
#pragma warning(disable: 4996)


int main() {
    int m_input, d_input,sum = 0;
    int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31 };
    const char* day[] = {"SUN","MON","TUE","WED","THU","FRI","SAT" };
    
    scanf("%d %d", &m_input, &d_input);
    if (m_input > 12 || d_input > 31) return 0;


    for (int i = 1; i < m_input; i++) {
        sum += month[i];
    }
    sum = sum + d_input ;
    printf("%s",day[(sum % 7)]);

    return 0;
}


// 무리한 실패작
/*
const char* day(int input)
{
    
    char* result_date = new char[10];^
    switch (input)
    {
    case 0: strcpy(result_date, "SUN"); break;
    case 1: strcpy(result_date, "MON"); break;
    case 2: strcpy(result_date, "TUE"); break;
    case 3: strcpy(result_date, "WED"); break;
    case 4: strcpy(result_date, "THU"); break;
    case 5: strcpy(result_date, "FRI"); break;
    case 6: strcpy(result_date, "SAT"); break;
    }
    return result_date;
};

int calculate(int m_input, int d_input)
{
    int m_con = NULL, stv;
    switch (m_input)
    {
    case 1: m_con = 6; break;
    case 2: m_con = 2; break;
    case 3: m_con = 2; break;
    case 4: m_con = 5; break;
    case 5: m_con = 0; break;
    case 6: m_con = 3; break;
    case 7: m_con = 5; break;
    case 8: m_con = 1; break;
    case 9: m_con = 4; break;
    case 10: m_con = 6; break;
    case 11: m_con = 2; break;
    case 12: m_con = 4; break;
    default: m_con = 10; break;
    }
    if (m_con == 10) return -1;
    stv = (1+ m_con + d_input) % 7;
    return stv;
}
int main()
{
    int month, date;
    const char* result = new char [10];
    scanf("%d %d", &month, &date);
    if (month > 12 || date > 31) return 0;
    int k = calculate(month, date);
    if (k == -1) return 0;
    result = day(k);
    printf("%s", result);
    delete [] result;

    return 0;
}
*/
