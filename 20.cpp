#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min_key(int key[], int mst_set[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mst_set[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}
int V;
void print_mst(int parent[], int graph[][V], int V) {
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void prim_mst(int graph[][V], int V) {
    int parent[V]; 
    int key[V];    
    int mst_set[V]; 

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mst_set[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1; 
    for (int count = 0; count < V - 1; count++) {
        int u = min_key(key, mst_set, V);
        mst_set[u] = 1;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mst_set[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    print_mst(parent, graph, V);
}

int main() {
    int V;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];

    printf("Enter the adjacency matrix representing the graph:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    prim_mst(graph, V);

    return 0;
}