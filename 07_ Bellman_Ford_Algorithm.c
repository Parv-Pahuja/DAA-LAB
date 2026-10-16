#include <stdio.h>
#include <stdlib.h>
#define INFINITY 999999

typedef struct {
    int src, dest, weight;
} Edge;

void printPath(int current, int *parent, int source) {
    if (current == source) {
        printf("%d", source);
        return;
    }
    printPath(parent[current], parent, source);
    printf("->%d", current);
}

int main() {
    int V, E;
    if (scanf("%d", &V) != 1) return 0;
    if (scanf("%d", &E) != 1) return 0;

    Edge *edges = (Edge *)malloc(E * sizeof(Edge));
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    int source;
    if (scanf("%d", &source) != 1) return 0;

    int *distance = (int *)malloc((V + 1) * sizeof(int));
    int *parent = (int *)malloc((V + 1) * sizeof(int));

    for (int i = 1; i <= V; i++) {
        distance[i] = INFINITY;
        parent[i] = -1;
    }
    distance[source] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            
            if (distance[u] != INFINITY && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
            }
        }
    }

    int hasNegativeCycle = 0;
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        
        if (distance[u] != INFINITY && distance[u] + weight < distance[v]) {
            hasNegativeCycle = 1;
            break;
        }
    }

    if (hasNegativeCycle) {
        printf("Negative cycle detected\n");
    } else {
        for (int i = 1; i <= V; i++) {
            if (i == source) {
                continue;
            }
            
            if (distance[i] == INFINITY) {
                printf("%d INF None\n", i);
            } else {
                printf("%d %d ", i, distance[i]);
                printPath(i, parent, source);
                printf("\n");
            }
        }
    }

    free(edges);
    free(distance);
    free(parent);

    return 0;
}
