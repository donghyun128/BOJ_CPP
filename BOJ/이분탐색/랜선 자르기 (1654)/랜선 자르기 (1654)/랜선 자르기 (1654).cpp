#include <iostream>
using namespace std;


int func(int wlan[], int k,int n , long long maxlan)
{
	long long left = 1;
	long long right = maxlan;
	long long mid = (left + right) / 2;
	int answer = 0;
	int tmp = 0;
	while (left <= right)
	{
		int n_split = 0;
		mid = (left + right) / 2;
		for (int i = 1; i <= k; i++)
		{
			n_split += wlan[i] / mid;
		}

		if (n_split >= n)
		{
			answer = mid;
			left = mid + 1;
		}

		else if (n_split < n)
		{
			right = mid - 1;
		}


	
	}
	return answer;
}


int main()
{
	int k, n;
	int wlan[10001];
	long long maxlan = 0;
	cin >> k >> n;
	for (int i = 1; i <= k; i++)
	{
		cin >> wlan[i];
		if (maxlan < wlan[i])
			maxlan = wlan[i];
	}

	int answer = func(wlan, k, n, maxlan);
	printf("%d", answer);

}
