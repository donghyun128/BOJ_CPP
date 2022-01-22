// 14500(테트로미노).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define STICK 1
#define SQUARE 2
#define L 3
#define rL 4
#define T 5


int table[500][500] = { 0 };
int M, N;

typedef struct tetromino
{
	// 도형의 유형
	int category;
	// 도형의 대칭 여부
	bool symm;
	// 도형의 회전 횟수. 0~3번
	int rotate;

}Tetromino;

bool check_valid_coord(int n, int m)
{
	if (n < N && m < M)
		return true;
	else
		return false;
}

int compute_STICK(int n, int m)
{
	int max_score = 0;
	int score;
	int rotate;
	
	for (rotate = 0; rotate < 4; rotate++)
	{
		int cx = m;
		int cy = n;
		score = 0;

		switch(rotate)
		{
		case 0:
			for (int i = 1; i < 5; i++)
			{
				if (cx < M && cy < N)
				{
					score += table[cy][cx];
				}
				else 
				{
					score = 0;
					break;
				}
				cy += i;
			}
			if (score > max_score)
				max_score = score;
			break;

		case 1:
			for (int j = 1; j < 5; j++)
			{
				if (cx < M && cy < N)
				{
					score += table[cy][cx];
				}
				else
				{
					score = 0;
					break;
				}
				cx += j;
			}
			if (score > max_score)
				max_score = score;
			break;

		case 2:
			for (int i = 1; i < 5; i++)
			{
				if (cx < M && cy < N)
				{
					score += table[cy][cx];
				}
				else
				{
					score = 0;
					break;
				}
				cy -= i;
			}
			if (score > max_score)
				max_score = score;
			break;
		case 3:
			for (int j = 1; j < 5; j++)
			{
				if (cx < M && cy < N)
				{
					score += table[cy][cx];
				}
				else
				{
					score = 0;
					break;
				}
				cx -= j;
			}
			if (score > max_score)
				max_score = score;
			break;
		}
	}

	return max_score;
}

int compute_SQUARE(int n, int m)
{
	int max_score = 0;
	int score;
	int rotate = 0;

	for (rotate = 0; rotate < 4; rotate++)
	{
		int cy = n;
		int cx = m;
		score = 0;
		switch (rotate)
		{

		case 0:
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					if (cy + i < N && cx + j < M)
					{
						score += table[cy + i][cy + j];
					}
					else
					{
						score = 0;
						break;
					}
				}
			}
			if (score > max_score)
			{
				max_score = score;
			}
			break;
		case 1:
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					if (cy + i < N && cx + j < M)
					{
						score += table[cy + i][cy - j];
					}
					else
					{
						score = 0;
						break;
					}
				}
			}
			if (score > max_score)
			{
				max_score = score;
			}
			break;
		case 2:
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					if (cy + i < N && cx + j < M)
					{
						score += table[cy - i][cy - j];
					}
					else
					{
						score = 0;
						break;
					}
				}
			}
			if (score > max_score)
			{
				max_score = score;
			}
			break;
		case 3:
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					if (cy + i < N && cx + j < M)
					{
						score += table[cy - i][cy + j];
					}
					else
					{
						score = 0;
						break;
					}
				}
			}
			if (score > max_score)
			{
				max_score = score;
			}
			break;
		}
	}
	return max_score;
}

int compute_L(int n, int m)
{
	int max_score = 0;
	int score;
	int rotate = 0;
	int symm = 0;
	for (symm = 0; symm < 2; symm++)
	{
		
		for (rotate = 0; rotate < 4; rotate++)
		{
			int cy = n;
			int cx = m;
			score = 0;
			// 대칭 아닌 경우
			if (symm == 0)
			{
				switch (rotate)
				{
				case 0:
					score = table[cy][cx];
					cx--;
					for (int i = 0; i < 3; i++)
					{
						if (cy + i < N && cx < M)
						{
							score += table[cy+i][cx];
						}
						else
						{
							score = 0;
							break;
						}
					
					}
					if (score > max_score)
					{
						max_score = score;
					}
					break;
				case 1:
					score = table[cy][cx];
					cy--;
					for (int i = 0; i < 3; i++)
					{
						if (cy < N && cx + i < M)
						{
							score += table[cy][cx + i];
						}
						else
						{
							score = 0;
							break;
						}

						if (score > max_score)
						{
							max_score = score;
						}
					}
						break;
				case 2:
					score = table[cy][cx];
					cx++;
					for (int i = 0; i < 3; i++)
					{
						if (cy + i < N && cx < M)
						{
							score += table[cy + i][cx];
						}
						else
						{
							score = 0;
							break;
						}
						if (score > max_score)
						{
							max_score = score;
						}
					}
						break;
				case 3:
					score = table[cy][cx];
					cy++;
					for (int i = 0; i < 3; i++)
					{
						if (cy < N && cx - i < M)
						{
							score += table[cy][cx - i];
						}
						else
						{
							score = 0;
							break;
						}
						if (score > max_score)
						{
							max_score = score;
						}
						break;
					}
					}
					// 대칭 한 경우
					if (symm == 1)
					{
						switch (rotate)
						{
						case 0:
							score = table[cy][cx];
							cx++;
							for (int i = 0; i < 3; i++)
							{
								if (cy - i < N && cx < M)
								{
									score += table[cy - i][cx];
								}
								else
								{
									score = 0;
									break;
								}
								if (score > max_score)
								{
									max_score = score;
								}
								break;
							}
						case 1:
							score = table[cy][cx];
							cy++;
							for (int i = 0; i < 3; i++)
							{
								if (cy < N && cx + i < M)
								{
									score += table[cy][cx + i];
								}
								else
								{
									score = 0;
									break;
								}
								if (score > max_score)
								{
									max_score = score;
								}
								break;
							}
						case 2:
							score = table[cy][cx];
							cx--;
							for (int i = 0; i < 3; i++)
							{
								if (cy + i < N && cx < M)
								{
									score += table[cy + i][cx];
								}
								else
								{
									score = 0;
									break;
								}
								if (score > max_score)
								{
									max_score = score;
								}
								break;
							}
						case 3:
							score = table[cy][cx];
							cy--;
							for (int i = 0; i < 3; i++)
							{
								if (cy < N && cx - i < M)
								{
									score += table[cy][cx - i];
								}
								else
								{
									score = 0;
									break;
								}
								if (score > max_score)
								{
									max_score = score;
								}
								break;
							}
							}
							}
							}
							}
						}
						return max_score;
					}
					
int compute_rL(int n, int m)
{
	int max_score = 0;
	int score;
	int rotate = 0;
	int symm = 0;
	for (symm = 0; symm < 2; symm++)
	{
		
		for (rotate = 0; rotate < 4; rotate++)
		{
			int cy = n;
			int cx = m;
			score = 0;
			// 대칭 아닌 경우
			if (symm == 0)
			{
				switch (rotate)
				{
				case 0:
					for (int i = 0; i < 2; i++)
					{
						if (cy < N && cx < M)
						{
							score += table[cy - i][cx];
						}
						else
						{
							score = 0;
							break;
						}

					}
					cy--; cx--;
					for (int i = 0; i < 2; i++)
					{
						if (cy < N && cx < M)
						{
							score += table[cy - i][cx];
						}
						else
						{
							score = 0;
							break;
						}

					}

					break;
					if (score > max_score)
					{
						max_score = score;
					}
					break;
				case 1:
					for (int j = 0; j < 2; j++)
					{
						if (cy < N && cx < M)
						{
							score += table[cy + j][cx];
						}
						else
						{
							score = 0;
							break;
						}

					}
					cy--; cx++;
					for (int j = 0; j < 2; j++)
					{
						if (cy < N && cx < M)
						{
							score += table[cy + j ][cx];
						}
						else
						{
							score = 0;
							break;
						}

					}
					break;
					if (score > max_score)
					{
						max_score = score;
					}
					break;
				case 2:
					for (int i = 0; i < 2; i++)
					{
						if (cy < N && cx < M)
						{
							score += table[cy + i][cx];
						}
						else
						{
							score = 0;
							break;
						}

					}
					cy++; cx++;
					for (int i = 0; i < 2; i++)
					{
						if (cy < N && cx < M)
						{
							score += table[cy + i][cx];
						}
						else
						{
							score = 0;
							break;
						}

					}
					break;
					if (score > max_score)
					{
						max_score = score;
					}
					break;
				case 3:
					for (int j = 0; j < 2; j++)
					{
						if (cy < N && cx < M)
						{
							score += table[cy - j][cx];
						}
						else
						{
							score = 0;
							break;
						}

					}
					cy++; cx--;
					for (int j = 0; j < 2; j++)
					{
						if (cy < N && cx < M)
						{
							score += table[cy - j][cx];
						}
						else
						{
							score = 0;
							break;
						}

					}
					break;
					if (score > max_score)
					{
						max_score = score;
					}
					break;
				}
			}
			// 대칭 한 경우
			if (symm == 1)
			{
				switch (rotate)
				{
				case 0:
					for (int i = 0; i < 2; i++)
					{
						if (cy < N && cx < M)
						{
							score += table[cy - i][cx];
						}
						else
						{
							score = 0;
							break;
						}

					}
					cy--; cx++;
					for (int i = 0; i < 2; i++)
					{
						if (cy < N && cx < M)
						{
							score += table[cy - i][cx];
						}
						else
						{
							score = 0;
							break;
						}

					}
					if (score > max_score)
					{
						max_score = score;
					}
					break;

				case 1:
					for (int j = 0; j < 2; j++)
					{
						if (cy < N && cx < M)
						{
							score += table[cy + j][cx];
						}
						else
						{
							score = 0;
							break;
						}

					}
					cy++; cx++;
					for (int j = 0; j < 2; j++)
					{
						if (cy < N && cx < M)
						{
							score += table[cy + j][cx];
						}
						else
						{
							score = 0;
							break;
						}

					}
					if (score > max_score)
					{
						max_score = score;
					}
					break;
				case 2:
					for (int i = 0; i < 2; i++)
					{
						if (cy < N && cx < M)
						{
							score += table[cy + i][cx];
						}
						else
						{
							score = 0;
							break;
						}

					}
					cy++; cx--;
					for (int i = 0; i < 2; i++)
					{
						if (cy < N && cx < M)
						{
							score += table[cy + i][cx];
						}
						else
						{
							score = 0;
							break;
						}

					}
					if (score > max_score)
					{
						max_score = score;
					}
					break;
				case 3:
					for (int j = 0; j < 2; j++)
					{
						if (cy < N && cx < M)
						{
							score += table[cy - j][cx];
						}
						else
						{
							score = 0;
							break;
						}

					}
					cy--; cx--;
					for (int j = 0; j < 2; j++)
					{
						if (cy < N && cx < M)
						{
							score += table[cy - j][cx];
						}
						else
						{
							score = 0;
							break;
						}

					}
					if (score > max_score)
					{
						max_score = score;
					}
					break;
				}
			}
		}
	}
	return max_score;
}

int compute_T(int n, int m)
{
	int max_score = 0;
	int score;
	int rotate = 0;
	int symm = 0;
	for (symm = 0; symm < 2; symm++)
	{
		
		for (rotate = 0; rotate < 4; rotate++)
		{
			int cy = n;
			int cx = m;
			score = 0;
			// 대칭 아닌 경우
				switch (rotate)
				{
				case 0:
					for (int j = 0; j < 3; j++)
					{
						if (cy < N && cx + j < M)
						{
							score += table[cy][cx + j];
						}
						else
						{
							score = 0;
							break;
						}
						if (cy + 1 < N && cx + 1 < M)
						{
							score += table[cy + 1][cx + 1];
						}
						else
						{
							score = 0;
							break;
						}
					}
					if (score > max_score)
					{
						max_score = score;
					}
					break;
				case 1:
					for (int i = 0; i < 3; i++)
					{
						if (cy < N && cx + i < M)
						{
							score += table[cy][cx + i];
						}
						else
						{
							score = 0;
							break;
						}
						if (cy + 1 < N && cx - 1 < M)
						{
							score += table[cy + 1][cx - 1];
						}
						else
						{
							score = 0;
							break;
						}
					}
					if (score > max_score)
					{
						max_score = score;
					}
					break;
				case 2:
					for (int j = 0; j < 3; j++)
					{
						if (cy < N && cx - j < M)
						{
							score += table[cy][cx - j];
						}
						else
						{
							score = 0;
							break;
						}
						if (cy - 1 < N && cx - 1 < M)
						{
							score += table[cy - 1][cx - 1];
						}
						else
						{
							score = 0;
							break;
						}
					}
					if (score > max_score)
					{
						max_score = score;
					}
					break;
				case 3:

					for (int i = 0; i < 3; i++)
					{
						if (cy < N && cx - i < M)
						{
							score += table[cy][cx - i];
						}
						else
						{
							score = 0;
							break;
						}
						if (cy - 1 < N && cx + 1 < M)
						{
							score += table[cy - 1][cx + 1];
						}
						else
						{
							score = 0;
							break;
						}
					}

					if (score > max_score)
					{
						max_score = score;
					}
					break;
				}
			
			
			
		}
	}
	return max_score;
}

int computeScore(int n, int m)
{
	int max_score = 0;
	int score;
	max_score = compute_STICK(n, m);

	score = compute_SQUARE(n, m);
	if (score > max_score)
		max_score = score;

	score = compute_L(n, m);
	if (score > max_score)
		max_score = score;

	score = compute_rL(n, m);
	if (score > max_score)
		max_score = score;

	score = compute_T(n, m);
	if (score > max_score)
		max_score = score;

	return max_score;

}

int main()
{
	int max_score = 0;
	int score = 0;
	scanf("%d %d",&N,&M);
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			scanf("%d", &table[n][m]);
		}
	}

	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			score = computeScore(n, m);
			if (score > max_score)
				score = max_score;
			
		}
	}

	printf("%d", max_score);

}
