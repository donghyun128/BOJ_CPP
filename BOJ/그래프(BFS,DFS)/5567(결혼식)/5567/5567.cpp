// 5567.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define TRUE 1
#define FALSE 0

void search( vector<int> graph[],int visited[])
{
    visited[1] = TRUE;
    for (int i = 0; i < graph[1].size(); i++)
    {
        int freind = graph[1][i];
        visited[freind] = TRUE;
        for (int i = 0; i < graph[freind].size(); i++)
        {
            int ff = graph[freind][i];
            if (visited[ff] == FALSE)
            {
                visited[ff] = TRUE;
            }
        }
    }
}
int main()
{
    int alum, list;
    vector<int> graph[10001];
    int visited[1001];
    memset(visited, 0, sizeof(visited));
    cin >> alum;
    cin >> list;

    for (int i = 0; i < list; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= list; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    search(graph, visited);

    int cnt= 0;
    for (int i = 2; i <= list; i++)
    {
        if (visited[i] == TRUE)
        {
            cnt++;
        }
    }

    printf("%d", cnt);
    return 0;
}

