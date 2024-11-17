#include <stdio.h>
#include <limits.h>
#define V 5
#define E 8
typedef struct {
    int src, dest, weight;
} Edge;
void bellmanFord(Edge edges[], int src) {
    int dist[V]; 
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0; 
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            if (dist[edges[j].src] != INT_MAX &&
                dist[edges[j].src] + edges[j].weight < dist[edges[j].dest]) {
                dist[edges[j].dest] = dist[edges[j].src] + edges[j].weight;
            }
        }
    }
    for (int j = 0; j < E; j++) {
        if (dist[edges[j].src] != INT_MAX &&
            dist[edges[j].src] + edges[j].weight < dist[edges[j].dest]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }
    printf("Vertex\tDistance from Source %d\n", src);
    for (int i = 0; i < V; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}
int main() {
    Edge edges[] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    bellmanFord(edges, 0); 
    return 0;
}
