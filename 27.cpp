#include <stdio.h>

void printPattern(int n, int i) {
    if(n == 0)
        return;
    if(i <= n) {
        printf("%d ", i);
        printPattern(n, i+1);
    } else {
        printf("\n");
        printPattern(n-1, 1);
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printPattern(n, 1);
    return 0;
}