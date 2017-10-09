//C_test

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define print(x)   printf("the no, "#x",is ") 



void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

void bubble_sort(int arr[], int len) 
{
	int i, j, temp;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1]) 
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void max_heapify(int arr[], int start, int end) {
	//建立父節點指標和子節點指標
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { //若子節點指標在範圍內才做比較
		if (son + 1 <= end && arr[son] < arr[son + 1]) //先比較兩個子節點大小，選擇最大的
			son++;
		if (arr[dad] > arr[son]) //如果父節點大於子節點代表調整完畢，直接跳出函數
			return;
		else { //否則交換父子內容再繼續子節點和孫節點比較
			swap(&arr[dad], &arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(int arr[], int len) {
	int i;
	//初始化，i從最後一個父節點開始調整
	for(i = (len - 1)/2; i >= 0; i--)
		max_heapify(arr, i, len-1);
	//先將第一個元素和已排好元素前一位做交換，再從新調整，直到排序完畢
	for (i = len - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}

void test77() {
	//int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
	int *arr = (int *)malloc(sizeof(int) * 100000000);
	//int len = (int) sizeof(arr) / sizeof(*arr);
	int len = 100000000;
	int i;
	for (i = len - 1; i >= 0; i--)
	{
		arr[i] = len - i;
	}
	for (i = 0; i < 1000; i++)
		printf("%d ", arr[i]);
	heap_sort(arr, len);

	for (i = 0; i < 1000; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return;
}

void Msort(int *array, int size, int *tmp)
{
	int i, j, k;
	if (size == 1)
	{
		return;
	}

	Msort(array, size/2, tmp);
	Msort(array + size/2, size - size/2, tmp);

	// merge two sorted list
	for (i = 0, j = size/2, k = 0; i < size/2 || j < size;)
	{
		if (j == size)
		{
			tmp[k++] = array[i++];
			continue;
		}

		if (i == size/2)
		{
			tmp[k++] = array[j++];
			continue;
		}

		if (array[i] < array[j])
		{
			tmp[k++] = array[i++];
		}
		else
		{
			tmp[k++] = array[j++];
		}
	}

	for (i = 0; i < size; i++)
	{
		array[i] = tmp[i];
	}
}

void MergeSort(int *array, int size)
{
	int *tmp = (int *)malloc(size * sizeof(int));
	Msort(array, size, tmp);

	free(tmp);
}

void Qsort(int *array, int size)
{  	
	int pivot, i, j, tmp;

	if (size == 0 || size == 1)
	{
		return;
	}

	pivot = array[0];

	// divide array to two subarray, left is smaller than pivot, right is larger.
	for (i = 1, j = size - 1; i <= j;)
	{
		if (array[i] <= pivot)
		{
			i++;
			continue;
		}

		if (array[j] > pivot)
		{
			j--;
			continue;
		}
		
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;

		i++;
	}

	tmp = array[i - 1];
	array[i - 1] = pivot;
	array[0] = tmp;

	Qsort(array, i - 1);
	Qsort(array + i, size - i);

}  

void test88()
{
	
	int array[] = {14,1,5,78,9,8,88,99,54,666,524,48875,546,5125,1144,2255,3366,74,854,521,2,5,44,6659,3354,4477};

	int i, n;

	n = sizeof(array) / sizeof(int);

	for (i = 0; i < n; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("\n");

	MergeSort(array, n);	

	for (i = 0; i < n; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("\n");

}

void initArray(int *array, int size)
{
	int i;
	
	for (i = 0; i < size; i++)
	{
		array[i] = rand() % 99;
	}
	
/*
	for (i = 0; i < (size < 1000 ? size : 1000); i++)
		printf("%d ", array[i]);

	printf("\n");	*/


	return;
}

int verifySortedArray(int *array, int size)
{
	int i;
	
	for (i = 0; i < size - 1; i++)
	{
		if (array[i + 1] < array[i])
		{
			printf("verify failed. array[%d] = %d,  array[%d] = %d\n", i, array[i], i+1, array[i+1]);
			return 0;
		}
	}

	return 1;
}


void testSort()
{
	//int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
	int len = 10;
	int *arr = (int *)malloc(sizeof(int) * len);
	//int len = (int) sizeof(arr) / sizeof(*arr);
	
	int i;
	clock_t begin, end;
	double time_spent;

	for (i = 1; i < 20; i++)
	{
		srand(i);

		printf("test %d...\n", i);

		initArray(arr, len);

		begin = clock();
		MergeSort(arr, len);
		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("MergeSort timing %f\n", time_spent);

		if (!verifySortedArray(arr, len))
		{
			printf("verify failed!!");
		}

		initArray(arr, len);

		begin = clock();
		Qsort(arr, len);
		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("Qsort timing %f\n", time_spent);

		if (!verifySortedArray(arr, len))
		{
			printf("verify failed!!");
		}


		initArray(arr, len);

		begin = clock();
		heap_sort(arr, len);
		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("heap_sort timing %f\n", time_spent);

		if (!verifySortedArray(arr, len))
		{
			printf("verify failed!!");
		}

		initArray(arr, len);

		begin = clock();
		bubble_sort(arr, len);
		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("bubble_sort timing %f\n", time_spent);

		if (!verifySortedArray(arr, len))
		{
			printf("verify failed!!");
		}


		printf("\n");
	}

	return;
}