#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
    bool isSwap;
    for (int i = 0; i < n - 1; i++) {
        isSwap = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwap = true;
            }
        }
        if (!isSwap) {
            break;
        }
    }
}

int binarySearch(int arr[], int n, int k) {
    int lowerBound = 0;
    int upperBound = n - 1;
    while (lowerBound <= upperBound) {
        int midPoint = lowerBound + (upperBound - lowerBound) / 2;
        if (arr[midPoint] == k) return midPoint;
        else if (arr[midPoint] < k) lowerBound = midPoint + 1;
        else upperBound = midPoint - 1;
    }
    return -1;
}

int main() {
    cout << "Enter the number of elements in your array: ";
    int n;
    cin >> n;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    

    // Sort the array using Bubble Sort
    bubbleSort(arr, n);
    cout << "The sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    // Perform Binary Search
    cout << "Enter the value to search: ";
    int key;
    cin >> key;
    int result = binarySearch(arr, n, key);
    if (result != -1) {
        cout << "The target value is present at index: " << result + 1 << endl;
    } else {
        cout << "The target value is not present in this array. Try again later!" << endl;
    }
    return 0;
}
