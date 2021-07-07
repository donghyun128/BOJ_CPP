// 2468 (안전 영역).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <cstring>
#include <stack>
#define True 1
#define False 0
using namespace std;
int visited[101][101] = { 0 };
int g[101][101] = { 0 };

void dfs(int y,int x,int r) {
    visited[y][x] = True;
    pair<int, int> d[4] = { {-1,0},{0,1},{1,0},{0,-1} };

            for (int k = 0; k < 4; k++)
            {
                if (visited[y + d[k].first][x + d[k].second] == False && g[y+d[k].first][x+d[k].second] > r)
                {
                    dfs(y + d[k].first, x + d[k].second,r);
                }
            }
}

int main()
{
   
    int n; // 행과 열 갯수
    int max = 0;
    int secure_zone[101]; // 강수량에 따른 안전구역 갯수.
    memset(secure_zone, 0, 101);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
            if (g[i][j] > max) max = g[i][j];
        }
    }
    

     // 강수량 r의 범위는 0 ~ 가장 높은 건물 높이
    for (int r = 0; r <= 100; r++)
    {
        memset(visited, 0, 101 * 101);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (visited[i][j] == False && g[i][j] > r)
                {
                  secure_zone[r]++;
                  dfs(i, j,r);
                }
                
            }
        }

    }

    int s_max = 0;
    for (int r = 0; r <= 100; r++) // 강수량에 따른 안전 구역 갯수 중 최대 갯수 출력
    {
        if (secure_zone[r] > s_max)
            s_max = secure_zone[r];
    }
    printf("%d", s_max);
}

