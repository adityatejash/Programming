#include <iostream>
#include <queue>
using namespace std;

#define V 5

void DFS(int graph[V][V], bool visited[], int v) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i]) {
            DFS(graph, visited, i);
        }
    }
}

void BFS(int graph[V][V], int start) {
    bool visited[V] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < V; i++) {
            if (graph[v][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int graph[V][V] = {
        {0,1,1,0,0},
        {1,0,0,1,0},
        {1,0,0,1,1},
        {0,1,1,0,1},
        {0,0,1,1,0}
    };

    bool visited[V] = {false};

    cout << "DFS Traversal: ";
    DFS(graph, visited, 0);

    cout << "\nBFS Traversal: ";
    BFS(graph, 0);

    return 0;
}