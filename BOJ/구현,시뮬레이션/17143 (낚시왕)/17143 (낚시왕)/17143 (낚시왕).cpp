
#include <iostream>
#include <tuple>
#include <queue>
#define UP 1
#define DOWN 2
#define RIGHT 3 
#define LEFT 4
using namespace std;

typedef struct shark
{
	int y;
	int x;
	int size;
	int speed;
	int dir;
	int num;
} shark;

vector<shark> map[101][101]; // 0 : 크기 , 1 : 속도 , 2: 방향 , 3: 이동 여부
vector<shark> map_tmp[101][101];
int fisher_x = 0;
int catched_shark = 0;
int R, C, M;
vector<shark> shark_v;

void copyMap()
{
	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			if (!map_tmp[r][c].empty())
			{
				for (int s = 0; s < map_tmp[r][c].size(); s++)
				{
					struct shark shark_tmp = map_tmp[r][c][s];
					map[shark_tmp.y][shark_tmp.x].push_back(shark_tmp);
				}

			}
		}
	}
}

void clearMap()
{
	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			if (!map[r][c].empty())
			{
				map[r][c].clear();
			}
		}
	}
}

void clearMapTmp()
{
	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			if (!map_tmp[r][c].empty())
			{
				map_tmp[r][c].clear();
			}
		}
	}
}


void catchOneShark()
{
	fisher_x++;
	for (int i = 1; i <= R; i++)
	{
		if (!map[i][fisher_x].empty())
		{
			catched_shark += map[i][fisher_x][0].size;
			map[i][fisher_x].pop_back();
			break;
		}
	}
}

void moveAlgorihtm(int y,int x)
{
	struct shark cur_shark = map[y][x][0];
	struct shark tmp_shark;

	int goal_y = cur_shark.y, goal_x = cur_shark.x;
	int distance = cur_shark.speed;
	int cur_dir = cur_shark.dir;
	
	while (distance != 0)
	{
		distance--;
		switch (cur_dir)
		{
		case UP:
		{
			if (goal_y - 1 < 1)
			{
				goal_y++;
				cur_dir = DOWN;
			}
			else
				goal_y--;
			break;
		}
		case DOWN:
		{
			if (goal_y + 1 > R)
			{
				goal_y--;
				cur_dir = UP;
			}
			else
				goal_y++;
			break;
		}
 		case RIGHT:
		{
			if (goal_x + 1 > C)
			{
				goal_x--;
				cur_dir = LEFT;
			}
			else
				goal_x++;
			break;
		}
		case LEFT:
		{
			if (goal_x - 1 < 1)
			{
				goal_x++;
				cur_dir = RIGHT;
			}
			else
				goal_x--;
			break;
		}
		}
	}

	tmp_shark.y = goal_y;
	tmp_shark.x = goal_x;
	tmp_shark.size = cur_shark.size;
	tmp_shark.dir = cur_dir;
	tmp_shark.speed  = cur_shark.speed;

	//map[y][x].pop_back();
	map_tmp[goal_y][goal_x].push_back(tmp_shark);

}

void eatShark(int y, int x)
{
	struct shark tmp_shark;
	int max = 0;
	int max_idx = -1;
	for (int s = 0; s < map_tmp[y][x].size(); s++)
	{
		if (map_tmp[y][x][s].size > max)
		{
			max_idx = s;
			max = map_tmp[y][x][s].size;
		}
	}

	tmp_shark.y = map_tmp[y][x][max_idx].y;
	tmp_shark.x = map_tmp[y][x][max_idx].x;
	tmp_shark.size = map_tmp[y][x][max_idx].size;
	tmp_shark.dir = map_tmp[y][x][max_idx].dir;
	tmp_shark.speed = map_tmp[y][x][max_idx].speed;
	tmp_shark.num = map_tmp[y][x][max_idx].num;

	map_tmp[y][x].clear();
	map_tmp[y][x].push_back(tmp_shark);
}

void sharkMove()
{
	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			if (!map[r][c].empty())
			{
				moveAlgorihtm(r, c);
			}
		}
	}

	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			if (map_tmp[r][c].size() >= 2)
				eatShark(r,c);
		}
	}
}

void secondProcess()
{
	catchOneShark();
	sharkMove();
	clearMap();
	copyMap();
	clearMapTmp();
}

void fishing()
{
	for (int x = 1; x <= C; x++)
	{
		secondProcess();
	}

	cout << catched_shark;
}

void input()
{
	int shark_r, shark_c, tmp_size, tmp_speed, tmp_dir;
	cin >> R >> C >> M;

	for (int m = 0; m < M; m++)
	{
		cin >> shark_r >> shark_c >> tmp_speed >> tmp_dir >> tmp_size;
		struct shark tmp_shark;

		tmp_shark.y = shark_r;
		tmp_shark.x = shark_c;
		tmp_shark.speed = tmp_speed;
		tmp_shark.dir = tmp_dir;
		tmp_shark.size = tmp_size;
		tmp_shark.num = m;

		shark_v.push_back(tmp_shark);
		map[shark_r][shark_c].push_back(tmp_shark);
	}
}

void solution()
{
	input();
	fishing();
}

int main()
{
	solution();
}

