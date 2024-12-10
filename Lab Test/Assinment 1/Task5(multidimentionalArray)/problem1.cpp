// declear 2D array
#include <bits/stdc++.h>
using namespace std;
// int toSearch(int arr[][5], int col)
// {
//     cout << "Enter the value, What you want:";
//     int value;
//     cin >> value;
//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = 0; j <col; j++)
//         {
//             if (arr[i][j] == value)
//                 return arr[i][j];
//             break;
//         }
//         cout << endl;
//     }
// }

int main()
{
    int x;
    cout << "Enter the number of column of 2D Array:";
    cin >> x;
    int arr[2][x];
    srand(time(0));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < x; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    
    //for searching
    cout<<"Enter the value to search:";
    int value;
    cin>>value;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if(value==arr[i][j]){
                cout<<arr[i][j]<<endl;
            }
        }
    }

}