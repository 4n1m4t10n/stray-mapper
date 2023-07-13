#include <iostream>
#include <vector>

using namespace std;

// Initialize graph using weighted adjacency matrix
void initializeGraph(vector<string>& vertices, vector<vector<int>>& weights) {
    int numVertices = vertices.size();

    // Create and initialize the adjacency matrix with all weights set to zero
    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));

    // Populate the graph with weighted edges
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (weights[i][j] != 0) {
                int weight = weights[i][j];
                graph[i][j] = weight;
            }
        }
    }

    // Example: Accessing the weight between vertices "start" and "B15"
    int weightStartB15 = graph[0][1];
    cout << "Weight between start and B15: " << weightStartB15 << endl;

    // Example: Accessing the weight between vertices "A33" and "A34"
    int weightA33A34 = graph[10][11];
    cout << "Weight between A33 and A34: " << weightA33A34 << endl;
}

int main() {
    vector<string> vertices = {"start", "B15", "B16", "B17", "B18", "B19", "B20", "A29", "A30", "A31", "A32", "A33", "A34"};
    vector<vector<int>> weights = {
        {0, 11, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0},
        {11, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
        {0, 2, 0, 1, 0, 0, 0, 2, 2, 0, 0, 0, 0},
        {0, 0, 1, 0, 2, 0, 0, 0, 1, 2, 0, 0, 0},
        {0, 0, 0, 2, 0, 1, 0, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 2, 2, 0},
        {0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 2, 0},
        {10, 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0},
        {0, 0, 2, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0},
        {0, 0, 0, 2, 1, 0, 0, 0, 1, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 1, 0},
        {0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 1, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0}
    };

    initializeGraph(vertices, weights);
    return 0;
}
