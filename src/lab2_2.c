#include <stdio.h>

/*
    Task:
    Write a function `long long factorial(int n)` that computes n!
    using a loop (not recursion).

    In main():
      - Ask user for an integer n
      - If n is negative, print an error and exit
      - Otherwise, call factorial and print the result
*/

long long factorial(int n) {
    long long sum = 1;
    for (int i = 1; i <= n; i++) {
        sum = sum * i;
    }
    return sum; // placeholder
}

int main(void) {
    int n;

    printf("Enter a non-negative integer n: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Please enter a number bigger than 0.");
    }
    else {
        printf("Factorial of %d! is %lld\n",n,factorial(n));
    }
    return 0;
}
