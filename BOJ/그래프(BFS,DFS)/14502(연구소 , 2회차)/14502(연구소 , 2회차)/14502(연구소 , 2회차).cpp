#include <iostream>
#include <queue>
using namespace std;



// N : y축 , M : x축
int N, M;

// 0 : 빈 칸 , 1 : 벽 , 2 : 바이러스
int zone[8][8];
int zone_tmp[8][8] = { 0 };

// 동서남북 순서
int dy[] = {0,0,-1,1};
int dx[] = { 1,-1,0,0 };


int ans = 0;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> zone[i][j];
			zone_tmp[i][j] = zone[i][j];

			

		}
	}
}

void spread_bfs()
{
	bool visited[8][8] = { false };
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			zone_tmp[i][j] = zone[i][j];
			if (zone_tmp[i][j] == 2)
				q.push(make_pair(i, j));

		}
	}

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		visited[cy][cx] = true;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
			{
				if (zone_tmp[ny][nx] == 0)
				{
					if (!visited[ny][nx])
					{
						zone_tmp[ny][nx] = 2;
						q.push(make_pair(ny, nx));
					}
				}
			}
		}
	}

	int ans_tmp = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (zone_tmp[i][j] == 0)
				ans_tmp++;
		}
	}

	ans = max(ans_tmp, ans);
}

void setWall(int cnt)
{
	if (cnt == 3)
	{
		spread_bfs();
	}

	else
	{
		for (int i = 0; i < N; i++)
		{
			for (int j=0; j<M; j++)
			{
				if (zone[i][j] == 0)
				{
					zone[i][j] = 1;
					setWall(cnt + 1);
					
					zone[i][j] = 0;

				}
			}
		}
	}
}

void solution()
{
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (zone[i][j] == 0)
			{
				zone[i][j] = 1;
				setWall(1);
				zone[i][j] = 0;
			}
		}
	}

	cout << ans << "\n";

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();
}