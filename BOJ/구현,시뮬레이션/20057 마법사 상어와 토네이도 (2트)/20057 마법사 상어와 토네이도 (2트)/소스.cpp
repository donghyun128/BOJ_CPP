#include <iostream>
#include <math.h>
using namespace std;

int N;
int answer = 0;
int sand[500][500] = { 0 };


int dy[12] = {-2,-1,-1,-1,0,0,0,0,1,1,1,2};
int dx[12] = {0,-1,0,1,-2,-1,1,2,-1,0,1,0};

int ddiry[4] = { 0,1,0,-1 };
int ddirx[4] = { -1,0,1,0 };



int rate[4][12] = {
					{2,10,7,1,5,0,0,0,10,7,1,2},
					{0,1,0,1,2,7,7,2,10,0,10,5},
					{2,1,7,10,0,0,0,5,1,7,10,2},
					{5,10,0,10,2,7,7,2,1,0,1,0}
};

void moveOneBlock(int y,int x,int dir)
{
	int cy = y + ddiry[dir];
	int cx = x + ddirx[dir];

	if (cy < 0 || cx < 0 || cy >= N || cx >= N)
	{
		//answer += sand[y][x];
		return;
	}

	int curSand = sand[cy][cx];
	int sandLeft = curSand;

	for (int i = 0; i < 12; i++)
	{
		int ny = cy + dy[i];
		int nx = cx + dx[i];
		int spreaded = (int)(sand[cy][cx] * rate[dir][i] * 0.01);
		sandLeft -= spreaded;

		if (ny >= 0 && nx >= 0 && ny < N && nx < N)
			sand[ny][nx] += spreaded;
		else
			answer += spreaded;
	}


	if (cy + ddiry[dir] < 0 || cx + ddirx[dir] < 0 || cy + ddiry[dir] >= N || cx + ddirx[dir] >= N)
		answer += sandLeft;
	else
		sand[cy + ddiry[dir]][cx + ddirx[dir]] += sandLeft;
	
	sand[cy][cx] = 0;

}

void moveMultipleBlock(int y, int x, int dir,int dist)
{
	int curY = y;
	int curX = x;
	for (int i = 0; i < dist; i++)
	{
		moveOneBlock(curY, curX, dir);
		curY += ddiry[dir];
		curX += ddirx[dir];
	}
}

void tornado()
{
	int startY = N / 2;
	int startX = N / 2;
	
	for (int i = 1; i < N; i+=2 )
	{
			moveMultipleBlock(startY, startX, 0, i);
			startY += ddiry[0] * i;
			startX += ddirx[0] * i;
			moveMultipleBlock(startY, startX, 1, i);
			startY += ddiry[1] * i;
			startX += ddirx[1] * i;

			moveMultipleBlock(startY, startX, 2, i + 1);
			startY += ddiry[2] * (i + 1);
			startX += ddirx[2] * (i + 1);
			moveMultipleBlock(startY, startX, 3, i + 1);
			startY += ddiry[3] * (i + 1);
			startX += ddirx[3] * (i + 1);
	}
	moveMultipleBlock(startY, startX, 0, N);
	startY += ddiry[0] * N;
	startX += ddirx[0] * N;
	
	
}

int main()
{

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> sand[i][j];
		}
	}

	tornado();
	cout << answer << "\n";
}


