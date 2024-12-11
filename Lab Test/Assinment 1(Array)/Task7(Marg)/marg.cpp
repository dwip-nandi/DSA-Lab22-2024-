// Task 7: Merge Two 2D Arrays 
// 1. Create a program in your preferred programming language (e.g., Python, 
// C++, Java) to merge two 2D integer arrays into a single 2D array. 
// 2. Implement the merging algorithm efficiently with a time complexity of 
// O(n), where n is the total number of elements in both arrays. 
// 3. Print the merged 2D array.

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

void mergeArrays(int arr1[][10], int rows1, int cols1, int arr2[][10], int rows2, int cols2, int mergedArray[][10]) {
    int i = 0, j = 0, k = 0, l = 0;

    while (i < rows1 && j < rows2) {
        for (int m = 0; m < cols1 && k < rows1 + rows2; m++) {
            if (arr1[i][m] <= arr2[j][m]) {
                mergedArray[k][l++] = arr1[i][m];
            } else {
                mergedArray[k][l++] = arr2[j][m];
            }
        }
        if (l == cols1) {
            l = 0;
            k++;
        }
        i++;
        j++;
    }

    while (i < rows1) {
        for (int m = 0; m < cols1; m++) {
            mergedArray[k][l++] = arr1[i][m];
        }
        if (l == cols1) {
            l = 0;
            k++;
        }
        i++;
    }

    while (j < rows2) {
        for (int m = 0; m < cols2; m++) {
            mergedArray[k][l++] = arr2[j][m];
        }
        if (l == cols2) {
            l = 0;
            k++;
        }
        j++;
    }
}

int main() {
    const int rows1 = 3, cols1 = 10;
    const int rows2 = 3, cols2 = 10;
    int arr1[rows1][cols1];
    int arr2[rows2][cols2];
    int mergedArray[rows1 + rows2][cols1];

    populateArray(arr1, rows1, cols1);
    populateArray(arr2, rows2, cols2);

    cout << "Array 1:" << endl;
    displayArray(arr1, rows1, cols1);

    cout << "Array 2:" << endl;
    displayArray(arr2, rows2, cols2);

    mergeArrays(arr1, rows1, cols1, arr2, rows2, cols2, mergedArray);

    cout << "Merged Array:" << endl;
    displayArray(mergedArray, rows1 + rows2, cols1);

    return 0;
}
