#include <stdio.h>
#include <conio.h>
#include <time.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}

void main() {
    int val[100], wt[100], dp[100][100];
    int n, cap, i, w;
    clock_t starttime,endtime;
    double timetaken;
    clrscr();
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter values of items: ");
    for (i = 0; i < n; i++)
        scanf("%d", &val[i]);
    printf("Enter weights of items: ");
    for (i = 0; i < n; i++)
        scanf("%d", &wt[i]);
    printf("Enter knapsack capacity: ");
    scanf("%d", &cap);
    starttime = clock();
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= cap; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    endtime = clock();
    printf("Max value = %d", dp[n][cap]);
    timetaken = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds", timetaken);
    getch();
}
