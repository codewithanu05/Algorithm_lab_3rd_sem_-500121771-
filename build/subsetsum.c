#include <stdio.h>

void printSubsets(int arr[], int n, int index, int subset[], int target, int sum) {
    if (index == n) {
        if (sum == target) {
            for (int i = 0; i < n; i++) {
                if (subset[i]) {
                    printf("%d ", arr[i]);
                }
            }
            printf("\n");
        }
        return;
    }
    subset[index] = 1;
    printSubsets(arr, n, index + 1, subset, target, sum + arr[index]);
    subset[index] = 0;
    printSubsets(arr, n, index + 1, subset, target, sum);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;
    int subset[n];
    for (int i = 0; i < n; i++) {
        subset[i] = 0;
    }
    printSubsets(arr, n, 0, subset, target, 0);
    return 0;
}
