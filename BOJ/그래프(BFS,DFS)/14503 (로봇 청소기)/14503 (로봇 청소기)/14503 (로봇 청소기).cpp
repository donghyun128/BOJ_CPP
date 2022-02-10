// 14503 (로봇 청소기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.


// 0 : 북쪽 , 1 : 동쪽 , 2 : 남쪽 , 3 : 서쪽
#include <iostream>
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

#define GO_FRONT 2
#define GO_BACK 1
#define STOP 0
#define NOTHING -1

using namespace std;

int N, M;
int zone[50][50] = { 0 };
bool visited[50][50] = { false };
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1};

typedef struct robot
{
	int x;
	int y;
	int dir;
} Robot;


void clean(struct robot* r)
{
	visited[r->y][r -> x] = true;

}

void move(struct robot* r)
{
	int ny;
	int nx;

	switch (r->dir)
	{
	case (NORTH):
	{
		ny = r->y - 1;
		nx = r->x;

		if (zone[ny][nx] != 1)
		{
			r->y = ny;
			r->x = nx;
		}

		break;
	}

	case (EAST):
	{
		ny = r->y ;
		nx = r->x + 1;

		if (zone[ny][nx] != 1)
		{
			r->y = ny;
			r->x = nx;
		}

		break;
	}

	case (SOUTH):
	{
		ny = r->y + 1;
		nx = r->x;

		if (zone[ny][nx] != 1)
		{
			r->y = ny;
			r->x = nx;
		}
		break;
	}

	case (WEST):
	{
		ny = r->y;
		nx = r->x - 1;

		if (zone[ny][nx] != 1)
		{
			r->y = ny;
			r->x = nx;
		}
		break;
	}

	default:
		break;
	}

}

int checkLeftAndRotate(struct robot *r)
{
	int ry = r->y;
	int rx = r->x;
	int rd = r->dir;

	int ny;
	int nx;

	// 청소기가 보고 있는 방향에 따라 왼쪽 타일 상태를 체크
	// 왼쪽으로 이동 가능하면 회전시키고 1 return , 불가하면 0을 return
	switch (r->dir)
	{
		int isMovable;

		case (NORTH) :
		{
			ny = ry;
			nx = rx - 1;

			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
			{
				if (!visited[ny][nx] || zone[ny][nx] == 0)
				{
					isMovable = 1;
				}
			}
			else
				isMovable = 0;

			r->dir = WEST;
			return isMovable;
		}

		case (EAST):
		{
			ny = ry + 1;
			nx = rx;
			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
			{
				if (!visited[ny][nx] || zone[ny][nx] == 0)
				{
					isMovable = 1;
				}
			}
			else
				isMovable = 0;

			r->dir = NORTH;
			return isMovable;

		}case (SOUTH):
		{
			ny = ry;
			nx = rx + 1;
			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
			{
				if (!visited[ny][nx] || zone[ny][nx] == 0)
				{
					isMovable = 1;
				}
			}
			else
				isMovable = 0;

			r->dir = EAST;
			return isMovable;
		}case (WEST):
		{
			ny = ry - 1;
			nx = rx;
			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
			{
				if (!visited[ny][nx] || zone[ny][nx] == 0)
				{
					isMovable = 1;
				}
			}
			else
				isMovable = 0;

			r->dir = SOUTH;
			return isMovable;

		}
		default:
		{
			return 0;
		}
	}

}

int checkAllDirection(struct robot* r)
{
	int ry = r->y;
	int rx = r->x;
	int ny;
	int nx;
	int cnt = 0;

	for (int i = 0; i < 4; i++)
	{
		int isLeftAccessible = checkLeftAndRotate(r);

		if (isLeftAccessible)
		{
			move(r);
			clean(r);
			return GO_FRONT;
		}

		cnt += isLeftAccessible;

	}

	if (cnt == 0)
	{
		// 후진
		if (zone[r->y + 1][r->x] == 0)
		{
			r->y = r->y + 1;
			return GO_BACK; 
		}
		// 이동 불가 -> 정지
		else
		{
			return STOP;
		}
	}

	else
	{

		return NOTHING;
	}
}

int getClean(struct robot* r)
{
	clean(r);

	int cleanNum = 1;

	while (1)
	{
		int result = checkAllDirection(r);
		if (result == GO_FRONT)
		{
			cleanNum++;
		}

		else if (result == STOP)
		{
			break;
		}
	}

	return cleanNum;


}

int main()
{
	
	int start_y, start_x, start_d;
	
	cin >> N >> M;
	cin >> start_y >> start_x >> start_d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> zone[i][j];
		}
	}

	robot cleaner;

	cleaner.y = start_y;
	cleaner.x = start_x;
	cleaner.dir = start_d;

	cout << getClean(&cleaner);



}

