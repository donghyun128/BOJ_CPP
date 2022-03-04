
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int population[51][51] = { 0 };
int unite_map[51][51] = { false };
int N, L, R;
int unite = 0;
int dy[] = {0,0,-1,1};
int dx[] = {1,-1,0,0};
stack<pair<int, int>> s;



void make_single_unite(int cy,int cx)
{
    unite_map[cy][cx] = unite;

    while (!s.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < N && nx >= 0 && nx < N)
            {
                if (unite_map[ny][nx] == 0 && abs(population[cy][cx] - population[ny][nx]) >= L && abs(population[cy][cx] - population[ny][nx]) <= R)
                {
                    s.push(make_pair(ny,nx));
                    make_single_unite(ny, nx);
                }
            }
        }
    }
}

void make_all_unite()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (unite_map[i][j] == 0)
            {
                unite++;
                make_single_unite(i, j);
            }
        }
    }
}

int calculate_average(int unite_num)
{
    int unite_population = 0;
    int country = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (unite_map[i][j] == unite_num)
            {
                country++;
                unite_population += population[i][j];
            }
        }
    }

    return unite_population / country;

}


void input()
{
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> population[i][j];
        }
    }
}


int main()
{
    std::cout << "Hello World!\n";
}

