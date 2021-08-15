#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[1001];
	int D[1001] = {0};
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	arr[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		int m_length = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				m_length = max(D[j] + 1, m_length);
			}
		}
		D[i] = m_length;
	}
	int max = 0;
	for (int i = 0; i <= N; i++)
	{
		if (D[i] > max)
			max = D[i];
	}
	printf("%d", max);
}
