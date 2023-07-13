#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

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

// Dijkstra's algorithm to find the shortest path that visits the target vertices
vector<int> shortestPath(const vector<vector<int>>& graph, int start, const vector<int>& targetVertices) {
    int numVertices = graph.size();

    // Create a distance array to store the shortest distances from the start vertex
    vector<int> distance(numVertices, INT_MAX);

    // Create a previous array to store the previous vertex for each vertex in the path
    vector<int> previous(numVertices, -1);

    // Create a map to store the vertex names
    unordered_map<int, string> vertexNames;
    vertexNames[0] = "start";
    vertexNames[1] = "B15";
    vertexNames[2] = "B16";
    vertexNames[3] = "B17";
    vertexNames[4] = "B18";
    vertexNames[5] = "B19";
    vertexNames[6] = "B20";
    vertexNames[7] = "A29";
    vertexNames[8] = "A30";
    vertexNames[9] = "A31";
    vertexNames[10] = "A32";
    vertexNames[11] = "A33";
    vertexNames[12] = "A34";

    // Create a set to store the visited vertices
    unordered_set<int> visited;

    // Create a priority queue to store vertices based on their distances
    priority_queue<Vertex> pq;

    // Initialize the distance of the start vertex as 0 and insert it into the priority queue
    distance[start] = 0;
    pq.push(Vertex(start, 0, -1));

    // Iterate until all target vertices are visited or the priority queue becomes empty
    while (!pq.empty()) {
        Vertex current = pq.top();
        pq.pop();

        // Mark the current vertex as visited
        visited.insert(current.index);

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

    // Check if all target vertices are visited
    for (int vertex : targetVertices) {
        if (visited.find(vertex) == visited.end()) {
            // If any target vertex is not visited, return an empty path
            return vector<int>();
        }
    }

    // Reconstruct the shortest path
    vector<int> shortestPath;
    int vertex = targetVertices[0];
    while (vertex != start) {
        shortestPath.push_back(vertex);
        vertex = previous[vertex];
    }
    shortestPath.push_back(start);

    // Reverse the path to obtain the correct order
    reverse(shortestPath.begin(), shortestPath.end());

    return shortestPath;
}

int main() {
    vector<vector<int>> graph = {
        {0, 11, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0}, // start
        {11, 0, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0}, // B15
        {0, 2, 0, 1, 0, 0, 0, 2, 2, 0, 0, 0, 0}, // B16
        {0, 0, 1, 0, 2, 0, 0, 0, 0, 2, 2, 0, 0}, // B17
        {0, 0, 0, 2, 0, 1, 0, 0, 0, 2, 2, 0, 0}, // B18
        {0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 2, 2}, // B19
        {0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 2}, // B20
        {10, 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0}, // A29
        {0, 2, 2, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0}, // A30
        {0, 0, 0, 2, 2, 0, 0, 0, 1, 0, 2, 0, 0}, // A31 
        {0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 0, 1, 0}, // A32
        {0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 1, 0, 2}, // A33
        {0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 0} // A34
    };

    vector<int> targetVertices = {1, 5, 12}; // Example target vertices
    vector<string> vertexNames = {"start", "B15", "B16", "B17", "B18", "B19", "B20", "A29", "A30", "A31", "A32", "A33", "A34"};

    int startVertex = 0; // Index of the "start" vertex

    vector<int> path = shortestPath(graph, startVertex, targetVertices);

    if (!path.empty()) {
        cout << "Shortest path to target vertices: ";
        for (int vertexIndex : path) {
            cout << vertexNames[vertexIndex] << " ";
        }
        cout << endl;
    } else {
        cout << "No path found to visit all target vertices." << endl;
    }

    return 0;
}
