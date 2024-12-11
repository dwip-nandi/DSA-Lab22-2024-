#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> merge2DArrays(const vector<vector<int>>& arr1, const vector<vector<int>>& arr2) {
    vector<vector<int>> mergedArray = arr1;

    // Add rows from the second array
    for (const auto& row : arr2) {
        mergedArray.push_back(row);
    }

    return mergedArray;
}

int main() {
    // Define two 2D arrays (using vectors)
    vector<vector<int>> array1 = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> array2 = {{7, 8, 9}, {10, 11, 12}};

    // Merge the arrays
    vector<vector<int>> mergedArray = merge2DArrays(array1, array2);

    // Print the merged array
    cout << "Merged 2D Array:" << endl;
    for (const auto& row : mergedArray) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}
