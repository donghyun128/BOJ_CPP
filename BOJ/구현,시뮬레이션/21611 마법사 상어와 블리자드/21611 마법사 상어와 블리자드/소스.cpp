#include <iostream>
#include <vector>
using namespace std;

struct coor
{
	int y, x;
};

struct spell
{
	int d, s;
};

struct mapInfo
{
	bool isCrushed;
	int bead;
};


int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

mapInfo map[50][50] = { false,0 };
mapInfo newMap[50][50] = { false,0 };
int N, M;
struct coor numList[2500];
struct coor newList[2500];
struct spell spellList[101];

int bombBreak[4] = { 0,0,0,0 };


void print()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << map[i][j].bead << "   " ;
		}
		cout << "\n\n";
	}
	cout << "-----------------\n";

}

void printNew()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << newMap[i][j].bead << "   ";
		}
		cout << "\n\n";
	}
	cout << "-----------------\n";

}


void initList()
{
	int curY = (N + 1) / 2;
	int curX = (N + 1) / 2;
	int curNum = 1;
	for (int i = 1; i < N; i+=2)
	{
		for (int s = 0; s < i; s++)
		{
			curX--;
			numList[curNum++] = { curY,curX };
		}

		for (int s = 0; s < i; s++)
		{
			curY++;
			numList[curNum++] = { curY,curX };
		}

		for (int s = 0; s < i+1; s++)
		{
			curX++;
			numList[curNum++] = { curY,curX };
		}

		for (int s = 0; s < i+1; s++)
		{
			curY--;
			numList[curNum++] = { curY,curX };
		}
	}

	for (int i = 0; i < N - 1; i++)
	{
		curX--;
		numList[curNum++] = { curY,curX };
	}
}

int blizzard(int idx)
{
	int cnt = 0;
	int sY = (N + 1) / 2;
	int sX = (N + 1) / 2;

	int dir = spellList[idx].d;
	int dist = spellList[idx].s;

	for (int i = 1; i <= dist; i++)
	{
		int cY = sY + dy[dir]*i;
		int cX = sX + dx[dir]*i;
		if (cY <= 0 || cX <= 0 || cY > N || cX > N) continue;
		map[cY][cX].bead = -1;
		map[cY][cX].isCrushed = true;
		cnt++;
	}
	return cnt;
}

void pullEmpty()
{	
	int crushedCnt = 0;

	for (int i = 1; i < N * N; i++)
	{
		if (map[numList[i].y][numList[i].x].bead > 0)
		{
			map[numList[i - crushedCnt].y][numList[i - crushedCnt].x].bead = map[numList[i].y][numList[i].x].bead;
			map[numList[i - crushedCnt].y][numList[i - crushedCnt].x].isCrushed = map[numList[i].y][numList[i].x].isCrushed;
			
			if (crushedCnt > 0 )
				map[numList[i].y][numList[i].x].bead = -1;

		}

		else if (map[numList[i].y][numList[i].x].isCrushed)
			crushedCnt++;
	
	}
	
}

bool bombard()
{
	int idx = 1;
	int cnt = 1;
	int flag = false;
	while (idx < N * N)
	{
		int curBead = map[numList[idx].y][numList[idx].x].bead;
		if (curBead > 0)
		{
			if (curBead != map[numList[idx + 1].y][numList[idx + 1].x].bead)
			{
				// Æø¹ß
				if (cnt >= 4)
				{
					flag = true;
					for (int i = cnt - 1; i >= 0; i--)
					{
						map[numList[idx - i].y][numList[idx - i].x].bead = -1;
						map[numList[idx - i].y][numList[idx - i].x].isCrushed = true;
					}
					bombBreak[curBead] += cnt;
				}
				cnt = 1;
			}
			else
			{
				cnt++;
			}
		}
		idx++;
	}
	return flag;
}

void initNewList()
{
	int curY = (N + 1) / 2;
	int curX = (N + 1) / 2;
	int curNum = 1;
	
	int newIdx = 1;
	int exIdx = 1;
	int cnt = 1;
	while (exIdx < N * N)
	{
		int curBead = map[numList[exIdx].y][numList[exIdx].x].bead;
		if (curBead == -1) break;
		
		else if (curBead == map[numList[exIdx + 1].y][numList[exIdx + 1].x].bead)
		{
			cnt++;
		}

		else
		{
			newMap[numList[newIdx].y][numList[newIdx].x] = { false,cnt};
			newMap[numList[newIdx+1].y][numList[newIdx+1].x] = { false,curBead };
			newIdx += 2;
			cnt = 1;
		}
		exIdx++;
	}

}

void copyMap()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			map[i][j] = {false,0};
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			map[i][j] = newMap[i][j];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			newMap[i][j] = { false,0 };
		}
	}
}

int calculateScore()
{
	return bombBreak[1] + 2 * bombBreak[2] + 3 * bombBreak[3];
}
void solution()
{
	initList();
	//print();
	
	for (int i = 0; i < M; i++)
	{
		blizzard(i);
		//print();
		pullEmpty();
		//print();

		while (bombard())
		{
			//print();
			pullEmpty();
			//print();
		}
		initNewList();
		//printNew();
		copyMap();
		//print();
	}
	cout << calculateScore();
}
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j].bead;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int dir, dist;
		cin >> dir >> dist;
		spellList[i] = { dir - 1,dist };
	}
	solution();
}