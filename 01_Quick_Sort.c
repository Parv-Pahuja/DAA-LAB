// Parv Pahuja - 25070521089

#include <stdio.h>

// Quick Sort function
void quickSort(int arr[], int low, int high) {
	// Complete the code...

	if (low < high) {
		int pivot = arr[low];
		int i = low + 1;
		int j = high;

		while (1) {
			while (i <= high && arr[i] <= pivot) {
				i++;
			}
			while (arr[j] > pivot) {
				j--;
			}
			if (i < j) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			} else {
				break;
			}
		}

		// Swap pivot with arr[j]
		int temp = arr[low];
		arr[low] = arr[j];
		arr[j] = temp;

		quickSort(arr, low, j - 1);
}
