#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

struct Edge {
    int source, destination, weight;
};

void addEdge(vector<vector<Edge>>& graph, int source, int destination, int weight) {
    graph[source].push_back({source, destination, weight});
    graph[destination].push_back({destination, source, weight});
}

vector<Edge> primMST(vector<vector<Edge>>& graph, function<bool(Edge, Edge)> comp) {
    int V = graph.size();
    vector<Edge> mst;
    vector<bool> visited(V, false);
    priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)>> pq(comp);

    visited[0] = true;
    for (const Edge& edge : graph[0]) {
        pq.push(edge);
    }

    while (!pq.empty()) {
        Edge currentEdge = pq.top();
        pq.pop();

        int nextVertex = currentEdge.destination;

        if (!visited[nextVertex]) {
            visited[nextVertex] = true;
            mst.push_back(currentEdge);

            for (const Edge& edge : graph[nextVertex]) {
                if (!visited[edge.destination]) {
                    pq.push(edge);
                }
            }
        }
    }

    return mst;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<Edge>> graph(V);

    cout << "Enter " << E << " edges in the format: source destination weight\n";
    for (int i = 0; i < E; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        addEdge(graph, source, destination, weight);
    }

    auto comp = [](Edge a, Edge b) { return a.weight > b.weight; };

    vector<Edge> mst = primMST(graph, comp);

    cout << "Minimum Spanning Tree:\n";
    int totalWeight = 0;
    for (const Edge& edge : mst) {
        cout << edge.source << " -- " << edge.destination << " with weight " << edge.weight << endl;
        totalWeight += edge.weight;
    }

    cout << "Total weight of the Minimum Spanning Tree: " << totalWeight << endl;

    return 0;
}
