#include <stdio.h>

void reverse_string(char *str) {
    if (*str) {
        reverse_string(str + 1);
        putchar(*str);
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Reversed string: ");
    reverse_string(str);
    printf("\n");

    return 0;
}
