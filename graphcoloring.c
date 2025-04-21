#include <stdio.h> 
#include <conio.h>
#include <stdlib.h>
#define MAX 100
#include <time.h>
int n, m, G[MAX][MAX], x[MAX];

int nextvalue(int k) {
    while (1) {
	x[k] = (x[k] + 1) % (m + 1);
	if (x[k] == 0)
	    return 0;
	int j;
	for (j = 1; j <= n; j++) {
	    if (G[k][j] != 0 && x[k] == x[j])
		break;
	}
	if (j == n + 1)
	    return 1;
    }
}

void mcolouring(int k) {
    while (1) {
	if (!nextvalue(k))
	    return;
	if (k == n) {
	    int i;

	    for (i = 1; i <= n; i++) {
		printf("%d ", x[i]);
	    }
	    printf("\n");
	} else {
	    mcolouring(k + 1);
	}
    }
}

void main() {
    int i, j;
    clock_t starttime, endtime;
    double timetaken;
    clrscr();
    printf("Enter number of vertices (n): ");
    scanf("%d", &n);
    printf("Enter number of colors (m): ");
    scanf("%d", &m);
    printf("Enter adjacency matrix (0 for no edge, 1 for edge):\n");
    for (i = 1; i <= n; i++) {
	for (j = 1; j <= n; j++) {
	    scanf("%d", &G[i][j]);
	}
    }
    for (i = 1; i <= n; i++) {
	x[i] = 0;
    }
    printf("\nValid colorings:\n");
    starttime = clock();
    mcolouring(1);
    endtime = clock();
    timetaken = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", timetaken);
    getch();
}
