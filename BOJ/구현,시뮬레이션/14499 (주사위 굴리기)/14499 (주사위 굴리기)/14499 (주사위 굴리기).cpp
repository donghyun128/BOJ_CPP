#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int map[20][20] = { 0 };
int dice[6] = { 0 };
// 주사위 설정 : 0 = 위쪽, 1 = 왼쪽 , 2= 뒤 , 3 = 오른쪽, 4 = 앞, 5 = 아래 
void up_roll()
{
    int tmp;
    //dice = { dice[4],dice[1],dice[0],dice[3],dice[5],dice[2] };
    tmp = dice[2];
    dice[2] = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[5];
    dice[5] = tmp;
}

void down_roll()
{
    int tmp;
    //dice = { dice[2],dice[1],dice[5],dice[3],dice[0],dice[4] };
    tmp = dice[5];
    dice[5] = dice[4];
    dice[4] = dice[0];
    dice[0] = dice[2];
    dice[2] = tmp;
}

void left_roll()
{
    int tmp;
    //dice = { dice[3],dice[0],dice[2],dice[5],dice[4],dice[1] };
    tmp = dice[3];
    dice[3] = dice[5];
    dice[5] = dice[1];
    dice[1] = dice[0];
    dice[0] = tmp;

}

void right_roll()
{
    int tmp;
    //dice = { dice[1],dice[5],dice[2],dice[0],dice[4],dice[3] };
    tmp = dice[5];
    dice[5] = dice[3];
    dice[3] = dice[0];
    dice[0] = dice[1];
    dice[1] = tmp;
}

void value_change(int x, int y)
{
    if (map[x][y] == 0)
    {
        map[x][y] = dice[5];
    }

    else if (map[x][y] != 0)
    {
        dice[5] = map[x][y];
        map[x][y] = 0;
    }
    printf("%d\n", dice[0]);

}
void move(int command[], int n_com, int x, int y, int n, int m)
{

    int cnt = 0;
    int xp = x; int yp = y; // xp: 세로 yp: 가로
    while (cnt != n_com)
    {
        int dir = command[cnt];
        switch (dir) // 1 : 동 , 2 : 서 , 3: 북 , 4: 남
        {
        case 1: if (yp < m - 1)
        {
            right_roll();
            yp++;
            value_change(xp, yp);
        }
              cnt++;
              break;
        case 2: if (yp > 0)
        {
            left_roll();
            yp--;
            value_change(xp, yp);
        }
              cnt++;
              break;

        case 3: if (xp > 0)
        {
            up_roll();
            xp--;
            value_change(xp, yp);
        }
              cnt++;
              break;
        case 4: if (xp < n - 1)
        {
            down_roll();
            xp++;
            value_change(xp, yp);
        }
              cnt++;
              break;
        default:
            break;
        }
    }

}

int main()
{
    int n, m;
    int x, y;
    int command[1000];
    int n_com;

    scanf("%d%d", &n, &m); // n: 세로 , m : 가로
    getchar();
    scanf("%d%d", &x, &y); // x : 세로 , y : 가로
    getchar();
    scanf("%d", &n_com);
    getchar();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < n_com; i++)
    {
        scanf("%d", &command[i]);
    }

    move(command, n_com, x, y, n, m);

    return 0;

}
