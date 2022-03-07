#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// N : 땅의 크기 , M : 심은 나무 갯수 , K : 시간 
int N, M, K;
int ans = 0;

int A[11][11] = { 0 };
int nutrient[11][11] = { 0 };

int dy[8] = {0,0,1,-1,1,-1,1,-1};
int dx[8] = {1,-1,0,0,1,-1,-1,1};

vector<int> tree[11][11];
vector<int> tmp;

void year_process()
{
    // 봄, 여름
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int all_die_nutrition = 0;

            sort(tree[i][j].begin(),tree[i][j].end());
            
            for (int k = 0; k < tree[i][j].size(); k++)
            {
                if (nutrient[i][j] >= tree[i][j][k])
                {
                    nutrient[i][j] -= tree[i][j][k];
                    tmp.push_back(tree[i][j][k] + 1);
                   
                }
                else
                {
                    // 여름
                    all_die_nutrition += tree[i][j][k] / 2;
                  
      
                }
            }
            tree[i][j].clear();
            while (!tmp.empty())
            {
                tree[i][j].push_back(tmp.back());
                tmp.pop_back();
            }
            nutrient[i][j] += all_die_nutrition;

        }
    }

    // 가을
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k=0; k<tree[i][j].size(); k++)
            {
                if (tree[i][j][k] % 5 == 0)
                {
                    for (int d = 0; d < 8; d++)
                    {
                        int ny = i + dy[d];
                        int nx = j + dx[d];
                        if (ny >= 1 && ny <= N && nx >= 1 && nx <= N)
                        {
                            tree[ny][nx].push_back(1);
                        }
                    }
                }
            }

        }
    }
   
    
    // 겨울
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            nutrient[i][j] += A[i][j];
        }
    }

}

/*
void print_tree()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 0; k < tree[i][j].size(); k++)
            {
                cout << tree[i][j][k] << " ";
            }
            cout << "         ";
        }
        cout << endl;
    }
}
*/

void solution()
{
    for (int k = 0; k < K; k++)
    {
        //print_tree();
        year_process();

    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            ans += tree[i][j].size();
        }
    }
    cout << ans;

}
void input()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> A[i][j];
            nutrient[i][j] = 5;
        }
    }

    for (int m = 0; m < M; m++)
    {
        int x, y, age;
        cin >> x >> y >> age;
        tree[x][y].push_back(age);
    }
}

int main()
{
    input();
    solution();
    
}
