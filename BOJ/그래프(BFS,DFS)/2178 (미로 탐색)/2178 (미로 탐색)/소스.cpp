#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[101][101] = { 0 };
int visited[101][101] = { 0 };
queue<int,int> q;

void bfs(int y, int x)
{
	visited[y][x] = 1;
	q.push((y, x));

	while (!q.empty())
	{

	}
}

int main()
{
	int N, M;
	char col[101];
	cin >> N >> M; 

	for (int i = 1; i <= N; i++)
	{
		cin >> col;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = col[j] - '0';
		}
	}



}