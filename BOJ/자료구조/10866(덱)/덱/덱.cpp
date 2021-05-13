// 덱.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.


#include <iostream>
#include <string>
#include <deque> 
using namespace std;

int main(int argc, char** argv) {

	deque<int> dq;
	int input;
	char c[10000];
	string s;
	scanf_s("%d", &input);

	for (int i = 1; i <= input; i++)
	{
		//scanf_s("%s", c);
		//s = c;
		cin >> s;
		if (s == "push_front")
		{
			int n;
			scanf_s("%d", &n);
			dq.push_front(n);
		}

		else if (s == "push_back")
		{
			int n;
			scanf_s("%d", &n);
			dq.push_back(n);
		}

		else if (s == "pop_front")
		{
			if (!dq.empty())
			{
				printf("%d\n", dq.front());
				dq.pop_front();

			}
			else printf("-1\n");
		}

		else if (s == "pop_back")
		{
			if (!dq.empty())
			{
				printf("%d\n", dq.back());
				dq.pop_back();
			}
			else printf("-1\n");
		}

		else if (s == "size")
		{
			printf("%d\n", dq.size());
		}

		else if (s == "empty")
		{
			printf("%d\n", dq.empty());
		}

		else if (s == "front")
		{
			if (!dq.empty())
			{
				printf("%d\n", dq.front());
			}
			else printf("-1\n");
		}

		else if (s == "back")
		{
			if (!dq.empty())
			{
				printf("%d\n", dq.back());
			}
			else printf("-1\n");
		}

	}

	return 0;
}