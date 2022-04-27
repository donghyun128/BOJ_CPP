#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int N, M;
int colors[20][20] = { 0 };
bool visited[20][20] = { 0 };
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int score = 0;

struct node
{
	int y, x;
};

struct group
{
	int y = -1;
	int x = -1;
	int rbwCnt = 0;
	int size = -1;
	vector<node> pos;
};

struct group bfs(int y, int x)
{
	int rbwCnt = 0;
	int size = 1;

	queue<node> q;
	bool rbwVisited[20][20] = { 0 };
	struct group result;
	result.y = y;
	result.x = x;
	result.pos.push_back({ y,x });

	q.push({ y,x });
	visited[y][x] = 1;
	rbwVisited[y][x] = 1;

	while (!q.empty())
	{
		int cy = q.front().y;
		int cx = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (!rbwVisited[ny][nx] && (colors[ny][nx] == colors[y][x] || colors[ny][nx] == 0))
			{
				if (colors[ny][nx] == 0)
				{
					rbwCnt++;
				}
				else 
				{
					visited[ny][nx] = 1;
				}

				size++;
				result.pos.push_back({ ny,nx });
				rbwVisited[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}
	result.size = size;
	result.rbwCnt = rbwCnt;
	return result;
}

struct group compareGroup(struct group A, struct group B)
{

	if (A.size > B.size)
	{
		return A;
	}
	else if (B.size > A.size)
		return B;
	else
	{
		if (A.rbwCnt > B.rbwCnt)
			return A;
		else if (B.rbwCnt > A.rbwCnt)
			return B;
		else
		{
			if (A.y > B.y)
				return A;
			else if (B.y > A.y)
				return B;
			else
			{
				if (A.x > B.x)
					return A;
				else if (B.x > A.x)
					return B;
			}
		}
	}
}

struct group findBiggestGroup()
{
	struct group result;
	struct group tmp;
	result.size = -1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j] && colors[i][j] != -1 && colors[i][j] != 0 && colors[i][j] != -2)
			{
				tmp = bfs(i,j);
				result = compareGroup(tmp, result);
			}
		}
	}
	return result;
}

void clearGroupAndGetScore(struct group Biggest)
{
	for (int i = 0; i < (int)Biggest.pos.size(); i++)
	{
		colors[Biggest.pos[i].y][Biggest.pos[i].x] = -2;
	}
	score += Biggest.size * Biggest.size;
}

void getGravity()
{
	for (int j = 0; j < N; j++)
	{
		int bottom = N - 1;

		for (int i = N - 1; i >= 0; i--)
		{
			if (colors[i][j] == -2)
				continue;
			else if (colors[i][j] == -1)
			{
				bottom = i-1;
			}
			else
			{
				int block = colors[i][j];
				colors[i][j] = -2;
				colors[bottom--][j] = block;
			}
		}
	}
}

void rotate()
{
	int colors_tmp[20][20];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			colors_tmp[N - j - 1][i] = colors[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			colors[i][j] = colors_tmp[i][j];
		}
	}

}

void autoPlay()
{
	while (1)
	{
		struct group tmp;
		tmp = findBiggestGroup();
		if (tmp.size < 2) break;
		clearGroupAndGetScore(tmp);
		getGravity();
		rotate();
		getGravity();
		memset(visited, 0, sizeof(visited));
	}
}

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> colors[i][j];
		}
	}
}


void solution()
{
	input();
	autoPlay();
	cout << score;
}

int main()
{
	solution();
}

