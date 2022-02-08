#include <iostream>
using namespace std;

int x[16];
int n;
int cnt = 0;

bool possible(int level)
{
	for (int i = 0; i < level; i++)
	{
		if ((x[i] == x[level]) || (abs(x[level] - x[i]) == level - i))
			return false;

	}
	return true;
}
void func(int cur)
{
	if (cur == n) {
		cnt++;
	}

	else
	{
		for (int i = 0; i < n; i++)
		{
			x[cur] = i;
			if (possible(cur))
			{
				func(cur + 1);
			}
		}
	}

}
int main()
{
	cin >> n;
	func(0);
	cout << cnt;
}