// 1260 (DFS와 BFS).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

#define TRUE 1
#define FALSE 0

using namespace std;

void DFS(vector<int> g[], int visited[], int start)
{
	visited[start] = TRUE;
	printf("%d ", start);
	for (int i = 0; i < g[start].size(); i++)
	{
		int next = g[start][i];
		if (visited[next] == FALSE)
		{
			DFS(g, visited, next);
		}
	}
}

void BFS(vector<int> g[], int visited[], int start)
{
	queue<int> q;
	visited[start] = TRUE;
	q.push(start);

	while (!q.empty())
	{

		int current = q.front();
		printf("%d ", current);
		q.pop();
		
		for (int i = 0; i < g[current].size(); i++)
		{
			
			int next = g[current][i];
			if (visited[next] == FALSE)
			{
				q.push(next);
				visited[next] = TRUE;
				
			}
		}
	}

}


int main()
{
	int vert, edge, start;
	queue<int> q;
	vector<int> g[1001];
	int visited[1001];
	cin >> vert >> edge >> start;

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < edge; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}

	for (int i = 0; i < vert; i++)
	{
		sort(g[i].begin(), g[i].end());
	}


	DFS(g, visited, start);
	cout << endl;
	memset(visited, 0, sizeof(visited));
	BFS(g, visited, start);
}

