// 21608(상어 초등학교)-2트.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{
	int num;
	int like[4];
};

struct adjacentInfo
{
	int y, x, adj_like_student, adj_empty;
};
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

int N;
int score = 0;
int maxAdjEmpty = 0;
int maxAdjFriend = 0;
int map[20][20] = { 0 };
int studentIdx[20];
struct adjacentInfo mapInfo[20][20];
vector<struct student> studentList;
vector<struct adjacentInfo> maxAdjFriendList;
vector<struct adjacentInfo> maxAdjEmptyList;



void valueInit()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			mapInfo[i][j] = {};
	}
	maxAdjFriendList.clear();
	maxAdjEmptyList.clear();
	maxAdjEmpty = 0;
	maxAdjFriend = 0;
}

void updateMapInfo(int sIndex)
{


		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int adjEmptyNum = 0;
				int adjFriendNum = 0;
				if (map[i][j] != 0)
					continue;
				for (int d = 0; d < 4; d++)
				{
					int y = i + dy[d];
					int x = j + dx[d];
					if (y < 0 || x < 0 || y >= N || x >= N) continue;
					if (map[y][x] == 0)
						adjEmptyNum++;
					else if (map[y][x] > 0)
					{
						for (int f = 0; f < 4; f++)
						{
							if (studentList[sIndex].like[f] == map[y][x])
							{
								adjFriendNum++;
							}
						}
					}
					
				}
				mapInfo[i][j] = { i,j,adjFriendNum,adjEmptyNum };

				maxAdjEmpty = max(maxAdjEmpty, adjEmptyNum);
				maxAdjFriend = max(maxAdjFriend, adjFriendNum);
			}
		}
	
}

void allocateStudent(int sIndex)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (mapInfo[i][j].adj_like_student == maxAdjFriend)
				maxAdjFriendList.push_back(mapInfo[i][j]);
		}
	}

	if (maxAdjFriendList.size() > 1)
	{
		int maxEmptyNum = 0;
		for (int s = 0; s < maxAdjFriendList.size(); s++)
		{
			maxEmptyNum = max(maxEmptyNum, maxAdjFriendList[s].adj_empty);
		}

		for (int s = 0; s < maxAdjFriendList.size(); s++)
		{
			if (maxAdjFriendList[s].adj_empty == maxEmptyNum)
				maxAdjEmptyList.push_back(maxAdjFriendList[s]);
		}


		if (maxAdjEmptyList.size() == 1)
			map[maxAdjEmptyList[0].y][maxAdjEmptyList[0].x] = studentList[sIndex].num;
		else if (maxAdjEmptyList.size() > 1)
		{
			int goalY = 1000;
			int goalX = 1000;

			for (int f = 0; f < maxAdjEmptyList.size(); f++)
			{
				if (maxAdjEmptyList[f].y < goalY)
				{
					goalY = maxAdjEmptyList[f].y;
					goalX = maxAdjEmptyList[f].x;
				}
				else if (maxAdjEmptyList[f].y == goalY)
				{
					if (maxAdjEmptyList[f].x < goalX)
					{
						goalY = maxAdjFriendList[f].y;
						goalX = maxAdjFriendList[f].x;
					}
					
				}
			}
			map[goalY][goalX] = studentList[sIndex].num;
		}

	}

	else
	{
		map[maxAdjFriendList[0].y][maxAdjFriendList[0].x] = studentList[sIndex].num;
	}
}

int scoreFormula(int cnt)
{
	if (cnt == 0)
		return 0;
	else if (cnt == 1)
		return 1;
	else if (cnt == 2)
		return 10;
	else if (cnt == 3)
		return 100;
	else
		return 1000;
}

void calculateScore()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int adjCnt = 0;
			for (int d = 0; d < 4; d++)
			{
				int y = i + dy[d];
				int x = j + dx[d];
				if (y < 0 || x < 0 || y >= N || x >= N) continue;
				for (int l = 0; l < 4; l++)
				{
					if (map[y][x] == studentList[studentIdx[map[i][j]]].like[l])
					{
						adjCnt++;
						break;
					}
				}
			}
			score += scoreFormula(adjCnt);
		}
	}
}

void solution()
{
	for (int p = 0; p < N*N; p++)
	{
		valueInit();
		updateMapInfo(p);
		allocateStudent(p);
	}

		calculateScore();
	
}

int main()
{
	cin >> N;
	for (int i = 0; i < N*N; i++)
	{
		struct student s_student;
		int student_num;
		int a, b, c, d;
		cin >> student_num >> a >> b >> c >> d;
		s_student.num = student_num;
		s_student.like[0] = a;
		s_student.like[1] = b;
		s_student.like[2] = c;
		s_student.like[3] = d;
		studentList.push_back(s_student);
		studentIdx[student_num] = studentList.size() - 1;

	}
	solution();
	cout << score;
}
