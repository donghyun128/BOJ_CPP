// 11720.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
	int input;
	string s;
	cin >> input;
	cin >> s;
	int result=0;
	for (int i = 0; i <input; i++) {
		result = result+ (s[i]-'0');
	}

	printf("%d", result);

	return 0;


}
