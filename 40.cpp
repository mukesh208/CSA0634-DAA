#include <stdio.h>
#define MAX_VERTICES 10

int path[MAX_VERTICES];

void printHamiltonian(int path[], int num_vertices) {
    printf("Hamiltonian Cycle: ");
    for (int i = 0; i < num_vertices; i++)
        printf("%d ", path[i] + 1);
    printf("%d\n", path[0] + 1);
}

int isSafe(int v, int graph[][MAX_VERTICES], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return 0;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;
}

int hamiltonianCycleUtil(int graph[][MAX_VERTICES], int path[], int pos, int num_vertices) {
    if (pos == num_vertices) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }

    for (int v = 1; v < num_vertices; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianCycleUtil(graph, path, pos + 1, num_vertices) == 1)
                return 1;

            path[pos] = -1;
        }
    }

    return 0;
}

void hamiltonianCycle(int graph[][MAX_VERTICES], int num_vertices) {
    for (int i = 0; i < num_vertices; i++)
        path[i] = -1;

    path[0] = 0;
    if (hamiltonianCycleUtil(graph, path, 1, num_vertices) == 0) {
        printf("Solution does not exist\n");
        return;
    }

    printHamiltonian(path, num_vertices);
}

int main() {
    int num_vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++)
        for (int j = 0; j < num_vertices; j++)
            scanf("%d", &graph[i][j]);

    hamiltonianCycle(graph, num_vertices);

    return 0;
}
