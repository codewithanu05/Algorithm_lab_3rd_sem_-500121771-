#include <stdio.h>
int max(int a, int b) { return (a > b) ? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}
int main()
{
    int profit[] = { 100, 200, 150, 80, 125, 180 };
    int weight[] = { 5, 10, 15, 20, 25, 30 };
    printf("Weight - ");
    for(int i=0; i<6; i++){
        
        printf("%d  ", weight[i]);
    }
    printf("\n");
    printf("Profit - ");
    for(int i=0; i<6; i++){
        
        printf("%d  ", profit[i]);
    }
    printf("\n");
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    printf(" Max Profit:  %d  ", knapSack(W, weight, profit, n));
    return 0;
} 
