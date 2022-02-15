
#include <iostream>
#include <vector>
using namespace std;

int map[100][100] = { 0 };
int N;
int ny, nx, nd;
vector<int> v[20];

struct zeroCurveInfo
{
    int y;
    int x;
    int dir;
};


// n+1 세대 : n세대 커브를 시계 방향 90도 회전 한 것을 n세대 끝점에 붙인다.
// 끝 점 : 시작점에서 직선 거리로 가장 먼 거리


void input()
{
    int x, y, d, g;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y >> d >> g;
        v[i].push_back(x);
        v[i].push_back(y);
        v[i].push_back(d);
        v[i].push_back(g);


    }
}

int counterClockWiseRotate(int dir)
{
    if (dir == 0) return 1;
    if (dir == 3) return 0;
    if (dir == 2) return 3;
    if (dir == 1) return 2;
}
int arrivePointY(int y,int d)
{
    switch (d)
    {
    case 0:
        return y;

    case 1:
        return y - 1;

    case 2:
        return y;

    case 3:
        return y + 1;

    default:
        return y;
    }
}

int arrivePointX(int x, int d)
{
    switch (d)
    {
    case 0:
        return x+1;

    case 1:
        return x;

    case 2:
        return x-1;

    case 3:
        return x;

    default:
        return x;
    }
}

vector<int> zeroCurveArrivePoint(int y, int x, int d)
{

    vector<int> tmp;
   

    switch (d)
    {
    case 0:
        tmp.push_back(y);
        tmp.push_back(x+1);
        break;

    case 1:
        tmp.push_back(y-1);
        tmp.push_back(x);
        break;

    case 2:
        tmp.push_back(y);
        tmp.push_back(x-1);
        break;

    case 3:
        tmp.push_back(y + 1);
        tmp.push_back(x);
        break;

    default:
        tmp.push_back(y);
        tmp.push_back(x);
        break;
    }
    tmp.push_back(counterClockWiseRotate(d));
    return tmp;

}

void setDragonCurve(int y,int x,int d,int g)
{
    if (g == 0)
    {
        vector<int> tmp;
        if (y >= 0 && y < 100 && x >= 0 && x < 100) {
            map[y][x] = 1;
            ny = arrivePointY(y, d);
            nx = arrivePointX(x, d);
            nd = counterClockWiseRotate(d);
            
            if (ny >= 0 && ny < 100 && nx >= 0 && nx < 100)
            {
                map[ny][nx] = 1;
            }
            
        }
     
    }

    else
    {
        setDragonCurve(y, x, d, g - 1);

        setDragonCurve(ny, nx,nd,g-1);
    }
}

void testPrint()
{
    for (int i = 0; i < N; i++)
    {
        cout << " " << v[i][0] << " " << v[i][1] << " " << v[i][2] << " " << v[i][3] << endl;
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void solution()
{
    for (int i = 0; i < N; i++)
    {
        setDragonCurve(v[i][1], v[i][0], v[i][2], v[i][3]);
    }

}

int main()
{
    input();
    solution();
    testPrint();
}

