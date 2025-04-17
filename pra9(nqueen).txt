#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int x[100];

int place(int k, int i) {
    for (int j = 1; j < k; j++) {
	if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
	    return 0;
	}
    }
    return 1;
}
void printSolution(int n) {
    for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= n; j++) {
	    if (x[i] == j) {
		printf("Q ");
	    } else {
		printf(". ");
	    }
	}
	printf("\n");
    }
    printf("\n");
}
void nqueen(int k, int n) {
    for (int i = 1; i <= n; i++) {
	if (place(k, i)) {
	    x[k] = i;
	    if (k == n) {
		printSolution(n);
	    } else {
		nqueen(k + 1, n);
	    }
	}
    }
}
void main() {
    int n;
    clock_t starttime, endtime;
    double timetaken;
    clrscr();
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    starttime = clock();
    nqueen(1, n);
    endtime = clock();
    timetaken = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", timetaken);
    getch();
}
