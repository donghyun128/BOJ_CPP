#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define A 1
#define B 2
using namespace std;
int visited[20001] = { 0 };
int group[20001] = { 0 };
queue<int> q;

void bfs(int start, vector<int> g[])
{
    visited[start] = 1;
    group[start] = A;
    q.push(start);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < g[cur].size(); i++)
        {
            int next = g[cur][i];

            if (visited[next] == 0)
            {
                if (group[cur] == A)
                    group[next] = B;
                else if (group[cur] == B)
                    group[next] = A;
                visited[next] = 1;
                q.push(next);
            }
        }
    }
}

int isBirpartite(vector<int> g[], int n_vertex)
{
    for (int i = 1; i <= n_vertex; i++)
    {
        for (int j = 0; j < g[i].size(); j++)
        {
            if (group[i] == group[g[i][j]])
            {
                return 0;
            }
        }
    }
    return 1;
}


int main()
{
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int result = 1;
        int v, e;
        cin >> v >> e;
        vector<int> g[20001];
        for (int j = 1; j <= e; j++)
        {
            int c_vert;
            int c_edge;
            cin >> c_vert >> c_edge;
            g[c_vert].push_back(c_edge);
            g[c_edge].push_back(c_vert); // 계속 틀린 이유: 70번 행만 써서 간선이 한쪽에만 연결되었었음.
        }

        for (int k = 1; k <= v; k++)
        {
            if (visited[k] == 0)
                bfs(k, g);
        }

        result = isBirpartite(g, v);
        if (result == 1) printf("YES\n");
        else if (result == 0) printf("NO\n");

        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= v; i++)
        {
            g[i].clear();
        }
        memset(group, 0, sizeof(visited));
        while (!q.empty())
            q.pop();
    }
}