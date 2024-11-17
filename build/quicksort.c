#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to place the pivot in its correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot element
    int i = low - 1;        // Pointer for smaller element

    // Rearrange elements based on the pivot
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);  // Swap the pivot to the correct position
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Get the partition index
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
	int m;
	printf("Enter the size of array : ");
	scanf("%d",&m);
	int arr[m];
	printf("Enter the elements of array : \n");
	for(int i=0;i<m;i++){
		scanf("%d",&arr[i]);
	}

    

    printf("Unsorted array: ");
    printArray(arr, m);

    quickSort(arr, 0, m - 1);

    printf("Sorted array: ");
    printArray(arr, m);

    return 0;
}
