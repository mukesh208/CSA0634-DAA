#include<stdio.h>

#define INF 999999
#define N 4

void copy_array(int n, int src[], int dest[]) {
    for(int i=0; i<n; i++)
        dest[i] = src[i];
}

int first_min(int adj[N][N], int i) {
    int min = INF;
    for (int k=0; k<N; k++)
        if (adj[i][k]<min && i != k)
            min = adj[i][k];
    return min;
}

int second_min(int adj[N][N], int i) {
    int first = INF, second = INF;
    for (int j=0; j<N; j++) {
        if (i == j)
            continue;

        if (adj[i][j] <= first) {
            second = first;
            first = adj[i][j];
        }
        else if (adj[i][j] <= second && adj[i][j] != first)
            second = adj[i][j];
    }
    return second;
}

void TSP(int adj[N][N]) {
    int curr_bound = 0;
    int curr_weight = 0;
    int level = 0;
    int curr_path[N+1];
    int visited[N];

    for (int i=0; i<N; i++) {
        visited[i] = 0;
        curr_path[i] = -1;
    }

    curr_path[0] = 0;
    visited[0] = 1;

    printf("The path is: ");
    for (int i=0; i<=N; i++) {
        printf("%d ", curr_path[i]);
    }
    printf("\nThe cost is: %d\n", curr_bound);
}

int main() {
    int adj[N][N];
    printf("Enter the adjacency matrix:\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    TSP(adj);
    return 0;
}