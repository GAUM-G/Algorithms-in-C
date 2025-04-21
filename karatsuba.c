#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
int get_digit_count(long long num) {
    int count = 0;
    while (num > 0) {
        count++;
        num = num / 10;
    }
    return count;
}

long long karatsuba(long long x, long long y) {
    if (x < 10 && y < 10) {
        return x * y;
    }
    int max_digit = (get_digit_count(x) > get_digit_count(y)) ? get_digit_count(x) : get_digit_count(y);
    if (max_digit < 10) {
        return x * y;
    }
    int half_size = (max_digit / 2) + (max_digit % 2);
    long long multiplier = (long long)pow(10, half_size);
    long long high_x = x / multiplier;
    long long low_x = x % multiplier;
    long long high_y = y / multiplier;
    long long low_y = y % multiplier;
    long long part1 = karatsuba(high_x, high_y);
    long long part2 = karatsuba(high_x + low_x, high_y + low_y);
    long long part3 = karatsuba(low_x, low_y);
    return part1 * (long long)pow(10, 2 * half_size) + (part2 - part1 - part3) * multiplier + part3;
}

int main() {
    long long x, y, result;
    clock_t starttime,endtime;
    double timetaken;
    clrscr();  
    printf("ENTER FIRST NUMBER: \n");
    scanf("%lld", &x);
    printf("ENTER THE SECOND NUMBER: \n");
    scanf("%lld", &y);
    starttime = clock();
    result = karatsuba(x, y);
    endtime = clock();
    printf("THE PRODUCT IS %lld \n", result);
    timetaken = ((double) (endtime-starttime)) / CLOCKS_PER_SEC;
    printf("Time taken to execute: %f seconds\n", timetaken);
    getch();  
    return 0;
}
