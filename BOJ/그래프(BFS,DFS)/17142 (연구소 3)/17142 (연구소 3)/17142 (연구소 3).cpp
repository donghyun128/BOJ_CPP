
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
#define MAX 100000000
using namespace std;

struct node
{
	int y, x;
};

vector<node> virus_vector;
queue<node> q;

int N, M;
int map[51][51] = { 0 };
int map_tmp[51][51] = { 0 };
int visitedTime[51][51];
bool check[10] = { 0 };
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int ans = MAX;
int emptyCnt = 0;

bool bfs()
{
	int infectCnt = 0;
	int time = 0;

	while (!q.empty())
	{
		int cy = q.front().y;
		int cx = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
			if (map[ny][nx] != 1 && visitedTime[ny][nx] == -1)
			{
				visitedTime[ny][nx] = visitedTime[cy][cx] + 1;
				if (map[ny][nx] == 0)
				{
					infectCnt++;
					time = visitedTime[ny][nx];
				}
				q.push({ ny,nx });
			}

		}
	}
	
	if (infectCnt != emptyCnt)
		return false;


	ans = min(time, ans);
	return true;
}

void combination(int idx, int cnt)
{
	if (cnt == M)
	{
		memset(visitedTime, -1, sizeof(visitedTime));
		for (int k = 0; k < virus_vector.size(); k++)
		{
			if (check[k])
			{
				visitedTime[virus_vector[k].y][virus_vector[k].x] = 0;
				q.push({ virus_vector[k].y , virus_vector[k].x });
			}
		}
		bfs();
		return;
	}
	else
	{
		for (int i = idx; i < virus_vector.size(); i++)
		{
			if (check[i]) continue;
			check[i] = true;
			combination(i + 1, cnt + 1);
			check[i] = false;
		}

	}
}

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0) emptyCnt++;
			else if (map[i][j] == 2) virus_vector.push_back({ i,j });
		}
	}
	memset(visitedTime, -1, sizeof(visitedTime));
}

void solution()
{
	input();
	combination(0,0);
	if (ans == MAX) cout << -1;
	else cout << ans;

}
int main()
{
	solution();
}
