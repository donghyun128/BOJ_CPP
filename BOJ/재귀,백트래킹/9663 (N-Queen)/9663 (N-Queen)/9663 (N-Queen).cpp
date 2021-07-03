#include <iostream>

using namespace std;
int n;
bool map[15][15] = { false };
int result = 0;

bool isPossible(int y, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (map[i][x] == true)
			return false;
	}

	for (int j = 0; j < n; j++)
	{
		if (map[y][j] == true)
			return false;
	}

	for (int k = 1; k < n; k++)
	{
		if (map[x + k][y + k] || map[x - k][y - k] || map[x + k][y - k] || map[x - k][y + k])
			return false;
	}

	return true;

}

void dfs(int k)
{
	if (n == k)
	{
		result++;
		return;
	}

	for (int i = 0; i < n; i++)
	{


			if (map[i][k] == false && isPossible(i, k))
			{
				map[i][k] = true;
				dfs(k + 1);
				map[i][k] = false;
			}
	}

}


int main()
{
	cin >> n;
	dfs(0);
	cout << result;
}