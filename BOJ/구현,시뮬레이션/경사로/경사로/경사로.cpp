#include <iostream>
using namespace std;
int N, L;
int road[100][100] = { 0 };



void solution()
{
	int cy;
	int cx;
	int cnt = 1;
	for (int i = 0; i < N; i++)
	{
		cy = i;
		for (int j = 0; j < N; j++)
		{
			cx = j;
			if (road[cy][j + 1] == road[cy][j])
				continue;
			else if (abs(road[i][j] - road[i][j+1]) == 1)
			{
				for (int k = j + 1; k < N-1; k++)
				{
					if ()
				}
			}
		}
	}
}


void input()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> road[i][j];
		}
	}
}

int main()
{
}

