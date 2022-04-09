

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>>  num_count_v; // first : 숫자 값 , second : 나온 횟수

int A[101][101] = { 0 };
int A_tmp[101][101] = { 0 };

int R, C, K;

int row_size = 3;
int col_size = 3;

int pre_row_size = 3;
int pre_col_size = 3;


void incrementCount(int num)
{
	for (int v = 0; v < num_count_v.size(); v++)
	{
		if (num_count_v[v].second == num)
		{
			num_count_v[v].first += 1;
			return;
		}
	}
	num_count_v.push_back(make_pair(1, num));
}

void copyArr()
{
	if (col_size > 100)
		col_size = 100;
	if (row_size > 100)
		row_size = 100;

	for (int r = 1; r <= col_size; r++)
	{
		for (int c = 1; c <= row_size; c++)
		{
			A[r][c] = A_tmp[r][c];
		}
	}

	if (pre_row_size > row_size)
	{
		for (int r = 1; r <= col_size; r++)
		{
			for (int c = row_size + 1; c <= pre_row_size; c++)
				A[r][c] = 0;
		}
	}

	if (pre_col_size > col_size)
	{
		for (int r = col_size + 1; r <= pre_col_size; r++)
		{
			for (int c = 1; c <= row_size; c++)
				A[r][c] = 0;
		}
	}

}

void clearMapTmp()
{
	if (col_size > 100)
		col_size = 100;
	if (row_size > 100)
		row_size = 100;

	for (int r = 1; r <= row_size; r++)
	{
		for (int c = 1; c <= col_size; c++)
		{
			A_tmp[r][c] = 0;
		}
	}
}

void rowSort()
{
	int rowLength = 0;

	for (int r = 1; r <= col_size; r++)
	{
		for (int c = 1; c <= row_size; c++)
		{
			if (A[r][c] != 0)
				incrementCount(A[r][c]);
		}
		sort(num_count_v.begin(), num_count_v.end());
		if (num_count_v.size() * 2 > rowLength)
			rowLength = num_count_v.size() * 2;
		for (int s = 0; s <num_count_v.size(); s++)
		{


			A_tmp[r][2 * s + 1] = num_count_v[s].second;
			A_tmp[r][2 * (s + 1)] = num_count_v[s].first;
		}
		num_count_v.clear();
	}

	row_size = rowLength;
}

void colSort()
{
	int colLength = 0;

	for (int c = 1; c <= row_size; c++)
	{
		for (int r = 1; r <= col_size; r++)
		{
			if (A[r][c]!= 0)
				incrementCount(A[r][c]);
		}
		sort(num_count_v.begin(), num_count_v.end());
		if (num_count_v.size() * 2 > colLength)
			colLength = num_count_v.size() * 2;

		for (int s = 0; s < num_count_v.size(); s++)
		{
			A_tmp[2 * s + 1][c] = num_count_v[s].second;
			A_tmp[2 * (s + 1)][c] = num_count_v[s].first;
		}
		num_count_v.clear();
	}

	col_size = colLength;
}

void secondProcess()
{
	pre_row_size = row_size;
	pre_col_size = col_size;

	if (col_size >= row_size)
	{
		rowSort();
	}
	else
	{
		colSort();
	}

	copyArr();
	clearMapTmp();
}

int sortHundredSec()
{
	int s = 0;
	while (s < 100)
	{
		if (A[R][C] == K)
		{
			return s;
		}
		secondProcess();
		s++;
	}

	return -1;
}

void input()
{
	cin >> R >> C >> K;
	for (int r = 1; r <= 3; r++)
	{
		for (int c = 1; c <= 3; c++)
		{
			cin >> A[r][c];
		}
	}
}

void solution()
{
	input();
	cout << sortHundredSec();
}

int main()
{
	solution();
}

