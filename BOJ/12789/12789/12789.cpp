// 12789.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> s;
	int student;// student : 앞에 있는 학생 수
	int line[1001];
	int get = 1;
	cin >> student;

	for (int i = 1; i <= student; i++)
	{
		cin >> line[i];
	}

	for (int i = 1; i <= student; i++)
	{
		s.push(line[i]);
		if (line[i] == get)
		{
			get++;
			s.pop();
		}
		while(!s.empty() && s.top() == get)
		{
			s.pop();
			get++;

		}
		
	}
	if (s.empty()) printf("Nice");
	else printf("Sad");

	return 0;

}

