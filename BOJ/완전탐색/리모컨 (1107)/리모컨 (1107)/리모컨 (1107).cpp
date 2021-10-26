// 리모컨 (1107).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string goal;
	int n_broken;
	int current = 100;
	int possible[10] = { 1 };
	int b_count = 0;

	cin >> goal;
	cin >> n_broken;

	for (int i = 0; i < n_broken; i++)
	{
		int b;
		cin >> b;
		possible[b] = 0;
	}

	int goal_len = goal.length();

	for (int i = 0; i < goal_len; i++)
	{

	}
	
	


}

