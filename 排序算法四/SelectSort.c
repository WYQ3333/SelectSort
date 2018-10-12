#include<stdio.h>
#include<Windows.h>

void swap(int *p, int *q)
{
	int *tmp = *q;
	*q = *p;
	*p = tmp;
}

void SelectSort(int array[], int size)
{
	int minspace = 0;
	int maxspace = size - 1;
	while (minspace < maxspace)
	{
		int minpos = minspace;
		int maxpos = maxspace;
		for (int i = minspace+1 ; i <= maxspace; i++)
		{
			if (array[i] <= array[minpos])
				minpos = i;
			if (array[i] >= array[maxpos])
				maxpos = i;
		}
		if (maxpos == minspace)
		{
			maxpos = minpos;
		}
		swap(&array[minpos], &array[minspace]);
		minspace++;
		if (array[maxpos]>array[maxspace])
			swap(&array[maxpos], &array[maxspace]);
		maxspace--;
	}
}

void test()
{
	int array[] = {10,9,8,7,6,5, 4, 3, 2, 1 };
	int size = sizeof(array) / sizeof(array[0]);
	SelectSort(array, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

int main()
{
	test();
	system("pause");
	return 0;
}