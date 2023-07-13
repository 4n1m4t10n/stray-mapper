#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to generate a DOT file representing the graph
void generateDotFile(const string& dotFilePath, const unordered_map<string, unordered_map<string, int>>& graph) {
    ofstream dotFile(dotFilePath);

    if (!dotFile) {
        cerr << "Failed to create DOT file: " << dotFilePath << endl;
        return;
    }

    dotFile << "digraph G {\n";

    // Iterate over each vertex and its edges
    for (const auto& vertexPair : graph) {
        const string& vertex = vertexPair.first;
        const auto& edges = vertexPair.second;

        // Iterate over the edges of the current vertex
        for (const auto& edge : edges) {
            const string& adjacentVertex = edge.first;
            int weight = edge.second;
            dotFile << "    " << vertex << " -> " << adjacentVertex << " [label=\"" << weight << "\"];\n";
        }
    }

    dotFile << "}\n";
    dotFile.close();

    cout << "DOT file created: " << dotFilePath << endl;
}

int main() {
    string dotFilePath = "graph.dot";

    unordered_map<string, unordered_map<string, int>> graph;
    graph["start"] = {{"B15", 11}, {"A29", 10}};
    graph["B15"] = {{"start", 11}, {"A29", 2}, {"B16", 2}, {"A30", 2}};
    graph["B16"] = {{"B15", 2}, {"A29", 2}, {"A30", 2}, {"B17", 1}};
    graph["B17"] = {{"B16", 1}, {"A31", 2}, {"A32", 2}, {"B18", 2}};
    graph["B18"] = {{"B17", 2}, {"A31", 2}, {"A32", 2}, {"B19", 1}};
    graph["B19"] = {{"B18", 1}, {"A33", 2}, {"A34", 2}, {"B20", 2}};
    graph["B20"] = {{"B19", 2}, {"A33", 2}, {"A34", 2}};
    graph["A29"] = {{"start", 10}, {"B15", 2}, {"B16", 2}, {"A30", 2}};
    graph["A30"] = {{"A29", 2}, {"B15", 2}, {"B16", 2}, {"A31", 1}};
    graph["A31"] = {{"A30", 1}, {"B17", 2}, {"B18", 2}, {"A32", 2}};
    graph["A32"] = {{"A31", 2}, {"B17", 2}, {"B18", 2}, {"A33", 1}};
    graph["A33"] = {{"A32", 1}, {"B19", 2}, {"B20", 2}, {"A34", 2}};
    graph["A34"] = {{"A33", 2}, {"B19", 2}, {"B20", 2}};

    generateDotFile(dotFilePath, graph);

    return 0;
}
