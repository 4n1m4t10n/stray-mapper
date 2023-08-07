#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

// Number of vertices in the graph
#define V 13
 
// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(vector<pair<int, int>> dist, bool sptSet[])
{
 
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v].second <= min)
            min = dist[v].second, min_index = v;
 
    return min_index;
}
 
// A utility function to print the constructed distance
// array
void printSolution(vector<pair<int, int>> dist)
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << dist[i].first << " \t\t\t\t" << dist[i].second << endl;
}
 
// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(vector<vector<int>> graph, int &src, set<int> targets, vector<int> &path)
{
    vector<pair<int, int>> dist; // The output array.  dist[i] will hold the
                 // shortest
    // distance from src to i
 
    bool sptSet[V]; // sptSet[i] will be true if vertex i is
                    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized
 
    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < V; i++)
    {
        dist.push_back(make_pair(i, INT_MAX)); 
        sptSet[i] = false;
    }
 
    // Distance of source vertex from itself is always 0
    dist[src].second = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)
 
            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v]
                && dist[u].second != INT_MAX
                && dist[u].second + graph[u][v] < dist[v].second)
                dist[v].second = dist[u].second + graph[u][v];
    }
 
    std::sort(dist.begin(), dist.end(), [](auto &left, auto &right) {
    return left.second < right.second;
});
    // print the constructed distance array
    printSolution(dist);

    for (int i = 1; i < dist.size(); i++){
        if (targets.find(dist[i].first) != targets.end()){
            src = dist[i].first;
            path.push_back(src);
            targets.erase(targets.find(dist[i].first));
            break;
        }
    }

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

    set<int> targets = {1, 5, 12};
    vector<int> path;

    int start = 0;

    while (!targets.empty())
        dijkstra(graph, start, targets, path);

    return 0;
}
