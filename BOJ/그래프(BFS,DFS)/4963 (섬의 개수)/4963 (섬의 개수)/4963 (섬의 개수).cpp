// 4963 (섬의 개수).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <memory.h>
#define TRUE 1
#define FALSE 0
using namespace std;

void dfs(int x,int y,int g[][51],int visited[][51]) {
    visited[x][y] = TRUE;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (visited[x + i][y + j] == 0 && g[x + i][y + j] == 1)
                {
                    dfs(x + i, y + j, g, visited);
                }
            }
        }
    
}

int main()
{
    int w, h;
    int g[51][51];
    int visited[51][51];
    memset(g, 0, sizeof(g));
    memset(visited, 0, sizeof(visited));
    while (1)
    {
        int cnt = 0;
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                cin >> g[i][j];
            }
        }

        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                if (g[i][j] == TRUE && visited[i][j] == FALSE)
                {
                    dfs(i, j, g, visited);
                    cnt++;          
                }
                
                
            }
        }
        printf("%d\n", cnt);
        memset(visited, 0, sizeof(visited));
        memset(g, 0, sizeof(g));

    }
}

