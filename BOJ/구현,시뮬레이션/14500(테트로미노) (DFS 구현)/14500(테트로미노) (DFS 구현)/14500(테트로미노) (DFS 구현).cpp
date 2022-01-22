// 14500(테트로미노) (DFS 구현).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int max_score = 0;
int map[500][500];
bool visited[500][500] = { false };
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

// DFS로 T 도형 제외한 테트로미노의 score 계산
void dfs(int cy, int cx, int sum, int count)
{

	if (count == 4)
	{
		max_score = max(sum, max_score);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = cy + dy[i];
		int nx = cx + dx[i];

		if ((ny < 0 || nx < 0 || ny >= N || nx >= M))
			continue;
	
		if (!visited[ny][nx])
		{
			visited[cy][cx] = true;

			dfs(ny, nx, sum + map[ny][nx], count + 1);

			visited[cy][cx] = false;
		}
	}
}

// DFS exception : T자 도형
void search_T(int cy, int cx)
{
	int score = 0;

	// 1. ㅜ
	if (cy >= 0 && cx >= 0 && cy + 1< N && cx + 2 < M)
	{
		score = map[cy][cx] + map[cy][cx + 1] + map[cy][cx + 2] + map[cy + 1][cx + 1];
		max_score = max(max_score, score);
	}

	// 2. ㅓ
	if (cy >= 0 && cx - 1 >= 0 && cy + 2 < N && cx < M)
	{
		score = map[cy][cx] + map[cy+1][cx] + map[cy+2][cx] + map[cy+1][cx-1];
		max_score = max(max_score, score);

	}

	// 3. ㅗ
	if (cy-1 >= 0 && cx - 2 >= 0 && cy < N && cx < M)
	{
		score = map[cy][cx] + map[cy][cx-1] + map[cy][cx-2] + map[cy-1][cx-1];
		max_score = max(max_score, score);

	}

	// 4. ㅏ
	if (cy  >= 0 && cx >= 0 && cy + 2 < N && cx + 1 < M)
	{
		score = map[cy][cx] + map[cy + 1][cx] + map[cy + 2][cx] + map[cy +1][cx + 1];
		max_score = max(max_score, score);
	}

}



int main()
{
	cin >> N >> M;

	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			cin >> map[n][m];
		}
	}

	for (int n = 0; n < N; n++)
	{

		for (int m = 0; m < M; m++)
		{
			visited[n][m] = true;
			dfs(n, m, map[n][m], 1);
			visited[n][m] = false;
			search_T(n, m);
		}
	}

	cout << max_score;

}

