/*
 * week4_1_dynamic_array.c
 * Author: [Emirhan Kucukyilmaz]
 * Student ID: [251ADB105]
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Allocate memory for n integers, read them from the user,
 *   print their sum and average, and then free the memory.
 *
 *   Output must match the format in the Week 4 instructions exactly
 *   (it is checked by the autograder).
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int *arr = NULL;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);

    int sum = 0;
    float average = 0.0f;

    for (int i = 0; i < n; i++){
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }
    printf("Sum = %d\n", sum);
    average = (float)sum / n;
    printf("Average = %.2f\n", average);
    free(arr);
    arr = NULL;
    return 0;
}
