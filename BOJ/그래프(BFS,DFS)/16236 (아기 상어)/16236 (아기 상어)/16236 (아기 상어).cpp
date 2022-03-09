#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
int N;
int map[20][20] = { 0 };
int dy[4] = {-1,0,1,0};
int dx[4] = {0,-1,0,1};
int shark_size = 2;
int fed = 0;
int times = 0;
int cur_shark_y = 0;
int cur_shark_x = 0;


queue<tuple<int, int, int>> fish_q;


void bfs(int y,int x)
{
	bool visited[20][20] = { false };
	queue<tuple<int, int,int>> q;

	visited[y][x] = true;
	q.push(make_tuple(y, x, 0));
	
	while (!q.empty())
	{
		int cy = get<0>(q.front());
		int cx = get<1>(q.front());
		int cd = get<2>(q.front());
		q.pop();
		

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N && !visited[ny][nx])
			{
				if (map[ny][nx] <= shark_size)
				{
					visited[ny][nx] = 1;
					q.push(make_tuple(ny, nx,cd+1));
					if (map[ny][nx] < shark_size && map[ny][nx] > 0)
					{
						fish_q.push(make_tuple(ny, nx, cd+1));
					}
				}
				
			}
		}
	}
}

bool compareAmongSameDistance()
{
	if (!fish_q.empty())
	{
		int y = get<0>(fish_q.front());
		int x = get<1>(fish_q.front());
		int d = get<2>(fish_q.front());
		fish_q.pop();

		while (!fish_q.empty())
		{
			int ny = get<0>(fish_q.front());
			int nx = get<1>(fish_q.front());
			int nd = get<2>(fish_q.front());
			fish_q.pop();

			if (nd < d)
			{
				y = ny;
				x = nx;
				d = nd;
			}
			else if (nd == d)
			{
				if (ny < y)
				{
					y = ny;
					x = nx;
					d = nd;
				}
				else if (ny == y)
				{
					if (nx < x)
					{
						y = ny;
						x = nx;
						d = nd;
					}
				}
			}
		}
		map[y][x] = 0;
		cur_shark_y = y;
		cur_shark_x = x;
		times += d;
		fed++;

		return true;
	}

	else
	{
		return false;
	}
}


void getFish()
{
	while (1)
	{
		bfs(cur_shark_y, cur_shark_x);
		if (!compareAmongSameDistance())
			return;
		if (fed == shark_size)
		{
			shark_size++;
			fed = 0;
		}
	}
}

void solution()
{
	getFish();
	cout << times;
}
void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				cur_shark_y = i;
				cur_shark_x = j;
				map[i][j] = 0;
			}
		}
	}
}

int main()
{
	input();
	solution();
}

