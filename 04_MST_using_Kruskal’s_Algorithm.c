#include <stdio.h>

    for (int i = 1; i < edgeCount; i++) {
        Edge key = edges[i];
        int j = i - 1;
        while (j >= 0 && edges[j].weight > key.weight) {
            edges[j + 1] = edges[j];
            j--;
        }
        edges[j + 1] = key;
    }

    int *parent = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int mstEdges = 0;
    int totalCost = 0;


    for (int i = 0; i < edgeCount; i++) {
        if (mstEdges == V - 1) {
            break; 
        }

        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (unionSets(u, v, parent)) {
            printf("Edge %d:(%d, %d) cost:%d\n", mstEdges, u, v, w);
            totalCost += w;
            mstEdges++;
        }
    }

    printf("Minimum cost= %d\n", totalCost);
	
    free(edges);
    free(parent);
}



int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
