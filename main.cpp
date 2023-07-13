#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

// Structure to represent a vertex and its distance from the start
struct Vertex {
    int index;
    int distance;
    int previous;

    Vertex(int idx, int dist, int prev) : index(idx), distance(dist), previous(prev) {}

    // Overload the comparison operator for the priority queue
    bool operator<(const Vertex& other) const {
        return distance > other.distance; // Compare distances (min-heap)
    }
};

// Dijkstra's algorithm to find the shortest path from the start vertex to the given vertices
void shortestPath(const vector<vector<int>>& graph, int start, const vector<int>& targetVertices) {
    int numVertices = graph.size();

    // Create a distance array to store the shortest distances from the start vertex
    vector<int> distance(numVertices, INT_MAX);

    // Create a previous array to store the previous vertex for each vertex in the path
    vector<int> previous(numVertices, -1);

    // Create a priority queue to store vertices based on their distances
    priority_queue<Vertex> pq;

    // Initialize the distance of the start vertex as 0 and insert it into the priority queue
    distance[start] = 0;
    pq.push(Vertex(start, 0, -1));

    // Iterate until the priority queue becomes empty
    while (!pq.empty()) {
        Vertex current = pq.top();
        pq.pop();

        // Stop if the current vertex is one of the target vertices
        if (find(targetVertices.begin(), targetVertices.end(), current.index) != targetVertices.end()) {
            // Reconstruct the shortest path and store it in a stack
            stack<int> shortestPath;
            int vertex = current.index;
            while (vertex != start) {
                shortestPath.push(vertex);
                vertex = previous[vertex];
            }
            shortestPath.push(start);

            // Print the shortest path in the correct order
            cout << "Shortest path to vertex " << current.index << ": ";
            while (!shortestPath.empty()) {
                cout << shortestPath.top() << " ";
                shortestPath.pop();
            }
            cout << endl;
        }

        // Explore the adjacent vertices of the current vertex
        for (int i = 0; i < numVertices; i++) {
            if (graph[current.index][i] != 0) { // If there is an edge between current and i
                int newDistance = current.distance + graph[current.index][i];

                // If the new distance is shorter, update the distance array and the previous array,
                // and insert the vertex into the priority queue
                if (newDistance < distance[i]) {
                    distance[i] = newDistance;
                    previous[i] = current.index;
                    pq.push(Vertex(i, newDistance, current.index));
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
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

    vector<int> targetVertices = {1, 5, 9, 12};  // Example target vertices

    int startVertex = 0;  // Index of the "start" vertex

    shortestPath(graph, startVertex, targetVertices);

    return 0;
}
