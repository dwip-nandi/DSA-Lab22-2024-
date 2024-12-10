// implementation the binary search of a string

#include <bits/stdc++.h> 
using namespace std;

int binarySearch(const string& str, char key) {
    int lowerBound = 0;
    int upperBound = str.size() - 1;
    while (lowerBound <= upperBound) {
        int midPoint = lowerBound + (upperBound - lowerBound) / 2;
        if (str[midPoint] == key) {
            return midPoint;
        } else if (str[midPoint] < key) {
            lowerBound = midPoint + 1;
        } else {
            upperBound = midPoint - 1;
        }
    }
    return -1; 
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    sort(str.begin(), str.end()); 
    cout<<"Sorted string is :";
    cout<<str<<endl;
    cout << "Enter the character to search: ";
    char key;
    cin >> key;
    int result = binarySearch(str, key);
    if (result != -1) {
        cout << "The character is present at index: " << result+1 << endl;
    } else {
        cout << "The character is not present in the string." << endl;
    }
    return 0;
}
