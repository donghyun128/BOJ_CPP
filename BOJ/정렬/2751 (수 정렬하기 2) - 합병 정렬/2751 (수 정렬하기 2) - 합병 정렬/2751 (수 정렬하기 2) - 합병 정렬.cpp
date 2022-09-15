// 2751 (수 정렬하기 2) - 합병 정렬.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>

int tmpArr[1000000];
int arr[1000000];

void mergeTwoArea(int arr[],int left,int right,int mid)
{
	int lidx = left;
	int ridx = mid+1;
	int nidx = left;

	while (lidx <= mid && ridx <= right)
	{
		if (arr[lidx] < arr[ridx])
			tmpArr[nidx] = arr[lidx++];
		else
			tmpArr[nidx] = arr[ridx++];
		nidx++;
	}

	if (lidx > mid)
	{
		for (int i = ridx; i <= right; i++, nidx++)
			tmpArr[nidx] = arr[i];
	}
	else
	{
		for (int i = lidx; i <= mid; i++, nidx++)
			tmpArr[nidx] = arr[i];
	}

	for (int i = left; i <= right; i++)
	{
		arr[i] = tmpArr[i];
	}

}

void mergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		mergeTwoArea(arr, left, right, mid);
	}

}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	mergeSort(arr, 0, N - 1);
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", arr[i]);
	}
}

