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

