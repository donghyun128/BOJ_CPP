#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int N;
vector<int> dragonCurve[20];
bool map[101][101] = { 0 };
int next_tmp[3] = { 0 };
// 방향을 나타내는 정보들을 벡터에 저장. 스택처럼 사용.
vector<int> allDirection;

pair<int, int> zeroGenerationEndCoordiate(int y,int x,int d)
{
	if (d == 0)
	{
		return make_pair(y, x + 1);
	}
	else if (d == 1)
	{
		return make_pair(y-1, x );

	}

	else if (d == 2)
	{
		return make_pair(y, x -1);

	}

	else if (d == 3)
	{
		return make_pair(y + 1, x );
	}
}

int getDirection(int curDir)
{
	if (curDir == 0) // right
		return 1; // up

	if (curDir == 1) // up
		return 2; // left
	 
	if (curDir == 2) // left
		return 3; // down

	if (curDir == 3) // down
		return 0; // right
}

// 기존 세대의 방향 정보에 따라 다음 방향을 결정. ex) 3번째 방향 정보는 0번째 방향에 의해 결정, 2번째 방향은 1번째 방향에 의해 결정. 
void getAllDirection(int dir, int gen)
{
	
	allDirection.push_back(dir);

	if (gen == 0)
		return;

		for (int curGen = 0; curGen < gen; curGen++)
		{
			if (curGen == 0)
			{
				allDirection.push_back(getDirection(dir));
				continue;
			}

			int curIdx =  pow(2,curGen) -1;
			for (int j = curIdx; j >= 0; j--)
			{
				allDirection.push_back(getDirection(allDirection[j]));
			}
		}
}

void drawDragonCurve(int start_y, int start_x,int dir,int gen)
{
	getAllDirection(dir, gen);
	int cur_y = start_y;
	int cur_x = start_x;
	int ny;
	int nx;

	for (int i = 0; i < allDirection.size(); i++)
	{
		if (cur_y < 0 || cur_y > 100 || cur_x < 0 || cur_x > 100)
			return;

		map[cur_y][cur_x] = 1;

		int cur_dir = allDirection[i];
		pair<int, int> next = zeroGenerationEndCoordiate(cur_y, cur_x,cur_dir);
		ny = next.first;
		nx = next.second;

		cur_y = ny;
		cur_x = nx;

	}
	map[cur_y][cur_x] = 1;
}
/*
void makeDragonCurve(int start_y,int start_x,int dir,int gen,int* next)
{
	map[start_y][start_x] = true;

	if (gen == 0)
	{
		map[start_y][start_x] = true;
		pair<int, int> nextCoord = zeroGenerationEndCoordiate(start_y, start_x, dir);
		int ny = nextCoord.first;
		int nx = nextCoord.second;
		int nd = getNextDirection(dir);
		

		next_tmp[0] = ny;
		next_tmp[1] = nx;
		next_tmp[2] = nd;
		if (ny >= 0 && ny < 100 && nx >= 0 && nx < 100)
		{
			map[ny][nx] = true;
		}
		else return;
	}
	else {
		int nextInfo[3] = { 0 };

		makeDragonCurve(start_y, start_x, dir, gen - 1, nextInfo);
		memcpy(next, next_tmp, sizeof(int) * 3);

		int cy = next[0];
		int cx = next[1];
		int cd = next[2];

		if (cy >= 0 && cy < 100 && cx >= 0 && cx < 100)
		{
			makeDragonCurve(cy, cx, cd, gen - 1, next);
			memcpy(next, next_tmp, sizeof(int) * 3);

		}
	}
}
*/

int countSquare()
{
	int cnt = 0 ;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
				cnt++;
		}
	}
	return cnt;
}

void testPrint()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j=0; j<20; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}
void input()
{
	int x, y, d, g;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y >> d >> g;
		dragonCurve[i].push_back(y);
		dragonCurve[i].push_back(x);
		dragonCurve[i].push_back(d);
		dragonCurve[i].push_back(g);
	}
	
}

void solution()
{
	for (int i = 0; i < N; i++)
	{
		int start_y = dragonCurve[i][0];
		int start_x = dragonCurve[i][1];
		int start_dir = dragonCurve[i][2];
		int gen = dragonCurve[i][3];
		drawDragonCurve(start_y, start_x, start_dir, gen);
		/*
		for (int i = 0; i < allDirection.size(); i++)
			cout << allDirection[i] << " ";
		cout << "\n";
		*/
		while (!allDirection.empty())
			allDirection.pop_back();
	}
	cout << countSquare();
}


int main()
{
	input();
	solution();
	//testPrint();
}

