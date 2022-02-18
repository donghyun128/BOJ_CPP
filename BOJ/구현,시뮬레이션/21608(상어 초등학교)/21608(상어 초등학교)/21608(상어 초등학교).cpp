

#include <iostream>
#include <vector>
using namespace std;

/*
	1. 인접한 칸에 좋아하는 친구가 가장 많은 빈 칸으로 간다
	2. 1을 만족하는 칸이 여러개면, 인접한 칸 중에 비어있는 칸이 가장 많은 칸으로 간다
	3. 2를 만족하는 칸이 여러개면, 행의 번호가 가장 작은 칸으로
		, 그게 여러개면 열의 번호가 가장 작은 칸으로 간다.
*/

int N;
int room[21][21] = { 0 };
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
vector<int> like[21];

int cntStudentLike(int studentNum,int y,int x)
{
	int cnt = 0;
	for (int r = 0; r < 4; r++)
	{
		int adjY = y + dy[r];
		int adjX = x + dx[r];
		if (adjY >= 1 && adjY <= N && adjX >= 1 && adjX <= N)
		{
			for (int s = 0; s < like[studentNum].size(); s++)
			{
				if (like[studentNum][s] == room[adjY][adjX])
				{
					cnt++;
					break;
				}
				
			}
		}
	}
	return cnt;
}

int cntAdjacentBlank(int y, int x)
{
	int cnt = 0;
	for (int r = 0; r < 4; r++)
	{
		int adjY = y + dy[r];
		int adjX = x + dx[r];
		if (adjY >= 1 && adjY <= N && adjX >= 1 && adjX <= N)
		{			
				if (room[adjY][adjX] == 0)
					cnt++;	
		}
	}
	return cnt;
}

void ifSameBlank(int studentNum,int y1,int x1,int y2,int x2)
{
	if (y1 < y2)
	{
		room[y1][x1] = studentNum;
	}

	else if (y1 == y2)
	{
		if (x1 <= x2)
			room[y1][x1] = studentNum;
		else
			room[y2][x2] = studentNum;
	}

	else
	{
		room[y2][x2] = studentNum;
	}
}

void requirement1()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{

		}
	}
}


void input()
{
	cin >> N;
	for (int i = 1; i <= N * N; i++)
	{
		int studentNum;
		cin >> studentNum;
		for (int s = 0; s < 4; s++)
		{
			int whoLike;
			cin >> whoLike;
			like[studentNum].push_back(whoLike);
		}
	}
}





int main()
{

}

