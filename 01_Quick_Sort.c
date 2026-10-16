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

		quickSort(arr, j + 1, high);
	}
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    // Input the size of the array
    scanf("%d", &n);
    int arr[n];
    
    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printArray(arr, n);

    // Sort the array using quick sort
    quickSort(arr, 0, n - 1);
    
    // Print the sorted array
    printArray(arr, n);

    return 0;
}
