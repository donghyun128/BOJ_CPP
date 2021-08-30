// 5430 (AC).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;

int func_D(int arr[], int size,int updated_size)
{
	if (updated_size == 0)
		return 1;
	else {
		for (int i = 0; i < size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}

		for (int i = size-1; i >= updated_size; i--)
			arr[i] = 0;
		return 0;
	}
}

int func_D_Reverse(int arr[], int size, int updated_size)
{
	if (updated_size == 0)
		return 1;
	else {
		for (int i = size-1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		
		for (int i = 0; i < size - updated_size; i++)
			arr[i] = 0;

		return 0;
	}
}


int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		// 입력부
		//////////////////////////////////////////////////////////////////
		int arr[100000] = { 0 };
		int arr_size;
		int index = 0;
		int isError = 0;
		string str_arr;
		string func;
		cin >> func;
		cin >> arr_size;
		cin >> str_arr;
		//////////////////////////////////////////////////////////////////
		// 숫자 문자열을 정수배열로 저장
		/////////////////////////////////////////////////////////////////

		if (arr_size == 0)
		{
			isError = 1;
			cout << "error" << endl;
		}
		else {

			for (int i = 0; i < arr_size; i++)
			{
				int digit = 0;
				index++;
				int start_index = index;
				while (1)
				{
					if ((str_arr[index] == ',') || (str_arr[index] == ']'))
						break;
					index++;
					digit++;
				}

				for (int j = start_index; j < index; j++)
				{
					arr[i] += (str_arr[j] - '0') * pow(10, digit - 1);
					digit--;
				}
			}
			///////////////////////////////////////////////////////////////
			//함수 실행부
			///////////////////////////////////////////////////////////////
			int updated_size = arr_size;
			int isReversed = 0;
			for (int c = 0; c < func.length(); c++)
			{

				if (func[c] == 'R')
				{
					isReversed++;
				}
				else if (func[c] == 'D')
				{
					updated_size--;
					if (isReversed % 2 == 1)
						isError = func_D_Reverse(arr, arr_size, updated_size);
					else
						isError = func_D(arr, arr_size, updated_size);
				}

				if (isError)
					break;
			}

			///////////////////////////////////////////////////////////////
			// 출력부
			///////////////////////////////////////////////////////////////


			if (isError)
				printf("error\n");
			else
			{
				cout << "[";
				if (isReversed % 2 == 0) {
					for (int k = 0; k < updated_size; k++)
					{
						cout << arr[k];
						if (k != updated_size - 1)
							cout << ",";
					}
				}

				else
				{
					for (int k = arr_size - 1; k >= arr_size - updated_size; k--)
					{
						if (arr[k] != 0)
							cout << arr[k];
						if (k != arr_size - updated_size)
							cout << ",";
					}
				}

				cout << "]" << endl;
			}

		}
	}
}

