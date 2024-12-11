// Problem : Task 4: Merge Two Sorted Arrays 
// 1. Create a program in your preferred programming language (e.g., 
// Python, C++, Java) to merge two sorted integer arrays into a single 
// sorted array. 
// 2. Implement the merging algorithm efficiently with a time complexity 
// of O(n), where n is the total number of elements in both arrays. 
// 3. Print the merged sorted array.

// using array

#include <iostream>

using namespace std;

void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int mergedArray[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            mergedArray[k++] = arr1[i++];
        } else {
            mergedArray[k++] = arr2[j++];
        }
    }

    while (i < n1) {
        mergedArray[k++] = arr1[i++];
    }

    while (j < n2) {
        mergedArray[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int mergedArray[n1 + n2];

    mergeSortedArrays(arr1, n1, arr2, n2, mergedArray);

    cout << "Merged Sorted Array: ";
    for (int i = 0; i < n1 + n2; i++) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    return 0;
}
