#include<stdio.h>
#include<limits.h>
#define V 5

int minD(int dist[], int sptset[]){
    int min = INT_MAX, min_ind;
    for(int v=0; v<V; v++){
        if(sptset[v] ==0 && dist[v] <= min){
            min = dist[v];
            min_ind = v;        
        }
    }
    return min_ind;
}
void sol(int dist[]){
    printf("Vertex \t distance from Source \n");
    for(int i=0; i<V;i++){
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src){
    int dist[V];
    int sptset[V];
    for(int i=0; i<V; i++){
        dist[i] = INT_MAX;
        sptset[i]=0;
    }
    dist[src] =0;
    for(int c=0; c<V-1; c++){
        int u = minD(dist, sptset);
        sptset[u] = 1;
        for(int v =0; v<V; v++){
            if(!sptset[v] && graph[u][v] && dist[u]  != INT_MAX && dist[u] + graph[u][v] < dist[v]){
            dist[v] = dist[u] + graph[u][v];
            }
        }        
    }
    sol(dist);
}
int main(){
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {10, 0, 1, 0, 2},
        {0, 1, 0, 4, 0},
        {0, 0, 4, 0, 3},
        {5, 2, 0, 3, 0}
    };

    dijkstra(graph, 0);
    return 0;
}
