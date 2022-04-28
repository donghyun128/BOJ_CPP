#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <math.h>
using namespace std;

struct node
{
	int y, x;
};

struct ICE
{
	int num;
	vector<node> pos;
}; 

vector<ICE> iceVector;
vector<node> meltVector;

int N, Q;
int ice[64][64] = { 0 };
int ice_tmp[64][64] = { 0 };
int visited[64][64] = { 0 };
int level[1000] = {0};
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int mapLength = 0;
int allIce = 0;
int maxSize = 0;
void rotateEachDivide(int y, int x, int L)
{
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			ice_tmp[y+i][x+j] = ice[y+L - j - 1][x+i];
		}
	}
}

void divideAndRotate(int L)
{
	int gridLength = (int)pow(2, L);
	int mapLength = (int)pow(2, N);

	for (int p = 0; p < mapLength; p+=gridLength)
	{
		for (int q = 0; q < mapLength; q+=gridLength)
		{
			rotateEachDivide(p,q,gridLength);
		}
	}

	memcpy(ice, ice_tmp, sizeof(ice));
}

void meltIce()
{

	for (int i = 0; i < mapLength; i++)
	{
		for (int j = 0; j < mapLength; j++)
		{
			int cnt = 0;
			if (ice[i][j] == 0) continue;

			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= mapLength || nx >= mapLength) continue;
				if (ice[ny][nx] == 0) continue;
				cnt++;
			}

			if (cnt < 3) meltVector.push_back({ i,j });
		}
	}

	for (int k = 0; k < meltVector.size(); k++)
	{
		ice[meltVector[k].y][meltVector[k].x]--;
	}
	meltVector.clear();
}



void bfs(int y, int x, int num)
{
	queue<node> q;
	q.push({ y,x });
	visited[y][x] = num;

	vector<node> pos_v;

	while (!q.empty())
	{
		int cnt = 0;
		int cy = q.front().y;
		int cx = q.front().x;
		q.pop();
		pos_v.push_back({ cy,cx });

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= mapLength || nx >= mapLength) continue;
			if (ice[ny][nx] == 0) continue;

			if (visited[ny][nx] == -1 && ice[ny][nx] != 0)
			{
				q.push({ ny,nx });
				visited[ny][nx] = num;

			}

		}

	}

	iceVector.push_back({ num, pos_v});
	
}

void findIce()
{
	int num = 0;
	for (int i = 0; i < mapLength; i++)
	{
		for (int j = 0; j < mapLength; j++)
		{
			if (visited[i][j] == -1 && ice[i][j] > 0)
			{
				bfs(i, j,num);
				num++;
			}
		}
	}
	memset(visited, -1, sizeof(visited));
}


void fireStorm(int L,int cnt)
{
	divideAndRotate(L);
	meltIce();
	findIce();
	if (cnt == Q)
	{
		return;
	}
	iceVector.clear();

}


void input()
{
	memset(visited, -1, sizeof(visited));
	cin >> N >> Q;
	mapLength = pow(2, N);
	for (int i = 0; i < mapLength; i++)
	{
		for (int j = 0; j < mapLength; j++)
		{
			cin >> ice[i][j];
		}
	}
	for (int s = 0; s < Q; s++)
	{
		cin >> level[s];
	}
}

void getAnswer()
{

	for (int i = 0; i < mapLength; i++)
	{
		for (int j = 0; j < mapLength; j++)
		{
			allIce += ice[i][j];
		}
	}
}
void solution()
{

	for (int i = 0; i < Q; i++)
	{
		fireStorm(level[i],i+1);
	}

	getAnswer();

	for (int i = 0; i < iceVector.size(); i++)
	{
		if (iceVector[i].pos.size() > maxSize)
		{
			maxSize = iceVector[i].pos.size();
		}
	}
	
}

int main()
{
	input();
	solution();
	cout << allIce << "\n";
	cout << maxSize;
}

