// 10828(스택).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

// 스택 라이브러리

/*
  선언: stack<자료형> 변수명
  추가 : 변수명.push(element)
  삭제 : 변수명.pop()
  찾기 : 변수명.top() : top의 원소 반환
  empty() : 스택이 비어있으면 TRUE , 아니면 FALSE
  size() : 스택 사이즈 반환
*/

// 씨발!!!... 왜 이런지는 모르겠는데... if(s.empty())쓰면 NZEC 런타임 에러 뜬다... if(!s.empty()) 써야 런타임 안뜬다....
#include <stack>
#include <iostream>
#include <string>
using namespace std;

stack<int> s;

int main()
{
	int input;
	cin >> input;
	string op;
	for (int i = 1; i <= input; i++) {
		cin >> op;
		if (op == "push")
		{
			int n;
			cin >> n;
			s.push(n);
		}

		else if (op == "pop")
		{
			if (!s.empty())
			{
				cout << s.top() << endl; s.pop();
			}		
			else cout << "-1" << endl;
		}

		else if (op == "size")
		{
			cout << s.size() << endl;
		}

		else if (op == "empty")
		{
			if (s.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (op == "top")
		{
			if (!s.empty()) 
			{
				cout << s.top() << endl;
			} 

			else cout << "-1" << endl;
		}
	}
	return 0;
}

