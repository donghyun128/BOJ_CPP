// 1931 (회의실 배정).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int n;
	pair<int, int> c[100001];

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> c[i].second >> c[i].first;
	}

	sort(c + 1, c + n+1);

	int ret = 0;
	int t = 0;
	for (int i = 1; i <= n; i++)
	{
		if (t > c[i].second)
			continue;

		t = c[i].first;
		ret++;
		//cout << c[i].second << " " << c[i].first << endl;
	}
	cout << ret;
}

