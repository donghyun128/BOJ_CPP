// 14502(연구소).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
int N, M;
int map[9][9];

int main()
{
	cin >> N >> M;

	for (int n = 1; n <= N; n++)
	{
		for (int m = 1; m <= M; m++)
		{
			cin >> map[n][m];
		}
	}


}

