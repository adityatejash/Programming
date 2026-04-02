#include <iostream>
#include <climits>
using namespace std;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(Edge edges[], int V, int E, int src) {
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Negative weight cycle detected\n";
            return;
        }
    }

    cout << "Vertex \t Distance\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << endl;
}

int main() {
    int V = 5, E = 8;
    Edge edges[E] = {
        {0,1,-1},{0,2,4},{1,2,3},{1,3,2},
        {1,4,2},{3,2,5},{3,1,1},{4,3,-3}
    };

    bellmanFord(edges, V, E, 0);
    return 0;
}