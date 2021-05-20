// 11724 (연결 요소의 갯수).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
#define TRUE 1
#define FALSE 0




void DFS(vector<int> g[],int visited[] , int start)
{
    stack<int> s;
    visited[start] = TRUE;
    s.push(start);
    while (!s.empty())
    {
        int current = s.top();
        s.pop();

        for (int i = 0; i < g[current].size(); i++)
        {
            int adj = g[current][i];
                if (visited[adj] == FALSE)
                {
                    DFS(g, visited, adj);
                }
        }
    }
}

int main()
{
    vector<int> g[1001];
    int visited[1001] = { 0 };
    int vert, edge;
    cin >> vert >> edge;

    for (int i = 0; i < edge; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    for (int i = 1; i <= vert; i++)
    {
        sort(g[i].begin(), g[i].end());
    }
    int count=0;

    for (int i = 1; i <= vert; i++)
    {
        if (!visited[i])
        {
            DFS(g, visited, i);
            count++;
        }
    }
  
    printf("%d", count);

    return 0;
}
