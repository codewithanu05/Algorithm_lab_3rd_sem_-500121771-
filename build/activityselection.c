#include <stdio.h>
void sortActivities(int n, int start[], int end[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (end[i] > end[j]) {
                int tempEnd = end[i];
                end[i] = end[j];
                end[j] = tempEnd;
                int tempStart = start[i];
                start[i] = start[j];
                start[j] = tempStart;
            }
        }
    }
}
void activitySelection(int n, int start[], int end[]) {
    sortActivities(n, start, end);
    int count = 1;
    int lastSelectedEnd = end[0];
    printf("Selected activities:\n");
    printf("(%d, %d)\n", start[0], end[0]);
    for (int i = 1; i < n; i++) {
        if (start[i] >= lastSelectedEnd) {
            printf("(%d, %d)\n", start[i], end[i]);
            lastSelectedEnd = end[i];
            count++;
        }
    }
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);
    activitySelection(n, start, end);

    return 0;
}
