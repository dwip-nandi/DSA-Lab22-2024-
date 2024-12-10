// problem : Create a program that: 
// (a) Declares an array of integers and sorts it using one of the  sorting algorithms from Task 2 (1). 
// (b) Allows the user to enter a value to search for in the sorted array. 
// (c) Uses Binary Search to find and print whether the value is found or not. 

#include <bits/stdc++.h>
using namespace std;

// Bubble Sort Function
void bubbleSort(int arr[], int n) {
    bool isSwap=false;
    for (int i = 0; i < n - 1; i++) {
        isSwap = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap) {
            break;
        }
    }
}

// Binary Search Function
int binarySearch(int arr[], int n, int k) {
    int lowerBound = 0;
    int upperBound = n - 1;
    while (lowerBound <= upperBound) {
        int midPoint = lowerBound + (upperBound - lowerBound) / 2;
        if (arr[midPoint] == k) {
            return midPoint;
        } else if (arr[midPoint] < k) {
            lowerBound = midPoint + 1;
        } else {
            upperBound = midPoint - 1;
        }
    }
    return -1;
}

int main() {
    // (a) Declare and initialize the array
    cout << "Enter the number of elements in your array: ";
    int n;
    cin >> n;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    cout << "The elements of the array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    // Sort the array using Bubble Sort
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    // (b) Allow the user to enter a value to search for
    cout << "Enter the value to search: ";
    int key;
    cin >> key;

    // (c) Use Binary Search to find and print whether the value is found or not
    int result = binarySearch(arr, n, key);
    if (result != -1) {
        cout << "The target value is present at index: " << result + 1 << endl;
    } else {
        cout << "The target value is not present in this array. Try again later!" << endl;
    }
    return 0;
}
