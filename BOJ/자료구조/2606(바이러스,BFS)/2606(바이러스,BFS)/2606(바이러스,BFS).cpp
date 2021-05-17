// 2606(바이러스,BFS).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <vector>
#include <queue>
#define TRUE 1
using namespace std;

int main()
{
    vector<int> g[101]; // 그래프 벡터
    queue<int> q;
    int vert; // 정점의 갯수
    int edge; // 간선의 갯수
    cin >> vert;
    cin >> edge;

    int visited[101] = { 0 }; // 노드 방문을 기록하는 배열 visited[i]는 i번째 정점의 방문 여부를 나타냄.

    for (int i = 0; i < edge; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    visited[1] = TRUE; 
    q.push(1);

    while (!q.empty()) // BFS
    {
        int t = q.front();
        q.pop();
         for (int i = 0; i < g[t].size(); i++)
        {
            int y = g[t][i];
            if (!visited[y])
            {
                q.push(y);
                visited[y] = TRUE;
            }
        }

    }

    int virus = 0;

    for (int i = 2; i <= vert; i++)
    {
        if (visited[i] == TRUE)
        {
            virus++;
        }

    }

    cout << virus << endl;

    return 0;
}
