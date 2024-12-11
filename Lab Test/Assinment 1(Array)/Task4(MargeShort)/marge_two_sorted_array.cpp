// Problem : Task 4: Merge Two Sorted Arrays 
// 1. Create a program in your preferred programming language (e.g., 
// Python, C++, Java) to merge two sorted integer arrays into a single 
// sorted array. 
// 2. Implement the merging algorithm efficiently with a time complexity 
// of O(n), where n is the total number of elements in both arrays. 
// 3. Print the merged sorted array.

#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> mergedArray;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            mergedArray.push_back(arr1[i]);
            i++;
        } else {
            mergedArray.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size()) {
        mergedArray.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size()) {
        mergedArray.push_back(arr2[j]);
        j++;
    }

    return mergedArray;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};

    vector<int> mergedArray = mergeSortedArrays(arr1, arr2);

    cout << "Merged Sorted Array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
