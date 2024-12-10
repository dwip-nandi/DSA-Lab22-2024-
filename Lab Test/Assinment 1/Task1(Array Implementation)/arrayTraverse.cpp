#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter the number of Element of Your Array:";
    int n;
    cin >> n;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    cout<<"The elements of the array:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}