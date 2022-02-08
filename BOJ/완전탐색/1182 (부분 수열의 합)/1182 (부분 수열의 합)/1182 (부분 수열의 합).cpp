// 1182 (부분 수열의 합).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.


#include <iostream>
using namespace std;
int arr[20];
int ans = 0;
void func(int n, int s, int start, int sum)
{
	int c_sum = 0;

	for (int i = start; i < n; i++)
	{
		c_sum = sum + arr[i];
		if (c_sum == s)
		{
			ans++;
			return;
		}
		else
		{
			func(n, s - c_sum, i + 1, c_sum);
		}
	}
}


int main()
{
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	func(n, s, 0, 0);

	cout << ans;
}

