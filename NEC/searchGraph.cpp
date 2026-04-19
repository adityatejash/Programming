#include <iostream>
#include <vector>
using namespace std;

int main() {
    int v = 5;

    vector<vector<int>> graph(v, vector<int>(v, 0));

    graph[0][1] = 1;
    graph[1][0] = 1;

    graph[0][2] = 1;
    graph[2][0] = 1;

    graph[1][3] = 1;
    graph[3][1] = 1;

    graph[2][4] = 1;
    graph[4][2] = 1;

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    int node;
    cout << "Enter node: ";
    cin >> node;

    if (node >= 0 && node < v) {
        cout << "Node exists" << endl;

        bool connected = false;
        for (int i = 0; i < v; i++) {
            if (graph[node][i] == 1) {
                connected = true;
                break;
            }
        }

        if (connected)
            cout << "Node is connected" << endl;
        else
            cout << "No edges" << endl;
    } else {
        cout << "Node does not exist" << endl;
    }

    return 0;
}