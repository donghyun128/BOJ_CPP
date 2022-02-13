#include <iostream>
#include <queue>

using namespace std;
int N, M;
int map[9][9] = {0};
int map_infected[9][9] = { 0 };

bool wall_visited[3] = { false };
// 0 : 빈칸 , 1 : 벽, 2 : 바이러스
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int ans = 0;

void copyMap(int (*dst)[9],int (*src)[9])
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			dst[i][j] = src[i][j];
		}
	}
}
int safeZone_score(int map_infected[][9])
{
	int result = 0;
	{
		for (int n = 1; n <= N; n++)
		{
			for (int m = 1; m <= M; m++)
			{
				if (map_infected[n][m] == 0)
				{
					result++;
				}
			}
		}
	}
	return result;
}

void virus_BFS()
{
	queue<pair<int, int>> q;
	int map_tmp[9][9] = { 0 };
	bool visited[9][9] = { false };
	
	for (int n = 1; n <= N; n++)
	{
		for (int m = 1; m <= M; m++)
		{
			map_tmp[n][m] = map_infected[n][m];
		}
	}
	
	for (int n = 1; n <= N; n++)
	{
		for (int m = 1; m <= M; m++)
		{
			if (map_tmp[n][m] == 2)
			{
				q.push(make_pair(n, m));
			}
		}
	}


	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny >= 1 && ny <= N && nx >= 1 && nx <= M)
			{
				if (map_tmp[ny][nx] == 0)
				{
					map_tmp[ny][nx] = 2;
					q.push(make_pair(ny, nx));
				}
			}
		}

	}

	int result_tmp = safeZone_score(map_tmp);
	ans = max(result_tmp, ans);


}

void setWall_recursive(int cnt)
{
	if (cnt == 3)
	{
		//bool virus_visited[9][9] = { false };
		virus_BFS();
		return;
	}

	else
	{
		for (int n = 1; n <= N; n++)
		{
			for (int m = 1; m <= M; m++)
			{
				if (map_infected[n][m] == 0)
				{
					map_infected[n][m] = 1;
					
					setWall_recursive(cnt + 1);

					map_infected[n][m] = 0;

				}
			}
		}
	}

}


int main()
{

	cin >> N >> M;

	for (int n = 1; n <= N; n++)
	{
		for (int m = 1; m <= M; m++)
		{
			cin >> map[n][m];
			map_infected[n][m] = map[n][m];
		}
	}

	for (int n = 1; n <= N; n++)
	{
		for (int m = 1; m <= M; m++)
		{
			if (map[n][m] == 0)
			{
				copyMap(map_infected, map);
				map[n][m] = 1;
				setWall_recursive(1);
				map[n][m] = 0;
			}

		}
	}

	cout << ans;

}

