#include <iostream>
#include <vector>

using namespace std;

void warshallAlgorithm(vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    vector<vector<int>> transitiveClosure = adjMatrix;

    // Apply Warshall's Algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                transitiveClosure[i][j] = transitiveClosure[i][j] || (transitiveClosure[i][k] && transitiveClosure[k][j]);
            }
        }
    }

    // Print the transitive closure matrix
    cout << "Transitive Closure Matrix:" << endl;
    for (const auto& row : transitiveClosure) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    vector<vector<int>> adjMatrix(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adjMatrix[i][j];
        }
    }

    warshallAlgorithm(adjMatrix);

    return 0;
}
