
#include <iostream>
#include <tuple>
#define UP 1
#define DOWN 2
#define RIGHT 3 
#define LEFT 4
using namespace std;

int map[101][101][4] = { 0 }; // 0 : 크기 , 1 : 속도 , 2: 방향 , 3: 이동 여부
int fisher_x = 0;
int catched_shark = 0;
int R, C, M;



void catchOneShark()
{
	fisher_x++;
	for (int i = 1; i <= R; i++)
	{
		if (map[i][fisher_x][0] !=0)
		{
			catched_shark += map[i][fisher_x][0];
			map[i][fisher_x][0] = 0;
			map[i][fisher_x][1] = 0;
			map[i][fisher_x][2] = 0;
			break;
		}
	}
}

tuple<int, int,int> moveAlgorihtm(int y, int x, int speed, int direction)
{
	if (speed == 0)
	{
		return make_tuple(y, x, direction);
	}
	int goal_y = y, goal_x = x;

	int distance = speed;
	int cur_dir = direction;

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
	return make_tuple(goal_y, goal_x, cur_dir);
}

void sharkMove()
{
	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			if (map[r][c][0] != 0 && map[r][c][3] == 0)
			{
				tuple<int, int,int> goal_pair = moveAlgorihtm(r, c, map[r][c][1], map[r][c][2]);
				
				// 상어가 겹쳤을 때 잡아먹기
					if (map[r][c][0] >= map[get<0>(goal_pair)][get<1>(goal_pair)][0])
					{
						map[get<0>(goal_pair)][get<1>(goal_pair)][0] = map[r][c][0];
						map[get<0>(goal_pair)][get<1>(goal_pair)][1] = map[r][c][1];
						map[get<0>(goal_pair)][get<1>(goal_pair)][2] = get<2>(goal_pair);
						map[get<0>(goal_pair)][get<1>(goal_pair)][3] = 1;
					}
				

				// 이동 후, 있었던 장소를 비움
					if (r == get<0>(goal_pair) && c == get<1>(goal_pair))
						continue;

					map[r][c][0] = 0;
					map[r][c][1] = 0;
					map[r][c][2] = 0;
					map[r][c][3] = 0;
					
				
			}
		}
	}
}

void secondProcess()
{
	catchOneShark();
	sharkMove();

	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
			map[r][c][3] = 0;
	}

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
		map[shark_r][shark_c][0] = tmp_size;
		map[shark_r][shark_c][1] = tmp_speed;
		map[shark_r][shark_c][2] = tmp_dir;
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

