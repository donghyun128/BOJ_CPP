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

void bfs(int start,vector<int> g[]) 
{
    visited[start] = 1;
    group[start] = A;
    q.push(start);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i<g[cur].size(); i++)
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

void initialyze()
{
    memset(visited, 0, sizeof(visited));
    while (!q.empty())
    {
        q.pop();
    }
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
        }

        for (int k = 1; k <= v; k++)
        {
            bfs(k, g);
            for (int l = 0; l < g[k].size(); l++)
            {
                if (group[k] == group[g[k][l]])
                {
                    result = 0;
                    initialyze();
                    break;
                }
            }
            initialyze();
        }
        if (result == 1) printf("YES\n");
        else if (result == 0) printf("NO\n");
    }
}

