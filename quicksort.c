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

void quickSort(int A[], int l, int h) {
    if (l < h) {
        int p = partition(A, l, h + 1);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, h);
    }
}

void main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int A[n + 1];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    A[n] = __INT_MAX__;

    quickSort(A, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
