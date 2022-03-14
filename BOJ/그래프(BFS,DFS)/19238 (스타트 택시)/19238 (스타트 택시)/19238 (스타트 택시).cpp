#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int N, M, fuel;
pair<int, int> start_coor;
vector<pair<int, int>> passenger;
vector<pair<int, int>> goal;

int map[20][20] = { 0 };
int dy[4] = {0,0,-1,1};
int dx[4] = { -1,1,0,0 };



int findPassenger()
{
	int distance = 0;

	bool visited[20][20] = { false };
	queue<int, int> q;

	visited[start_coor.first][start_coor.second] = true;
	q.push(make_pair(start_coor.first, start_coor.second));

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int ny = cy + dy[k];
			int nx = cx + dx[k];

			if (ny >= 0 && ny < N && nx >= 0 && nx < N)
			{
				if (!visited[ny][nx] && map[ny][nx] != 1)
				{
					visited[ny][nx] = true;
					q.push(make_pair(ny, nx));
					if (map[ny][nx] == 2)
						passenger.push_back(make_pair(ny, nx));
				}
			}
		}

		distance++;

		if (!passenger.empty())
			return distance;
	}
}

pair<int,int> passengerPriority()
{
	int y = passenger.back().first;
	int x = passenger.back().second;
	passenger.pop_back();

	while (!passenger.empty())
	{
		int cy = passenger.back().first;
		int cx = passenger.back().second;
		passenger.pop_back();

		if (cy < y)
		{
			y = cy;
			x = cx;
		}

		else if (cy == y)
		{
			if (cx < x)
			{
				y = cy;
				x = cx;
			}
		}
	}

	return make_pair(y, x);
}

void deliverPassenger()
{

}




void input()
{
	int passenger_y, passenger_x, goal_y, goal_x;
	cin >> N >> M >> fuel;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	cin >> start_coor.first >> start_coor.second;

	for (int k = 0; k < M; k++)
	{
		cin >> passenger_y >> passenger_x >> goal_y >> goal_x;
		map[passenger_y][passenger_x] = 2;
		map[goal_y][goal_x] = 3;
	}

}

int main()
{
}

