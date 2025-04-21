#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void Merge(int *A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    int i, j, k;
    for (i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = A[q + 1 + j];
    }
    i = 0; j = 0; k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}
void MergeSort(int *A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}
void main() {
    int n, k, i;
    int *A;
    A = (int *)malloc(n * sizeof(int));
    clock_t starttime,endtime;
    double timetaken;
    clrscr();
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    starttime = clock();
    MergeSort(A, 0, n - 1);
    endtime = clock();
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
	printf("%d ", A[i]);
    }
    printf("\nEnter k (for k-th smallest element): ");
    scanf("%d", &k);
    if (k >= 1 && k <= n)
        printf("The %dth smallest element is: %d", k, A[k - 1]);
    else
        printf("Invalid value of k!\n");

    free(A);
    timetaken = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f",timetaken);
    getch();
}
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l;
    int j = h;

    while (i < j) {
        do {
            i++;
        } while (A[i] < pivot);

        do {
            j--;
        } while (A[j] > pivot);

        if (i < j)
            swap(&A[i], &A[j]);
    }
    swap(&A[l], &A[j]);
    return j;
}

int kthSmallest(int A[], int l, int h, int k) {
    if (l <= h) {
        int pos = partition(A, l, h + 1);

        if (pos == k - 1)
            return A[pos];
        else if (pos > k - 1)
            return kthSmallest(A, l, pos - 1, k);
        else
            return kthSmallest(A, pos + 1, h, k);
    }
    return -1; 
}

void main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int A[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("Enter k (for k-th smallest element): ");
    scanf("%d", &k);

    int result = kthSmallest(A, 0, n - 1, k);
    if (result != -1)
        printf("The %d-th smallest element is: %d\n", k, result);
    else
        printf("Invalid input!\n");
}

