#include<stdio.h>
#include<conio.h>
#include<time.h>
void main () {
    int a[100];
    int n,i,j,key;
    clock_t starttime,endtime;
    double timetaken;
    clrscr();
    printf("Enter size of array: ");
    scanf("%d",&n);
    printf("Enter elements : \n");
    for(i=1;i<=n;i++) {
	scanf("%d",&a[i]);
    }
    starttime=clock();
    for(j=2;j<=n;j++) {
	key=a[j];
	i=j-1;
	while(i>0 && a[i]>key) {
	    a[i+1]=a[i];
	    i=i-1;
	}
	a[i+1]=key;
    }
    endtime=clock();
    timetaken = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
    printf("Sorted Array: \n");
    for(i=1;i<=n;i++) {
	printf("%d ",a[i]);
    }
    printf("\nTime taken: %f",timetaken);
    getch();
}
