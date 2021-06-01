// 13565 (침투).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <stack>
#include <cstring>

#define True 1
#define False 0
using namespace std;

int g[1001][1001];
int visited[1001][1001];
stack<pair<int,int>> st;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int y,int x)
{
	
	st.push({y,x});
	visited[y][x] = True;
	
	while (!st.empty())
	{
		pair<int, int> curr = st.top();
		st.pop();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> next;
			next.first = curr.first + dy[i];
			next.second = curr.second + dx[i];

			if (visited[next.first][next.second] == False && g[next.first][next.second] == 0)
			{
				visited[next.first][next.second] = True;
				st.push({next.first,next.second });
			}
		}
	}

}


int main()
{
	memset(g, 1, sizeof(g));
	memset(visited, 0, sizeof(visited));
	int m, n;
	string row;

	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		cin >> row;
		for (int j = 0; j < n; j++)
		{
			g[i][j + 1] = (row[j]-'0');
		}
	}

	for (int j = 1; j <= n; j++)
	{
		if (g[1][j] == 0 && visited[1][j] == False) {
			dfs(1, j);
		}
	}

	int result = 0;

	for (int j = 1; j <= n; j++)
	{
		if (visited[m][j] == True)
		{
			result = 1;
		}

		while (!st.empty())
		{
			st.pop();
		}
	}

	if (result == 1)
	{
		printf("YES");
	}
	else printf("NO");

	return 0;
}

