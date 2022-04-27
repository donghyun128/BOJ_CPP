#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
#define MAX 100000
using namespace std;

struct node
{
	int y, x;
};

struct passenger
{
	int num;
	struct node start;
	struct node goal;
	int distance = MAX;
};

vector<passenger> p_vector;
vector<passenger> same_distance;

int dist[21][21];
int map[21][21] = { 0 };
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0};

int fuel;
int usedFuel = 0;
int N, M;
int carY, carX;

int selectSameDistancePassenger()
{
	int selectedIdx = 1;

	for (int i = 1; i < p_vector.size(); i++)
	{
		if (p_vector[i].distance < p_vector[selectedIdx].distance)
			selectedIdx = p_vector[i].num;
		else if (p_vector[i].distance > p_vector[selectedIdx].distance)
			continue;

		else {
			if (p_vector[i].start.y < p_vector[selectedIdx].start.y)
			{
				selectedIdx = p_vector[i].num;
			}
			else if (p_vector[i].start.y > p_vector[selectedIdx].start.y)
			{
				continue;
			}
			else
			{
				if (p_vector[i].start.x < p_vector[selectedIdx].start.x)
				{
					selectedIdx = p_vector[i].num;
				}
			}
		}
	}
	return selectedIdx;
}

int goToPassenger()
{
	bool visited[20][20] = { 0 };
	queue<node> q;

	q.push({ carY,carX });
	visited[carY][carX] = true;
	dist[carY][carX] = 0;

	while (!q.empty())
	{
		int cy = q.front().y;
		int cx = q.front().x;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
			if (!visited[ny][nx] && map[ny][nx] != 1)
			{
				visited[ny][nx] = true;
				q.push({ ny,nx });
				dist[ny][nx] = dist[cy][cx] + 1;
				
				if (dist[ny][nx] > fuel)
					return -1;

				if (map[ny][nx] < 0)
				{
					p_vector[-map[ny][nx]].distance = dist[ny][nx];
					//same_distance.push_back(p_vector[-map[ny][nx]]);
				}

			}

		}
	}

	int p_vectorIdx = selectSameDistancePassenger();
	//same_distance.clear();
	carY = p_vector[p_vectorIdx].start.y;
	carX = p_vector[p_vectorIdx].start.x;
	fuel -= dist[carY][carX];
	usedFuel = dist[carY][carX];

	return p_vectorIdx;
	
}


void moveToGoal(int vector_idx)
{
	int goalY = p_vector[vector_idx].goal.y;
	int goalX = p_vector[vector_idx].goal.x;

	bool visited[20][20] = { 0 };
	queue<node> q;

	q.push({ carY,carX });
	visited[carY][carX] = true;
	dist[carY][carX] = 0;

	while (!q.empty())
	{
		int cy = q.front().y;
		int cx = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
			if (!visited[ny][nx] && map[ny][nx] != 1)
			{
				visited[ny][nx] = true;
				q.push({ ny,nx });
				dist[ny][nx] = dist[cy][cx] + 1;

				if (dist[ny][nx] > fuel)
					return;

				if (ny == goalY && nx == goalX)
				{
					carY = goalY;
					carX = goalX;
					p_vector.erase(p_vector.begin() + vector_idx);
					usedFuel += dist[ny][nx];
					fuel += usedFuel * 2;
					usedFuel = 0;
					return;
				}
			


			}

		}
	}


}

int drive()
{
	while (1)
	{
		int passengerIdx = goToPassenger();
		if (fuel <= 0) return -1;
		memset(dist, 0, sizeof(dist));
		moveToGoal(passengerIdx);
		if (fuel <= 0) return -1;
		memset(dist, 0, sizeof(dist));
		if (p_vector.size() == 1)
			return fuel;
	}
}

void input()
{
	cin >> N >> M >> fuel;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}
	
	p_vector.push_back({ 0,NULL,NULL});

	cin >> carY >> carX;

	for (int i = 1; i <= M; i++)
	{
		int sy, sx, gy, gx;
		cin >> sy >> sx >> gy >> gx;
		p_vector.push_back({i,sy,sx,gy,gx });
		map[sy][sx] = -i;
	}
}

void solution()
{
	cout << drive();
}

int main()
{
	input();
	solution();
}