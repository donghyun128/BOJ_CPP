// 11725 (트리의 부모 찾기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int visited[100001] = { 0 };
int parent[100001] = { 0 };
vector<int> g[100001];

void dfs(int node)
{
    
    stack<int> s;

    visited[1] = 1;
    s.push(1);

    while (!s.empty())
    {
        int current = s.top();
        s.pop();

        for (int i = 0; i < g[current].size(); i++)
        {
            int next = g[current][i];
                if (visited[next] == 0)
                {
                    parent[next] = current;
                    s.push(next);
                    visited[next] = 1;
                }
        }
    }

    for (int i = 2; i <= node; i++)
    {
        printf("%d\n", parent[i]);
    }
    

}


int main()
{
    int node;
    

    cin >> node;
    for (int i = 1; i < node; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        g[n1].push_back(n2);
        g[n2].push_back(n1);
    }

    dfs(node);
}

