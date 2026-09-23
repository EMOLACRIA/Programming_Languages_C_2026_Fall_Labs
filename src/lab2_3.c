#include <stdio.h>
#include <math.h>

int is_prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }

    }

    return 1;
}

int main(void) {
    int n;

    printf("Enter an integer n (>= 2): ");
    scanf("%d", &n);
    if (n < 2) {
        printf("Please enter a number bigger than 2.");
    }
    else {
        for (int i = 2; i<=n; i++) {
            if (is_prime(i)) {
                printf("%d ", i);
            }
        }
    }
    return 0;
}
