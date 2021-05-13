// 10953.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	int input;
	int n1, n2;
	char c;
	cin >> input;
	for (int i = 1; i <= input; i++)
	{
		cin >> n1 >> c >> n2;
		cout << n1 + n2 << endl;
	}
	return 0;
}

