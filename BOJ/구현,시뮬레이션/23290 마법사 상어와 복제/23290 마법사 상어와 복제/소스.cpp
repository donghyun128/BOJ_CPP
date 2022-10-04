#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dy_fish[9] = {0,0,-1,-1,-1,0,1,1,1};
int dx_fish[9] = {0,-1,-1,0,1,1,1,0,-1 };

int dy_shark[5] = {0,-1,0,1,0};
int dx_shark[5] = {0,0,-1,0,1};



vector<int> fish_map[5][5];
vector<int> copied_map[5][5];
vector<int> imitate_map[5][5];
int scent_map[5][5];
vector<vector<int>> sequenceVector;

vector<int> moveSequence;

int shY;
int shX;
int M, S;



void writeSequence(int cnt)
{
	if (cnt == 3)
	{
		sequenceVector.push_back(moveSequence);
		return;
	}

	for (int i = 1; i <= 4; i++)
	{
		moveSequence.push_back(i);
		writeSequence(cnt + 1);
		moveSequence.pop_back();
	}
}

void imitateMap()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 0; k < fish_map[i][j].size(); k++)
			{
				imitate_map[i][j].push_back(fish_map[i][j][k]);
			}
		}
	}
}


void moveFish()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 0; k < fish_map[i][j].size(); k++)
			{
				int dir = fish_map[i][j][k];
				int ny, nx;
				bool flag = false;
				for (int l = 0; l < 8; l++)
				{
					ny = i + dy_fish[dir];
					nx = j + dx_fish[dir];
					if (ny >= 1 && nx >= 1 && ny <= 4 && nx <= 4)
					{
						if (scent_map[ny][nx] == 0 && (shY != ny || shX != nx))
						{
							flag = true;
							break;
						}
					}
					dir--;
					if (dir == 0) dir = 8;
				}
				
				if (flag)
					copied_map[ny][nx].push_back(dir);

				

				else
					copied_map[i][j].push_back(fish_map[i][j][k]);
				
			}
		}
	}

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 0; k < fish_map[i][j].size(); k++)
			{
				fish_map[i][j].clear();
			}
			for (int k = 0; k < copied_map[i][j].size(); k++)
				fish_map[i][j].push_back(copied_map[i][j][k]);
		}
	}
}

void sharkMove(int time)
{
	int MAX = 0;
	for (int k = 0; k < sequenceVector.size(); k++)
	{
		bool visited[5][5] = { false };
		int ny = shY;
		int nx = shX;
		int get = 0;
		bool OOB = false;
		for (int i = 0; i < 3; i++)
		{
			ny += dy_shark[sequenceVector[k][i]];
			nx += dx_shark[sequenceVector[k][i]];

			if (ny <= 0 || nx <= 0 || ny > 4 || nx > 4)
			{
				OOB = true;
				break;
			}
			if (visited[ny][nx] == false)
			{
				get += fish_map[ny][nx].size();
				visited[ny][nx] = true;
			}
		}
		if (!OOB)
			MAX = max(get, MAX);
	}

	vector<vector<int>> maxSequence;

	for (int k = 0; k < sequenceVector.size(); k++)
	{
		bool visited[5][5] = { false };
		int ny = shY;
		int nx = shX;
		int get = 0;
		bool OOB = false;
		for (int i = 0; i < 3; i++)
		{
			ny += dy_shark[sequenceVector[k][i]];
			nx += dx_shark[sequenceVector[k][i]];

			if (ny <= 0 || nx <= 0 || ny > 4 || nx > 4)
			{
				OOB = true;
				break;
			}

			if (!visited[ny][nx])
			{
				get += fish_map[ny][nx].size();
				visited[ny][nx] = true;
			}
		}
		if (!OOB && MAX == get && (ny >= 1 && nx >= 1 && ny <=4 && nx <=4))
			maxSequence.push_back(sequenceVector[k]);
	}

	int ny = shY;
	int nx = shX;

	for (int i = 0; i < 3; i++)
	{
		ny += dy_shark[maxSequence[0][i]];
		nx += dx_shark[maxSequence[0][i]];
		if (fish_map[ny][nx].size() > 0)
		{
			scent_map[ny][nx] = time;
			fish_map[ny][nx].clear();
		}
	}

	shY = ny;
	shX = nx;

}

void evaporateScent(int time)
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if ((time - scent_map[i][j] == 2))
				scent_map[i][j] = 0;
			
		}
	}
}

void imitateComplete()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 0; k < imitate_map[i][j].size(); k++)
			{
				fish_map[i][j].push_back(imitate_map[i][j][k]);

			}
		}
	}
}

int getLeftFishNumber()
{
	int ret = 0;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			ret += fish_map[i][j].size();
		}
	}
	return ret;
}

void clearMap()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			imitate_map[i][j].clear();
			copied_map[i][j].clear();
		}
	}
}
void solution()
{
	writeSequence(0);
	for (int i = 1; i <= S; i++)
	{
		imitateMap();
		moveFish();
		sharkMove(i);
		evaporateScent(i);
		imitateComplete();
		clearMap();
	}
	cout << getLeftFishNumber();
}

int main()
{
	cin >> M >> S;
	for (int i = 0; i < M; i++)
	{
		int fx, fy, dir;
		cin >> fy >> fx >> dir;
		fish_map[fy][fx].push_back(dir);
	}

	cin >> shY >> shX;

	solution();
	
}

