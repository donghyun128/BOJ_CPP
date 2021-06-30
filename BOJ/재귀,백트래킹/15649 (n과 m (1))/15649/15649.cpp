#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool checked[10] = {0};

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}


	for (int i = 1; i <= n; i++)
	{
		if (!checked[i])
		{
			checked[i] = 1;
			arr[k] = i ;
			func(k + 1);
			checked[i] = 0;
		}
	}
}
int main()
{
	cin >> n >> m;
	func(0);
}

