// 2644 (촌수계산).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define True 1
#define False 0
using namespace std;

queue<int> q;

int bfs(int src, int des, vector<int> g[101],int visited[])
{
    int distance[101]; // distance[k]는 src와 k 와의 촌수
    memset(distance, -1, 101);
    distance[src] = 0;
    visited[src] = True;
    q.push(src);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        int size = g[cur].size();
        for (int i = 0; i < size; i++)
        {
            
            int next = g[cur][i];
            if (visited[next] == False)
            {
                visited[next] = True;
                distance[next] = distance[cur] + 1;
                q.push(next);
            }
        }
    }
    return distance[des];
}

int main()
{
    int visited[101] = {0};
    vector<int> g[101];
    int vert, edge; // 정점, 간선
    int src, des; // 두 사람
    cin >> vert;
    cin >> src >> des;
    cin >> edge;

    for (int i = 0; i < edge; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    int result = bfs(src, des, g, visited);
    printf("%d", result);
    
    return 0;
}

