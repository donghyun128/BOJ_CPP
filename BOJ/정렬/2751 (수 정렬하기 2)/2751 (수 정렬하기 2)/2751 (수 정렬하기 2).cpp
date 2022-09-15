
#include <stdio.h>
#include <stdlib.h>
int arr[1000000];

void swap(int arr[], int idx1, int idx2)
{
	int tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}

int getRand(int s, int e) {
	int high = rand();
	int low = rand();
	int r = (high << 16) | low;

	return s + (r % (e - s + 1));
}

void quickSort(int arr[], int left, int right)
{
	int pivot = getRand(left, right);
	int low = left;
	int high = right;

	while (low <= high)
	{
		while (low <= right && arr[low] < arr[pivot])
			low++;
		while (high >= left && arr[high] > arr[pivot])
			high--;

		if (low <= high)
			swap(arr, low++, high--);
	}

	if (left < high)
		quickSort(arr, left, high);
	if (low < right)
		quickSort(arr, low, right);
	
}



int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	quickSort(arr, 0, N - 1);
	for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);
}

