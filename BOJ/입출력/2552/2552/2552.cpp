// 2552.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    int num;
    cin >> num;
    string line;

    getline(cin, line);

    getline(cin, line);

    istringstream ss(line);
    string buffer;
    while (getline(ss, buffer, " "))
    {

    }
    return 0;
}
