#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int source, destination, weight;
};

void addEdge(vector<Edge>& edges, int source, int destination, int weight) {
    edges.push_back({source, destination, weight});
}

int find(vector<int>& parent, int vertex) {
    if (parent[vertex] == vertex)
        return vertex;
    return parent[vertex] = find(parent, parent[vertex]);
}

void unite(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;
        else if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

vector<Edge> kruskalMST(vector<Edge>& edges, int V) {
    vector<Edge> mst;
    vector<int> parent(V), rank(V, 0);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    for (const Edge& edge : edges) {
        if (find(parent, edge.source) != find(parent, edge.destination)) {
            unite(parent, rank, edge.source, edge.destination);
            mst.push_back(edge);
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

    vector<Edge> edges;

    cout << "Enter " << E << " edges in the format: source destination weight\n";
    for (int i = 0; i < E; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        addEdge(edges, source, destination, weight);
    }

    vector<Edge> mst = kruskalMST(edges, V);

    cout << "Minimum Spanning Tree:\n";
    int totalWeight = 0;
    for (const Edge& edge : mst) {
        cout << edge.source << " -- " << edge.destination << " with weight " << edge.weight << endl;
        totalWeight += edge.weight;
    }

    cout << "Total weight of the Minimum Spanning Tree: " << totalWeight << endl;

    return 0;
}
