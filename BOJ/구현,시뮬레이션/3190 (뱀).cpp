#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define APPLE 1
#define BODY -1;
#define EMPTY 0
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3


struct queue {
    int front;
    int rear;
    int size;
    char coor[101];
};

int map[101][101] = { 0 }; // 보드
char ch_dir[101]; // 왼쪽? 오른쪽?
int move_t[101]; // 방향 바꾸기 전 움직이는 시간
int direction[101]; // 현재 가고 있는 방향
struct queue qy;
struct queue qx;


int isEmpty(struct queue &Q)
{
    if (Q.front == Q.rear)
        return 1;
    else return 0;
}

void enQueue(struct queue &Q, int n)
{
    Q.coor[Q.rear] = n;
    Q.rear++;

}

int deQueue(struct queue& Q)
{
    int tmp = Q.coor[Q.front];
    Q.coor[Q.front] = NULL;
    Q.front++;
    return tmp;
}

int decide_dir(int &direction, char ch_dir)
{
    switch (direction)
    {
    case UP:
        if (ch_dir == 'L')
            direction = LEFT;
        else if (ch_dir == 'D')
            direction = RIGHT;
        break;
    case DOWN:
        if (ch_dir == 'L')
            direction = RIGHT;
        else if (ch_dir == 'D')
            direction = LEFT;
        break;
    case LEFT:
        if (ch_dir == 'L')
            direction = DOWN;
        else if (ch_dir == 'D')
            direction = UP;
        break;
    case RIGHT:
        if (ch_dir == 'L')
            direction = UP;
        else if (ch_dir == 'D')
            direction = DOWN;
        break;
    default:
        break;
    }
    return direction;
}

int move_coor(int y, int x,int &length)
{
    int tmp_x[101];
    int tmp_y[101];
    for (int i = 1; i <= length; i++)
    {
        tmp_y[i] = deQueue(qy);
        tmp_x[i] = deQueue(qx);
        
    }
    enQueue(qy, y);
    enQueue(qx, x);
    if (map[y][x] == APPLE)
    {
        length++;
        map[y][x] = EMPTY;
    }
    
        for (int i = 1; i <= length; i++)
        {
            if (tmp_y[i] == y && tmp_x[i] == x)
                return 1;
            if (i < length) {
                enQueue(qy, tmp_y[i]);
                enQueue(qx, tmp_x[i]);
            }
        }
    
    return 0;
}

int move(int direction, int &y, int &x,int size, int &length)
{
    int body_break = 0;
    switch (direction)
    {
    case UP :
        y--;
        if (y > size || y < 1) break;
        body_break = move_coor(y, x, length);
        break;
    case DOWN :
        y++;
        if (y > size || y < 1) break;
        body_break = move_coor(y, x, length);
        break;
    case LEFT :
        x--;
        if (x > size || x < 1) break;
        body_break = move_coor(y, x, length);
        break;
    case RIGHT :
        x++;
        if (x > size || x < 1) break;
        body_break = move_coor(y, x, length);
        break;
    
    }
    if (y > size || x > size || y < 1 || x < 1)
        return 0;
    if (body_break == 1)
        return 0;
    else return 1;
}

int main()
{
    int N, K, L;
    int length = 1;
    int px = 1; int py = 1;
    
    scanf("%d", &N);
    scanf("%d", &K);
    for (int i = 1; i <= K; i++)
    {
        int y, x;
        scanf("%d %d", &y, &x);
        map[y][x] = APPLE;
    }
    
    scanf("%d", &L);
    for (int i = 1; i <= L; i++)
    {
        scanf("%d %c", &move_t[i], &ch_dir[i]);
    }
    
    int direction = RIGHT;
    enQueue(qy, 1);
    enQueue(qx, 1);
    int ch_time = 1;
    int exitouterLoop = 0;
    while (1)
    {
        for (int t = 1; t; t++)
        {
            if (move(direction, py, px, N, length) == 0)
            {
                printf("%d", t);
                exitouterLoop = 1;
                break;
            }

            

            if (t == move_t[ch_time])
            {
                decide_dir(direction, ch_dir[ch_time]);
                ch_time++;
            }

        }
        if (exitouterLoop) break;
    }
    return 0;
}
