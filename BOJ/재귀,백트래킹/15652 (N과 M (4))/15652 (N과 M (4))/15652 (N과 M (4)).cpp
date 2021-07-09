#include <iostream>
using namespace std;

int n, m;
int arr[8];

void function(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m - 1; i++)
		{
			if (arr[i] > arr[i + 1])
				return;
		}

		for (int i = 0; i < m; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		arr[k] = i + 1;
		function(k + 1);
	}
}
int main()
{
	cin >> n >> m;
	function(0);
}

