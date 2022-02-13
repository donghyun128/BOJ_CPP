#include <iostream>
#include <queue>
using namespace std;



// N : y축 , M : x축
int N, M;

// 0 : 빈 칸 , 1 : 벽 , 2 : 바이러스
int zone[8][8];
int zone_tmp[8][8] = { 0 };
int wallVisited[64] = { 0 };

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

void copyArr(int dst[][8], int src[][8])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			dst[i][j] = src[i][j];
		}
	}
}

int countSafeZone()
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (zone_tmp[i][j] == 0)
			{
				cnt++;
			}
		}
	}
	return cnt++;
}

void bfs()
{
	int visited[8][8] = { 0 };
	queue<pair<int,int>> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (zone_tmp[i][j] == 2)
			{
				q.push(make_pair(i, j));
			}

		}
	}

	while (!q.empty())
	{
		
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		visited[cy][cx] = 1;


		for (int r = 0; r < 4; r++)
		{
			int ny = cy + dy[r];
			int nx = cx + dx[r];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
			{
				if (visited[ny][nx] == 0)
				{
					if (zone_tmp[ny][nx] == 0)
					{
						zone_tmp[ny][nx] = 2;
						q.push(make_pair(ny, nx));

					}
				}
			}

		}
	}
}

void setWall(int wall_cnt)
{
	int zone_recur[8][8] = { 0 };
	copyArr(zone_recur, zone_tmp);

	if (wall_cnt == 3)
	{
		bfs();
		int ans_tmp = countSafeZone();
		ans = max(ans_tmp, ans);
	}

	else {
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j])
			}
		}
	}
	copyArr(zone_tmp, zone_recur);

}

void solution()
{
	setWall(0);
	cout << ans << endl;
}






int main()
{
	input();
	solution();


}