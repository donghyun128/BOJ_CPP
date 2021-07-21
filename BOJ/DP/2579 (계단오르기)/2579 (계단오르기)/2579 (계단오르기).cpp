#include <iostream>
#include <algorithm>
using namespace std;

int score[301] = { 0 };
int sum[301] = { 0 };
int cal(int n)
{
	for (int i = 3; i<=n; i++)
	{
		int tmp;
		tmp = max(sum[i - 3] + score[i - 1] + score[i], sum[i - 2] + score[i]);
		sum[i] = tmp;
	}
	return sum[n];
}


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> score[i];
	}
	sum[1] = score[1];
	sum[2] = score[1] + score[2];

	printf("%d", cal(n));
}

