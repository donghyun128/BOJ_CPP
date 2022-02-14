
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

#define CLOCKWISE 1
#define COUNTER_CLOCKWISE 0
#define N 0
#define S 1

int gearMk1[8] = { 0 };
int gearMk2[8] = { 0 };
int gearMk3[8] = { 0 };
int gearMk4[8] = { 0 };

int K;

queue<pair<int, int>> sequence;

// N극 : 0, S극 : 1

void rotateMk1(int, int);
void rotateMk2(int, int);
void rotateMk3(int, int);
void rotateMk4(int, int);


void input()
{

	for (int i = 0; i < 4; i++)
	{
		string tmp;
		cin >> tmp;
		for (int p = 0; p < 8; p++)
		{
			if (i == 0)
				gearMk1[p] = tmp[p] - '0';

			else if (i == 1)
				gearMk2[p] = tmp[p] - '0';

			else if (i == 2)
				gearMk3[p] = tmp[p] - '0';

			else if (i == 3)
				gearMk4[p] = tmp[p] - '0';
		}
	}

	cin >> K;

	for (int k = 0; k < K; k++)
	{
		// 1 : 시계방향 , 2 : 반시계방향
		int gear;
		int rotate;
		cin >> gear >> rotate;;
		sequence.push(make_pair(gear, rotate));
	}
}

void testPrint()
{
	for (int i = 0; i < 8; i++)
	{
		cout << gearMk1[i];
	}
	cout << "\n";
	for (int i = 0; i < 8; i++)
	{
		cout <<gearMk2[i];
	}
	cout << "\n";

	for (int i = 0; i < 8; i++)
	{
		cout << gearMk3[i];
	}
	cout << "\n";

	for (int i = 0; i < 8; i++)
	{
		cout <<gearMk4[i];
	}
	cout << "\n";

	for (int k = 0; k < K; k++)
	{
		cout << sequence.front().first << " "<< sequence.front().second << endl;
		sequence.pop();
		cout << endl;
	}

}

// 시계방향
int* arr_shiftRight(int beforeShift[])
{
	int afterShift[8] = { 0 };

	for (int i = 1; i < 8; i++)
	{
		afterShift[i] = beforeShift[i - 1];
	}
	afterShift[0] = beforeShift[7];

	return afterShift;
}

// 시계반대방향
int* arr_shiftLeft(int beforeShift[])
{
	int afterShift[8] = { 0 };

	for (int i = 0; i < 7; i++)
	{
		afterShift[i] = beforeShift[i + 1];
	}
	afterShift[7] = beforeShift[0];
	return afterShift;
}

void rotateMk1(int dir, int from)
{
	if (from == 1)
	{
		// 시계방향
		if (dir == CLOCKWISE)
		{
			if (gearMk1[2] != gearMk2[6])
			{
				rotateMk2(COUNTER_CLOCKWISE, 1);
			}
			memcpy(gearMk1, arr_shiftRight(gearMk1), 8*sizeof(int));
		}

		// 반시계방향
		else
		{
			if (gearMk1[2] != gearMk2[6])
			{
				rotateMk2(CLOCKWISE, 1);
			}
			memcpy(gearMk1, arr_shiftLeft(gearMk1), 8 * sizeof(int));

		}
	}

	// 2가 회전했을 때 
	else if (from == 2)
	{
		if (dir == CLOCKWISE)
		{
			if (gearMk2[6] != gearMk1[2])
			{
				memcpy(gearMk1, arr_shiftRight(gearMk1), 8 * sizeof(int));
			}
		}
		else
		{
			if (gearMk2[6] != gearMk1[2])
			{
				memcpy(gearMk1, arr_shiftLeft(gearMk1), 8 * sizeof(int));
			}
		}
	}
}

void rotateMk2(int dir,int from)
{

	if (from == 1)
	{
		// 시계방향
		if (dir == CLOCKWISE)
		{
			if (gearMk1[2] != gearMk2[6])
			{
				rotateMk3(COUNTER_CLOCKWISE, 2);
				memcpy(gearMk2, arr_shiftRight(gearMk2), 8 * sizeof(int));
			}
		}

		// 반시계방향
		else
		{
			if (gearMk1[2] != gearMk2[6])
			{
				rotateMk3(CLOCKWISE, 2);
				memcpy(gearMk2, arr_shiftLeft(gearMk2), 8 * sizeof(int));
			}

		}
	}

	else if (from == 2)
	{
		// 시계방향
		if (dir == CLOCKWISE)
		{
			if (gearMk1[2] != gearMk2[6])
			{
				rotateMk1(COUNTER_CLOCKWISE, 2);
			}

			if (gearMk3[6] != gearMk2[2])
			{
				rotateMk3(COUNTER_CLOCKWISE, 2);
			}

			memcpy(gearMk2, arr_shiftRight(gearMk2), 8 * sizeof(int));

		}

		// 반시계방향
		else
		{
			if (gearMk1[2] != gearMk2[6])
			{
				rotateMk1(CLOCKWISE, 2);
			}

			if (gearMk3[6] != gearMk2[2])
			{
				rotateMk3(CLOCKWISE, 2);
			}

			memcpy(gearMk2, arr_shiftLeft(gearMk2), 8 * sizeof(int));

		}
	}

	else if (from == 3)
	{
		// 시계방향
		if (dir == CLOCKWISE)
		{
			if (gearMk2[2] != gearMk3[6])
			{
				rotateMk1(COUNTER_CLOCKWISE, 2);
				memcpy(gearMk2, arr_shiftRight(gearMk2), 8 * sizeof(int));
			}
		}

		// 반시계방향
		else
		{
			if (gearMk2[2] != gearMk3[6])
			{
				rotateMk1(CLOCKWISE, 2);
				memcpy(gearMk2, arr_shiftLeft(gearMk2), 8 * sizeof(int));
			}

		}
	}

}

void rotateMk3(int dir,int from)
{
	if (from == 2)
	{
		// 시계방향
		if (dir == CLOCKWISE)
		{
			if (gearMk2[2] != gearMk3[6])
			{
				rotateMk4(COUNTER_CLOCKWISE, 3);
				memcpy(gearMk3, arr_shiftRight(gearMk3), 8 * sizeof(int));
			}
		}

		// 반시계방향
		else
		{
			if (gearMk2[2] != gearMk3[6])
			{
				rotateMk4(CLOCKWISE, 3);
				memcpy(gearMk3, arr_shiftLeft(gearMk3), 8 * sizeof(int));
			}

		}
	}

	else if (from == 3)
	{
		// 시계방향
		if (dir == CLOCKWISE)
		{
			if (gearMk2[2] != gearMk3[6])
			{
				rotateMk2(COUNTER_CLOCKWISE, 3);
			}

			if (gearMk4[6] != gearMk3[2])
			{
				rotateMk4(COUNTER_CLOCKWISE, 3);
			}

			memcpy(gearMk3, arr_shiftRight(gearMk3), 8 * sizeof(int));

		}

		// 반시계방향
		else
		{
			if (gearMk2[2] != gearMk3[6])
			{
				rotateMk2(CLOCKWISE, 3);
			}

			if (gearMk4[6] != gearMk3[2])
			{
				rotateMk4(CLOCKWISE, 3);
			}

			memcpy(gearMk3, arr_shiftLeft(gearMk3), 8 * sizeof(int));

		}
	}

	else if (from == 4)
	{
		// 시계방향
		if (dir == CLOCKWISE)
		{
			if (gearMk3[2] != gearMk4[6])
			{
				rotateMk2(COUNTER_CLOCKWISE, 3);
				memcpy(gearMk3, arr_shiftRight(gearMk3), 8 * sizeof(int));
			}
		}

		// 반시계방향
		else
		{
			if (gearMk3[2] != gearMk4[6])
			{
				rotateMk2(CLOCKWISE, 3);
				memcpy(gearMk3, arr_shiftLeft(gearMk3), 8 * sizeof(int));
			}

		}
	}
}

void rotateMk4(int dir, int from)
{
	
	if (from == 3)
	{
		// 시계방향
		if (dir == CLOCKWISE)
		{
			if (gearMk3[2] != gearMk4[6])
			{
				memcpy(gearMk4, arr_shiftRight(gearMk4), 8 * sizeof(int));
			}
		}

		// 반시계방향
		else
		{
			if (gearMk3[2] != gearMk4[6])
			{
				memcpy(gearMk4, arr_shiftLeft(gearMk4), 8 * sizeof(int));
			}

		}
	}

	else if (from == 4)
	{
		if (dir == CLOCKWISE)
		{
			if (gearMk3[2] != gearMk4[6])
			{
				rotateMk3(COUNTER_CLOCKWISE, 4);
			}
			memcpy(gearMk4, arr_shiftRight(gearMk4), 8 * sizeof(int));


		}

		else
		{
			if (gearMk3[2] != gearMk4[6])
			{
				rotateMk3(CLOCKWISE, 4);
			}
			memcpy(gearMk4, arr_shiftLeft(gearMk4), 8 * sizeof(int));

		}
	}

}

void rotateStart(int gear_num, int dir)
{
	switch(gear_num)
	{
	case 1:
		rotateMk1(dir, 1);
		break;


	case 2:
		rotateMk2(dir, 2);
		break;

	case 3:
		rotateMk3(dir, 3);
		break;

	case 4:
		rotateMk4(dir, 4);
		break;
		
	default:
		break;
	}
}

int countScore()
{
	int score = 0;

	if (gearMk1[0] == S)
		score += 1;
	if (gearMk2[0] == S)
		score += 2;
	if (gearMk3[0] == S)
		score += 4;
	if (gearMk4[0] == S)
		score += 8;

	return score;
}

void solution()
{

	while (!sequence.empty())
	{
		int gear_num = sequence.front().first;
		int dir = sequence.front().second;
		sequence.pop();

		rotateStart(gear_num, dir);
	}
	
	cout << countScore();
}




//  시계방향 : 11101011 -> 11110101 (shift right)
// 반시계방향 : 11101011 -> 11010111 (shift left)


int main()
{
	input();
	solution();
	//testPrint();

}

