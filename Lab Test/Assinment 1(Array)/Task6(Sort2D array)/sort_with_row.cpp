#include <iostream>
#include <vector>
#include <algorithm> // For swap
#include <stdexcept> // For exceptions

using namespace std;

// Function to partition the array for quicksort
int partition(vector<vector<int>>& arr, int low, int high, int column) {
    vector<int> pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j][column] < pivot[column]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to implement quicksort
void quickSort(vector<vector<int>>& arr, int low, int high, int column) {
    if (low < high) {
        int pi = partition(arr, low, high, column);

        quickSort(arr, low, pi - 1, column);
        quickSort(arr, pi + 1, high, column);
    }
}

// Function to sort rows based on a specific column
void sortRowsByColumn(vector<vector<int>>& arr, int column) {
    // Validate the column index
    if (arr.empty() || column >= arr[0].size()) {
        throw invalid_argument("Invalid column index.");
    }

    // Apply quicksort on rows
    quickSort(arr, 0, arr.size() - 1, column);
}

// Function to print the 2D array
void print2DArray(const vector<vector<int>>& arr) {
    for (const auto& row : arr) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    // Input: Define a 2D array
    vector<vector<int>> array = {
        {3, 4, 2},
        {1, 9, 5},
        {6, 7, 8},
        {4, 2, 6}
    };

    cout << "Original 2D Array:" << endl;
    print2DArray(array);

    // Ask the user to specify a column to sort by
    int column;
    cout << "\nEnter the column index to sort by (0-based index): ";
    cin >> column;

    try {
        // Sort rows based on the specified column
        sortRowsByColumn(array, column);

        cout << "\nSorted 2D Array:" << endl;
        print2DArray(array);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
