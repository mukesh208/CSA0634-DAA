#include <stdio.h>
#define N 10
#define INF 999999

int costMatrix[N][N];
int minCost = INF;
int assignment[N];

void printAssignment(int n) {
    printf("The optimal assignment is:\n");
    for (int i = 0; i < n; i++)
        printf("Worker %d -> Job %d\n", i + 1, assignment[i] + 1);
    printf("Minimum cost: %d\n", minCost);
}

void findMinCost(int worker, int n, int cost, int bound, int mask) {
    if (worker == n) {
        if (cost < minCost) {
            minCost = cost;
            for (int i = 0; i < n; i++)
                assignment[i] = ((mask >> i) & 1) ? i : assignment[i];
        }
        return;
    }

    if (cost + bound >= minCost)
        return;

    for (int job = 0; job < n; job++) {
        if (!((mask >> job) & 1)) {
            int nextMask = mask | (1 << job);
            findMinCost(worker + 1, n, cost + costMatrix[worker][job], bound - costMatrix[worker][job], nextMask);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of workers/jobs: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    int bound = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
            if (costMatrix[i][j] < bound)
                bound = costMatrix[i][j];
        }
    }

    bound *= n;
    findMinCost(0, n, 0, bound, 0);
    printAssignment(n);

    return 0;
}
