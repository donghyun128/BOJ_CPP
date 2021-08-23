// 1931 (회의실 배정).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	pair<int, int> arr[100001];
	int ans = 0;
	int st = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].second >> arr[i].first;
	}

	sort(arr + 1, arr + n);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ~ %d \n ", arr[i].second, arr[i].first);
	}



	for (int i = 1; i <= n; i++)
	{
		if (st > arr[i].second)
			continue;
		ans++;
		st = arr[i].first;
	}




}

