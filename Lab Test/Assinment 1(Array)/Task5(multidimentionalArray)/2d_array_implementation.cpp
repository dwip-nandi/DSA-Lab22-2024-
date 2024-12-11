// Task 5: Searching in a 2D Array 
// 1. Create a program in your preferred programming language (e.g., Python, 
// C++, Java) that allows the user to: 
// (a) Declare a 2D integer array of a size of your choice. 
// (b) Populate the array with random values. 
// (c) Enter a value to search for within the 2D array. 
// (d) Implement a search algorithm (e.g., linear search or binary search) to 
// find the value in the 2D array and return its position (row and 
// column). 
// (e) Print the position where the value was found or a message indicating 
// that it wasn't found. 

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

bool searchArray(int arr[][10], int rows, int cols, int value, int &row, int &col) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == value) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

int main() {
    const int rows = 2;
    const int cols = 10;
    int arr[rows][cols];

    populateArray(arr, rows, cols);
    displayArray(arr, rows, cols);

    int value;
    cout << "Enter a value to search for: ";
    cin >> value;

    int row, col;
    if (searchArray(arr, rows, cols, value, row, col)) {
        cout << "Value found at position: (" << row << ", " << col << ")" << endl;
    } else {
        cout << "Value not found in the array." << endl;
    }

    return 0;
}
