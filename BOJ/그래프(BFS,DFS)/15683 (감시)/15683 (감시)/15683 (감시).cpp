#include <iostream>
#define INF 1000000
using namespace std;
int N, M;
int office[8][8] = {0};
int visited[8][8] = { 0 };
int office_tmp[8][8] = { 0 };
int cnt_CCTV = 0;
int ans = INF;

void copyArr(int src[][8], int dst[][8])
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			src[i][j] = dst[i][j];
		}
	}
}


int numOfBlindSpot(int arr[][8])
{
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
				ret++;
		}
	}
	return ret;
}

void count_CCTV(int arr[][8])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] > 0 && arr[i][j] < 6)
				cnt_CCTV++;
		}
	}
}

void up(int y, int x)
{
	for (int i = y; i >= 0; i--)
	{
		if (office_tmp[i][x] == 6)
			break;

		else if (0 < office_tmp[i][x] && office_tmp[i][x] < 6)
		{
			continue;
		}
		else if (office_tmp[i][x] == 0)
			office_tmp[i][x] = 7;
	}
}

void down(int y, int x)
{
	for (int i = y; i < N; i++)
	{
		if (office_tmp[i][x] == 6)
			break;

		else if (0 < office_tmp[i][x] && office_tmp[i][x] < 6)
		{
			continue;
		}
		else if (office_tmp[i][x] == 0)
			office_tmp[i][x] = 7;
	}
}

void right(int y, int x)
{
	for (int i = x; i < M; i++)
	{
		if (office_tmp[y][i] == 6)
			break;
		else if (0 < office_tmp[y][i] && office_tmp[y][i] < 6)
		{
			continue;
		}
		else if (office_tmp[y][i] == 0)
			office_tmp[y][i] = 7;
	}
}

void left(int y, int x)
{
	for (int i = x; i >=0; i--)
	{
		if (office_tmp[y][i] == 6)
			break;
		else if (0 < office_tmp[y][i] && office_tmp[y][i] < 6)
		{
			continue;
		}
		else if (office_tmp[y][i] == 0)
			office_tmp[y][i] = 7;
	}
}

void CCTV_one(int y, int x, int dir)
{
	if (dir == 1)
	{
		right(y, x);

	}

	else if (dir == 2)
	{
		up(y, x);

	}


	else if (dir == 3)
	{
		left(y, x);

	}
	else
	{
		down(y, x);
	}
}

void CCTV_two(int y, int x,int dir)
{
	if (dir == 1)
	{
		left(y, x);
		right(y, x);

	}

	else if (dir == 2)
	{
		up(y, x);
		down(y, x);
	}


	else if (dir == 3)
	{
		left(y, x);
		right(y, x);
	}
	else
	{
		up(y, x);
		down(y, x);
	}
}

void CCTV_three(int y, int x, int dir)
{
	if (dir == 1)
	{
		up(y, x);
		right(y, x);

	}

	else if (dir == 2)
	{
		right(y, x);
		up(y, x);
	}


	else if (dir == 3)
	{
		left(y, x);
		down(y, x);
	}
	else
	{
		left(y, x);
		up(y, x);
	}
}

void CCTV_four(int y, int x, int dir)
{
	if (dir == 1)
	{
		up(y, x);
		right(y, x);
		left(y, x);

	}

	else if (dir == 2)
	{
		right(y, x);
		up(y, x);
		down(y, x);
	}


	else if (dir == 3)
	{
		right(y, x);
		left(y, x);
		down(y, x);
	}
	else
	{
		left(y, x);
		up(y, x);
		down(y, x);
	}
}

void CCTV_five(int y, int x)
{
	up(y, x);
	down(y, x);
	left(y, x);
	right(y, x);
}



void setCCTV_recursive(int cnt)
{
	int office_recur[8][8];
	copyArr(office_recur, office_tmp);

	if (cnt == cnt_CCTV)
	{
		int ans_tmp = numOfBlindSpot(office_tmp);
		ans = min(ans_tmp, ans);
		return;
	}

	else
	{
		

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
			
				
				int cat_CCTV = office_tmp[i][j];

				if (cat_CCTV > 0 && cat_CCTV < 6 && visited[i][j] == 0)
				switch (cat_CCTV)
				{
				case 1:
				{
					for (int r = 1; r <= 4; r++)
					{
						visited[i][j] = 1;
						CCTV_one(i, j, r);
						setCCTV_recursive(cnt + 1);
						visited[i][j] = 0;
						copyArr(office_tmp, office_recur);

					}

					return;
				}
				case 2:
				{
					for (int r = 1; r <= 4; r++)
					{
						visited[i][j] = 1;
						CCTV_two(i, j, r);
						setCCTV_recursive(cnt + 1);
						visited[i][j] = 0;

						copyArr(office_tmp, office_recur);

					}
					return;
				}

				case 3:
				{
					for (int r = 1; r <= 4; r++)
					{
						visited[i][j] = 1;
						CCTV_three(i, j, r);
						setCCTV_recursive(cnt + 1);
						visited[i][j] = 0;

						copyArr(office_tmp, office_recur);

					}
					return;
				}

				case 4:
				{
					for (int r = 1; r <= 4; r++)
					{
						visited[i][j] = 1;

						CCTV_four(i, j, r);
						setCCTV_recursive(cnt + 1);
						visited[i][j] = 0;

						copyArr(office_tmp, office_recur);

					}
					return;
				}

				case 5:
				{
					visited[i][j] = 1;

					CCTV_five(i, j);
					setCCTV_recursive(cnt + 1);
					visited[i][j] = 0;

					copyArr(office_tmp, office_recur);
					break;
				}
				default:
					return;

				}
			}
			
		}
	}

	return;

}


int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> office[i][j];
		}
	}
	copyArr(office_tmp, office);

	count_CCTV(office);

	setCCTV_recursive(0);

	cout << ans << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << office_tmp[i][j] << " " ;
		}
		cout << endl;
	}

}

