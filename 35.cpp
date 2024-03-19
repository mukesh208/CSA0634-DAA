#include <stdio.h>

#define MAX_SIZE 100
int isSubsetSum(int set[], int n, int target_sum, int subset[], int subset_size) {
    if (target_sum == 0) {
        printf("Subset found: ");
        for (int i = 0; i < subset_size; i++)
            printf("%d ", subset[i]);
        printf("\n");
        return 1;
    }

    if (n == 0 || target_sum < 0)
        return 0;

    if (isSubsetSum(set, n - 1, target_sum, subset, subset_size))
        return 1;

    subset[subset_size] = set[n - 1];
    return isSubsetSum(set, n - 1, target_sum - set[n - 1], subset, subset_size + 1);
}

int main() {
    int n, target_sum;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[MAX_SIZE];
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target_sum);

    int subset[MAX_SIZE];
    if (!isSubsetSum(set, n, target_sum, subset, 0))
        printf("No subset found with the given sum.\n");

    return 0;
}