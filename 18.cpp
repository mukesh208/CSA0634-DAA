#include <stdio.h>

int isPrime(int n, int i) {
    if (n <= 2)
        return (n == 2) ? 1 : 0;
    if (n % i == 0)
        return 0;
    if (i * i > n)
        return 1;
    return isPrime(n, i + 1);
}

void printPrimes(int n) {
    if (n > 1) {
        printPrimes(n - 1);
        if (isPrime(n, 2))
            printf("%d ", n);
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Prime numbers up to %d are: ", n);
    printPrimes(n);
    printf("\n");
    return 0;
}
