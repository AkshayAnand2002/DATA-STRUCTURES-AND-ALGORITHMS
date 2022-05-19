/*Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
Run two loops. In the outer loop, pick elements one by one from the left. 
In the inner loop, compare the picked element with the elements starting from the right side. 
Stop the inner loop when you see an element greater than the picked element and keep updating the maximum j-i so far. 
*/
// C program for the above approach
#include <stdio.h>
/* For a given array arr[],
returns the maximum j – i such
that arr[j] > arr[i] */
int maxIndexDiff(int arr[], int n)
{
	int maxDiff = -1;
	int i, j;

	for (i = 0; i < n; ++i) {
		for (j = n - 1; j > i; --j) {
			if (arr[j] > arr[i] && maxDiff < (j - i))
				maxDiff = j - i;
		}
	}
	return maxDiff;
}
int main()
{
	int arr[] = { 9, 2, 3, 4, 5, 6, 7, 8, 18, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int maxDiff = maxIndexDiff(arr, n);
	printf("\n %d", maxDiff);
	getchar();
	return 0;
}

