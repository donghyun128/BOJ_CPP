
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int A[51][51] = { 0 };
bool visited[51][51] = { false };
int N, M;
int ans = 0;

struct node
{
	int y,x;
};
vector<pair<int, int>> spell;
vector<node> clouds;

int dy[9] = {0,0,-1,-1,-1,0,1,1,1};
int dx[9] = {0,-1,-1,0,1,1,1,0,-1};

void moveCloud(int d, int s)
{
	pair <int, int> goal;
	int goalY, goalX;
	goalY = N - 1;
	goalX = 1;
	int S = s % N;

	for (int c = 0; c < clouds.size(); c++)
	{
		clouds[c].x = (clouds[c].x + dx[d] * S + N) % N;
		clouds[c].y = (clouds[c].y + dy[d] * S + N) % N;
		A[clouds[c].y][clouds[c].x]++;
		visited[clouds[c].y][clouds[c].x] = true;

	}
	
}

void waterCopyBug()
{
	for (node cur : clouds)
	{
		int bCnt = 0;
		for (int k = 2; k <= 8; k += 2)
		{
			int ny = cur.y + dy[k];
			int nx = cur.x + dx[k];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;
			else if (A[ny][nx] > 0)
			{
				bCnt++;
			}
		}
		A[cur.y][cur.x] += bCnt;
	}
}

void makeCloud()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == false && A[i][j] >= 2)
			{
				clouds.push_back({ i,j });
				A[i][j] -= 2;
			}
		}
	}
}

void baragi(int num)
{
	int d = spell[num].first;
	int s = spell[num].second;

	moveCloud(d, s);
	waterCopyBug();
	clouds.clear();
	makeCloud();
	memset(visited, false, sizeof(visited));
}

void solution()
{
	for (int k = 0; k < M; k++)
	{
		
		baragi(k);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ans += A[i][j];
		}
	}

	cout << ans;
}

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}

	for (int k = 0; k < M; k++)
	{
		int d, s;
		cin >> d >> s;
		spell.push_back(make_pair(d, s));
	}

	clouds.push_back({ N - 1 ,0 });
	clouds.push_back({ N - 1 ,1 });
	clouds.push_back({ N - 2,0 });
	clouds.push_back({ N - 2,1 });
}

int main()
{
	input();
	solution();
}

