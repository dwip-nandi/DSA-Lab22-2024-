#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int binarySearch(const vector<string>& arr, const string& key) {
    int lowerBound = 0;
    int upperBound = arr.size() - 1;
    while (lowerBound <= upperBound) {
        int midPoint = lowerBound + (upperBound - lowerBound) / 2;
        if (arr[midPoint] == key) {
            return midPoint;
        } else if (arr[midPoint] < key) {
            lowerBound = midPoint + 1;
        } else {
            upperBound = midPoint - 1;
        }
    }
    return -1; 
}

int main() {
    vector<string> arr = {"apple", "banana", "cherry", "date", "fig", "grape"};
    sort(arr.begin(), arr.end()); 
    cout<<"Sorted array string is : ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    cout << "Enter the string to search: ";
    string key;
    cin >> key;
    int result = binarySearch(arr, key);
    if (result != -1) {
        cout << "The string is present at index: " << result+1 << endl;
    } else {
        cout << "The string is not present in the array." << endl;
    }
    return 0;
}
