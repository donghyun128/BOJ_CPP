// 2468 (안전 영역).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <cstring>
#define True 1
#define False 0
using namespace std;
int visited[101][101] = { 0 };
<<<<<<< HEAD
int g[101][101] = { 0 }; // 건물높이
int t[101][101] = { 0 }; // 침수여부. 침수되면 0, 아니면 1

void dfs(int y,int x, int r) {
=======
int g[101][101] = { 0 };

void dfs(int y,int x,int r) {
    visited[y][x] = True;
>>>>>>> ddddf3395bc18841a784e4ac1f51872a2baad4cb
    pair<int, int> d[4] = { {-1,0},{0,1},{1,0},{0,-1} };

            for (int k = 0; k < 4; k++)
            {
<<<<<<< HEAD
                if (visited[y + d[k].first][x + d[k].second] == False && t[y + d[k].first][x + d[k].second] == True  && x+d[k].first < 101 && y+d[k].second < 101)
                {
                    visited[y + d[k].first][x + d[k].second] = True;
=======
                if (visited[y + d[k].first][x + d[k].second] == False && g[y+d[k].first][x+d[k].second] > r)
                {
>>>>>>> ddddf3395bc18841a784e4ac1f51872a2baad4cb
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
<<<<<<< HEAD
    for (int r = 0; r <= max; r++)
=======
    for (int r = 0; r <= 100; r++)
>>>>>>> ddddf3395bc18841a784e4ac1f51872a2baad4cb
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
<<<<<<< HEAD
    for (int r = 0; r <= max; r++) // 강수량에 따른 안전 구역 갯수 중 최대 갯수 출력
=======
    for (int r = 0; r <= 100; r++) // 강수량에 따른 안전 구역 갯수 중 최대 갯수 출력
>>>>>>> ddddf3395bc18841a784e4ac1f51872a2baad4cb
    {
        if (secure_zone[r] > s_max)
            s_max = secure_zone[r];
    }
    printf("%d", s_max);
}

