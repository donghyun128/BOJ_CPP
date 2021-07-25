#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int diam = 0;
int diam_arr[100001] = { 0 };
int visited[100001] = { 0 };
vector<pair<int, int>> map[100001];

// 트리의 지름 찾기: 임의의 점에서 가장 먼 점 u 찾기. u에서 가장 먼 점 t 찾기. u와 t 사이의 거리 = 트리의 지름.

void dfs(int visited[], int start_v,int v)
{
    visited[start_v] = 1;

    for (int i = 0; i < map[start_v].size(); i++)
    {
        int next = map[start_v][i].first;
        if (visited[next] == 0)
        {
            diam_arr[next] = diam_arr[start_v] + map[start_v][i].second;
            dfs(visited, next, v);
        }
    }
}

int main()
{
    
    int v, vertex, connect_v, connect_d;
    cin >> v;
    for (int i = 1; i <= v; i++)
    {
        cin >> vertex;
        while (1)
        {
            cin >> connect_v;
            if (connect_v == -1) break;
            cin >> connect_d;
            map[vertex].push_back(make_pair(connect_v,connect_d));

        }
    }

    int result = 0;
    int t = 0 , u = 0;

    dfs(visited, 1, v);
    for (int k = 1; k <= v; k++)
    {
           if (result < diam_arr[k])
            {   
               result = diam_arr[k];
                t = k;
            } 
     }

    printf("%d\n", t);

   result = 0;
   memset(diam_arr, 0, sizeof(diam_arr));
   memset(visited, 0, sizeof(visited));
   dfs(visited, t, v);
   for (int k = 1; k <= v; k++)
   {
       if (result < diam_arr[k])
       {
           result = diam_arr[k];
           u = k;
       }
   }
   printf("%d\n", u);

   memset(diam_arr, 0, sizeof(diam_arr));
   memset(visited, 0, sizeof(visited));
   dfs(visited, t, v);

    printf("%d", diam_arr[u]);
}

