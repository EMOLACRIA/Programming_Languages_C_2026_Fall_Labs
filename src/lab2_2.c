#include <stdio.h>

long long factorial(int n) {
    long long sum = 1;
    for (int i = 1; i <= n; i++) {
        sum = sum * i;
    }
    return sum;
}

int main(void) {
    int n;

    printf("Enter a non-negative integer n: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Please enter a non-negative number.\n");
    }
    else {
        printf("Factorial of %d! is %lld\n",n,factorial(n));
    }
    return 0;
}
