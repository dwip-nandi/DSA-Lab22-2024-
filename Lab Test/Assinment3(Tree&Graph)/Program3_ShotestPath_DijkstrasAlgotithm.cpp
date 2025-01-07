/*  ---------------------Dijkstra's Algorithm--------------------------
Problrm: Suppose you are given graph G in the form of weight matrix.
Write a program to determine the shortest path of the graph.
--------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

int minDistance(const vector<int>& dist, const vector<bool>& sptSet, int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printPath(const vector<int>& parent, int j) {
    if (parent[j] == -1) {
        return;
    }

    printPath(parent, parent[j]);
    cout << " -> " << char('A' + j);
}

void dijkstra(const vector<vector<int>>& graph, int src, int dest) {
    int n = graph.size();
    cout<<n<<endl;
    vector<int> dist(n, INT_MAX);
    vector<bool> sptSet(n, false);
    vector<int> parent(n, -1);

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Shortest path from " << char('A' + src) << " to " << char('A' + dest) << " is: " << char('A' + src);
    printPath(parent, dest);
    cout << endl;
}

int main() {
    cout<<"Enter the numeber of nodes: ";
    int n;
    cin>>n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    
    cout<<"Enter the source and destination: ";
    char s,d;
    cin>>s>>d;
    int src = s-'A'; 
    int dest = d-'A'; 

    dijkstra(graph, src, dest);

    return 0;
}
