#include <iostream>
#include <algorithm>
#define INF 100000
using namespace std;

// N : 세로선, M : 가로선 , H : 가로선을 놓을 수 있는 위치의 갯수
int N, M, H ;
int ladder_map[11][31] = { 0 };
int ans = INF;
bool finish = 0;

int ladderResult(int row)
{
	int cy = 1;
	int cx = row; 

	while (cy <= H)
	{
		if (cx < N && ladder_map[cy][cx])
		{
			cx++;
		}

		else if (cx >=2 && ladder_map[cy][cx - 1])
		{
			cx--;
		}

		cy++;
	}

	return cx;
}

bool isManipulateSuccess()
{
	for (int i = 1; i <= N; i++)
	{
		if (i != ladderResult(i))
			return false;
	}
	return true;
}

void setAdditionalLadder(int cnt)
{
	if (cnt > 3)
	{
		return;
	}

	else if (isManipulateSuccess())
	{
		ans = min(ans, cnt);
		finish = true;
		return;
	}

	else
	{
		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (!ladder_map[i][j] && !ladder_map[i][j - 1])
				{
					// 왼쪽에 사다리 놓기
					if (j - 2 >= 1 && !ladder_map[i][j - 2])
					{
						ladder_map[i][j - 1] = 1;
						setAdditionalLadder(cnt + 1);
						ladder_map[i][j - 1] = 0;
					}

					// 오른쪽에 사다리 놓기
					if (j + 1 <= N && !ladder_map[i][j + 1])
					{
						ladder_map[i][j] = 1;
						setAdditionalLadder(cnt + 1);
						ladder_map[i][j] = 0;
					}

				}
			}
		}
	}

}

void printResult()
{
	for (int i = 1; i <= N; i++)
	{
		cout << ladderResult(i);
	}
}

void input()
{
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		ladder_map[a][b] = 1;
	}
}
void solution()
{
	setAdditionalLadder(0);
	if (ans > 3)
	{
		cout << -1;
	}
	else
		cout << ans;
}

int main()
{
	input();
	solution();
}

