#include <stdio.h>

struct Job {
    int id;  
    int deadline; 
    int profit;   
};
void sortJobsByProfit(struct Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (jobs[j].profit > jobs[maxIdx].profit) {
                maxIdx = j; 
            }
        }
        if (maxIdx != i) {
            struct Job temp = jobs[i];
            jobs[i] = jobs[maxIdx];
            jobs[maxIdx] = temp;
        }
    }
}
void jobScheduling(struct Job jobs[], int n) {
    sortJobsByProfit(jobs, n); 
    int result[n];
    int slot[n];  
    for (int i = 0; i < n; i++)
        slot[i] = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = (jobs[i].deadline < n ? jobs[i].deadline : n) - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                slot[j] = jobs[i].id; 
                break;
            }
        }
    }
    printf("Scheduled Jobs: ");
    for (int i = 0; i < n; i++) {
        if (slot[i] != 0) 
            printf("%d ", slot[i]); 
    }
    printf("\n");
}

int main() {
    struct Job jobs[] = {
        {1, 1, 10},
        {2, 2, 5},
        {3, 1, 8},
        {4, 2, 3}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    jobScheduling(jobs, n); 
    return 0;
}