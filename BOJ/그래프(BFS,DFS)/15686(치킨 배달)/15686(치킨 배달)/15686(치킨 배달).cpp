#include <iostream>
#include <queue>
using namespace std;

int store_y[13] = { 0 };
int store_x[13] = { 0 };

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int N = 0;
int M = 0;
int map[51][51] = { 0 };
bool visited[13] = { false };

int result = 10000000;



int check_chicken_store()
{
	int idx = 0;
	int num_store = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] == 2)
			{
				store_y[idx] = i;
				store_x[idx] = j;
				idx++;
				num_store++;
			}
		}
	}
	return num_store;
}

int cal_distance(int y1, int x1, int y2, int x2)
{
	return abs(y2 - y1) + abs(x2 - x1);
}

void recur_chicken_distance(int idx,int cnt,int num_store)
{
	if (cnt == M)
	{
		int ans = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (map[i][j] == 1)
				{
					int dist = 10000000;

					for (int k = 0; k < num_store; k++)
					{
						if (visited[k] == true)
						{
							dist = min(dist, cal_distance(i, j, store_y[k], store_x[k]));
						}
					}
					ans += dist;
				}
			}

		}
		result = min(result, ans);
		return;

	}

	if (idx == num_store)
		return;

	else
	{	
			visited[idx] = true;
			recur_chicken_distance(idx + 1, cnt + 1, num_store);

			visited[idx] = false;
			recur_chicken_distance(idx + 1, cnt, num_store);
		
	
	}
}


int main()
{
	int ans = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	int num_store = check_chicken_store();

	recur_chicken_distance(0, 0, num_store);
	

	cout << result;
}

