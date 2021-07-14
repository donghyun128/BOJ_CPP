#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int map[101][101] = { 0 };
int visited[101][101] = { 0 };
int dist[101][101] = { 0 };
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
queue<int> qy;
queue<int> qx;

void bfs(int y, int x)
{
	visited[y][x] = 1;
	dist[y][x] = 1;
	qy.push(y);
	qx.push(x);

	while (!qy.empty() && !qx.empty())
	{
		int curY = qy.front();
		int curX = qx.front();
		qy.pop();
		qx.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			if (map[nextY][nextX] == 1 && visited[nextY][nextX] == 0)
			{
				qy.push(nextY);
				qx.push(nextX);
				visited[nextY][nextX] = 1;
				dist[nextY][nextX] = dist[curY][curX] + 1;
			}
		}

	}
}

int main()
{
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	memset(dist, 0, sizeof(dist));
	int N, M;
	char col[101];
	cin >> N >> M; 

	for (int i = 1; i <= N; i++)
	{
		cin >> col;
		for (int j = 0; j < M; j++)
		{
			map[i][j+1] = col[j] - '0';
		}
	}

	bfs(1, 1);
	printf("%d", dist[N][M]);

}