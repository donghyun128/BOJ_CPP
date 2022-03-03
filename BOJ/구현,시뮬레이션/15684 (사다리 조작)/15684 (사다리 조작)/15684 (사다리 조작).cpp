
#include <iostream>
using namespace std;
#define INF 1000000
int N, M, H;
bool ladder[11][271][2] = { false };
bool ladder_tmp[11][271][2] = { false };
int ans = INF;

// vertical[0] -> 왼쪽 연결 , vetical[1] -> 오른쪽 연결


void copy_arr(bool arr[11][271][2])
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= H; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				arr[i][j][k] = ladder[i][j][k];
			}
		}
	}
}

// current_col : 가로선 , current_row : 세로선
int get_goal(int current_col,int current_row)
{
	if (current_col == H+1)
	{
		return current_row;
	}
	else {
		// 왼쪽에 길이 있음
		if (ladder_tmp[current_row][current_col][0] == 1)
		{
			return get_goal(current_col + 1, current_row - 1);
		}
		// 오른쪽에 길이 있음
		else if (ladder_tmp[current_row][current_col][1] == 1)
		{
			return get_goal(current_col + 1, current_row + 1);
		}
		// 현재 행 오른쪽, 왼쪽 길 둘 다 없음.
		else
		{
			return get_goal(current_col + 1, current_row);
		}

	}
}

bool isManipulateSuccess()
{
	for (int i = 1; i <= N; i++)
	{
		int goal = get_goal(1, i);
		if (goal != i)
			return false;
	}
	return true;
}

void manipulate_ladder(int cnt)
{
	if (isManipulateSuccess())
	{
		ans = min(cnt, ans);
	}

	if (cnt > 3)
		return;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= H; j++)
			{
				if (ladder_tmp[i][j][0] == 0 && ladder_tmp[i][j][1] == 0)
				{

					// 왼쪽선 추가
					if (ladder_tmp[i - 1][j][0] == 0 && i >=2)
					{
						ladder_tmp[i][j][0] = 1;
						ladder_tmp[i - 1][j][1] = 1;
						manipulate_ladder(cnt + 1);
						ladder_tmp[i][j][0] = 0;
						ladder_tmp[i - 1][j][1] = 0;
					}
					
					// 오른쪽 선 추가

					if (i + 1 <= N && ladder_tmp[i+1][j][1] == 0)
					{
						ladder_tmp[i][j][1] = 1;
						ladder_tmp[i + 1][j][0] = 1;
						manipulate_ladder(cnt + 1);
						ladder_tmp[i][j][1] = 0;
						ladder_tmp[i + 1][j][0] = 0;
					}
				}
				
			}
		}

}

void input()
{
	int a, b;

	cin >> N >> M >> H;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		ladder[b][a][1] = 1;
		ladder[b + 1][a][0] = 1;
	}
}

void solution()
{
	
	copy_arr(ladder_tmp);
	manipulate_ladder(0);

	if (ans > 3)
		cout << -1;
	else
		cout << ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solution();
}
