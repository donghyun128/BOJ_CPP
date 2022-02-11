// 코드 알고리즘 블로그에서 베낌
/*
	출처: https://velog.io/@sj-lee33/%EB%B0%B1%EC%A4%80-14503%EB%B2%88-%EB%A1%9C%EB%B4%87-%EC%B2%AD%EC%86%8C%EA%B8%B0-c-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%ED%92%80%EC%9D%B4
*/
// 재풀이 요망
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

#define MOVE 0
#define GO_BACK 1
#define STOP 2
#include <iostream>
using namespace std;

int N, M;
int zone[50][50] = { 0 };
int visited[50][50] = { 0 };
int cleaned = 0;
int r, c, d;

// 북, 동, 남, 서
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

void input()
{
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> zone[i][j];
		}
	}

	visited[r][c] = 1;
	cleaned++;
}

int nextDirection(int currentDirection)
{
	if (currentDirection == 0) return 3;
	else if (currentDirection == 1) return 0;
	else if (currentDirection == 2) return 1;
	else return 2;
}

int backDirection(int currentDirection)
{
	if (currentDirection == 0) return 2;
	else if (currentDirection == 1) return 3;
	else if (currentDirection == 2) return 0;
	else return 1;
}


void dfs()
{
	for (int i = 0; i < 4; i++)
	{
		int next_d = (d + 3 - i) % 4;
		int next_r = r + dy[next_d];
		int next_c = c + dx[next_d];

		if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M || zone[next_r][next_c] == 1)
		{
			continue;
		}

		if (zone[next_r][next_c] == 0 && visited[next_r][next_c] == 0)
		{
			d = next_d;
			r = next_r;
			c = next_c;
			visited[r][c] = 1;
			cleaned++;
			dfs();
		}
	}

	int back_r = r - dy[d];
	int back_c = c - dx[d];

	if (back_r >= 0 && back_r < N && back_c >= 0 && back_c < M)
	{
		if (zone[back_r][back_c] == 0)
		{
			r = back_r;
			c = back_c;
			dfs();
		}
		else
		{
			cout << cleaned << "\n";
			exit(0);
		}

	}

}


int main()
{
	input();
	dfs();

	


}

