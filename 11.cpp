#include <stdio.h>
void copyString(char *source, char *destination, int index) {
    if (source[index] == '\0') {
        destination[index] = '\0';
        return;
    } else {
        destination[index] = source[index];
        copyString(source, destination, index + 1);
    }
}
int main() {
    char source[50];
    char destination[50];

    printf("Enter a string: ");
    fgets(source, sizeof(source), stdin); 
    copyString(source, destination, 0);
    printf("Copied string: %s\n", destination);
    return 0;
}
