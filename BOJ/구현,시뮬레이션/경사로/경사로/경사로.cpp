#include <iostream>
using namespace std;
int N, L;
int road[100][100] = { 0 };


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

