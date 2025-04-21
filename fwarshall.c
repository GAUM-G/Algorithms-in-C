#include <stdio.h> 
#include <conio.h>
#include <limits.h> 
#include <time.h> 
#define MAX_VERTICES 100 
void floydWarshall(int A[MAX_VERTICES][MAX_VERTICES], int n) { 
    int k, i, j; 
    
    for (k = 0; k < n; k++) { 
        for (i = 0; i < n; i++) { 
            for (j = 0; j < n; j++) { 
                if (A[i][k] != INT_MAX && A[k][j] != INT_MAX) { 
                    if (A[i][j] > A[i][k] + A[k][j]) { 
                        A[i][j] = A[i][k] + A[k][j]; 
                    } 
                } 
            } 
        } 
    } 
} 
void main() { 
    int n, i, j; 
    int A[MAX_VERTICES][MAX_VERTICES]; 
    clock_t starttime, endtime; 
    double timetaken;
    clrscr();
    printf("Enter number of vertices: "); 
    scanf("%d", &n); 
    printf("Enter the adjacency matrix (use 9999 for infinity):\n"); 
    for (i = 0; i < n; i++) { 
        for (j = 0; j < n; j++) { 
            scanf("%d", &A[i][j]); 
            if (A[i][j] == 9999) { 
                A[i][j] = INT_MAX; 
            } 
        } 
    } 
    starttime = clock(); 
    floydWarshall(A, n); 
    endtime = clock();  
    printf("The shortest path matrix is:\n"); 
    for (i = 0; i < n; i++) { 
        for (j = 0; j < n; j++) { 
            if (A[i][j] == INT_MAX) { 
                printf("INF "); 
            } else { 
                printf("%d ", A[i][j]); 
            } 
        } 
        printf("\n"); 
    } 
    timetaken = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
    printf("Time taken by the Floyd-Warshall algorithm: %lf seconds\n", timetaken); 
    getch(); 
}
