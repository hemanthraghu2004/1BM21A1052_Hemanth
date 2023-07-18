#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int destination, weight;
};

void addEdge(vector<vector<Edge>>& graph, int source, int destination, int weight) {
    graph[source].push_back({destination, weight});
    graph[destination].push_back({source, weight});
}

vector<int> dijkstra(vector<vector<Edge>>& graph, int source) {
    int V = graph.size();
    vector<int> distances(V, numeric_limits<int>::max());
    vector<bool> visited(V, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({distances[v], v});
            }
        }
    }

    return distances;
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

    int sourceVertex;
    cout << "Enter the source vertex: ";
    cin >> sourceVertex;

    vector<int> distances = dijkstra(graph, sourceVertex);

    cout << "Shortest distances from vertex " << sourceVertex << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
