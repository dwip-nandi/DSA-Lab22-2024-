// Problem : Task 6: Sorting Rows in a 2D Array 
// 1. Extend your program to sort the rows of the 2D array in ascending order 
// based on a chosen column (the user should specify the column). 
// (a) Implement a sorting algorithm (e.g., quicksort or mergesort) to 
// perform the sorting operation efficiently. 
// (b) Print the sorted 2D array.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void populateArray(int arr[][10], int rows, int cols) {
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100; // Random values between 0 and 99
        }
    }
}

void displayArray(int arr[][10], int rows, int cols) {
    cout << "2D Array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void swapRows(int arr[][10], int row1, int row2, int cols) {
    for (int i = 0; i < cols; i++) {
        int temp = arr[row1][i];
        arr[row1][i] = arr[row2][i];
        arr[row2][i] = temp;
    }
}

int partition(int arr[][10], int low, int high, int col, int cols) {
    int pivot = arr[high][col];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j][col] <= pivot) {
            i++;
            swapRows(arr, i, j, cols);
        }
    }
    swapRows(arr, i + 1, high, cols);
    return i + 1;
}

void quickSort(int arr[][10], int low, int high, int col, int cols) {
    if (low < high) {
        int pi = partition(arr, low, high, col, cols);
        quickSort(arr, low, pi - 1, col, cols);
        quickSort(arr, pi + 1, high, col, cols);
    }
}

int main() {
    const int rows = 2;
    const int cols = 10;
    int arr[rows][cols];

    populateArray(arr, rows, cols);
    displayArray(arr, rows, cols);

    int col;
    cout << "Enter the column to sort by (0 to " << cols - 1 << "): ";
    cin >> col;

    quickSort(arr, 0, rows - 1, col, cols);
    displayArray(arr, rows, cols);

    return 0;
}
