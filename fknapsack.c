#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};
int i;
float fractionalKnapsack(int W, struct Item items[], int n) {
    for (i = 0; i < n - 1; i++) {
	for (int j = 0; j < n - i - 1; j++) {
	    if (items[j].ratio < items[j + 1].ratio) {
		struct Item temp = items[j];
		items[j] = items[j + 1];
		items[j + 1] = temp;
	    }
	}
    }
    float totalProfit = 0.0;
    for (i = 0; i < n; i++) {
	if (W >= items[i].weight) {
	    W -= items[i].weight;
	    totalProfit += items[i].profit;
	} else {
	    totalProfit += items[i].profit * ((float)W / items[i].weight);
	    break;
	}
    }
    return totalProfit;
}

void main() {
    int n, W;
    clock_t starttime, endtime;
    double timetaken;
    struct Item* items = (struct Item*)malloc(n * sizeof(struct Item));
    clrscr();
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter capacity of the knapsack: ");
    scanf("%d", &W);
    for (i = 0; i < n; i++) {
	printf("Enter weight and profit for item %d: ", i + 1);
	scanf("%d %d", &items[i].weight, &items[i].profit);
	items[i].ratio = (float)items[i].profit / items[i].weight;
    }
    starttime = clock();
    float maxProfit = fractionalKnapsack(W, items, n);
    endtime = clock();
    timetaken = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
    printf("Maximum profit is: %.2f\n", maxProfit);
    printf("Function took %lf seconds to execute\n", timetaken);
    free(items);
    getch();
}
