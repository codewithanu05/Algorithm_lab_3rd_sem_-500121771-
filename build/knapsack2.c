#include <stdio.h>

int knapsackBacktracking(int weights[], int values[], int n, int capacity) {
    if (n == 0 || capacity == 0)
        return 0;

    if (weights[n-1] > capacity)
        return knapsackBacktracking(weights, values, n-1, capacity);

    int include = values[n-1] + knapsackBacktracking(weights, values, n-1, capacity - weights[n-1]);
    int exclude = knapsackBacktracking(weights, values, n-1, capacity);

    return (include > exclude) ? include : exclude;
}

typedef struct {
    int level, profit, weight;
    float bound;
} Node;

float bound(Node u, int n, int W, int weights[], int values[]) {
    if (u.weight >= W)
        return 0;
    
    int j = u.level + 1;
    int totalWeight = u.weight;
    float result = u.profit;

    while (j < n && totalWeight + weights[j] <= W) {
        totalWeight += weights[j];
        result += values[j];
        j++;
    }

    if (j < n)
        result += (W - totalWeight) * values[j] / weights[j];

    return result;
}

int knapsackBranchBound(int W, int weights[], int values[], int n) {
    Node u, v;
    int maxProfit = 0;
    u.level = -1;
    u.profit = u.weight = 0;
    u.bound = bound(u, n, W, weights, values);

    if (u.bound > maxProfit) {
        if (u.bound > maxProfit) {
            maxProfit = u.profit;
        }
    }
    
    return maxProfit;
}

int knapsackDP(int W, int weights[], int values[], int n) {
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i-1] <= w)
                dp[i][w] = (values[i-1] + dp[i-1][w - weights[i-1]]) > dp[i-1][w] ? 
                            (values[i-1] + dp[i-1][w - weights[i-1]]) : dp[i-1][w];
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);
    int choice;

    printf("Select the approach:\n");
    printf("1. Backtracking\n");
    printf("2. Branch & Bound\n");
    printf("3. Dynamic Programming\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Maximum value (Backtracking): %d\n", knapsackBacktracking(weights, values, n, capacity));
            break;
        case 2:
            printf("Maximum value (Branch & Bound): %d\n", knapsackBranchBound(capacity, weights, values, n));
            break;
        case 3:
            printf("Maximum value (Dynamic Programming): %d\n", knapsackDP(capacity, weights, values, n));
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
