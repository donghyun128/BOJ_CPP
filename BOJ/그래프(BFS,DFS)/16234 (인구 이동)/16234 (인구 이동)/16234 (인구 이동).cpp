#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int population[50][50] = { 0 };
int population_tmp[50][50] = { 0 };

int unite_map[50][50] = { 0 };
int N, L, R;
int unite = 0;
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

vector <pair<int, int>> popul_changed;

bool isSame()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (population[i][j] != population_tmp[i][j])
                return false;
        }
    }
    return true;
}



void make_single_unite(int y, int x)
{
    int country = 1, total = 0;
    queue<pair<int, int>> q;
    vector <pair<int, int>> v;

    unite_map[y][x] = unite;
    q.push(make_pair(y, x));
    v.push_back(make_pair(y, x));
    popul_changed.push_back(make_pair(y, x));

    total = population[y][x];
    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < N && nx >= 0 && nx < N)
            {
                if (unite_map[ny][nx] == 0 && abs(population[cy][cx] - population[ny][nx]) >= L && abs(population[cy][cx] - population[ny][nx]) <= R)
                {
                    q.push(make_pair(ny, nx));
                    v.push_back(make_pair(ny, nx));
                    popul_changed.push_back(make_pair(ny, nx));
                    unite_map[ny][nx] = unite;
                    total += population[ny][nx];
                    country++;

                }
            }
        }
    }

    int average = total / country;

    while (!v.empty())
    {
        int cy = v.back().first;
        int cx = v.back().second;
        population[cy][cx] = average;
        v.pop_back();
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

int count_days()
{
    
    int ans = 0;

    while (1)
    {
        unite = 0; 

        for (int k = 0; k < popul_changed.size(); k++)
        {
            int y = popul_changed[k].first;
            int x = popul_changed[k].second;
            population_tmp[y][x] = population[y][x];
            unite_map[y][x] = { 0 };

        }

        popul_changed.clear();
        make_all_unite();

        if (isSame() == false)
        {
            ans++;
            continue;
        }
        break;
    }
    return ans;
}

void input()
{
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> population[i][j];
            population_tmp[i][j] = population[i][j];
        }
    }
}

void solution()
{
    cout << count_days();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solution();

}
