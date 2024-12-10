#include <bits/stdc++.h>
using namespace std;
//sum function
int sum_of_Array(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
// for determine average 
double average(int sum,int n){
    double avg =(double)sum/n;
    return avg;
}
//max and min
void max_and_min(int arr[],int n){
    int min=arr[0];
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<min)min=arr[i];
        if(arr[i]>max)max=arr[i];
    }
    cout<<"The maximum value is = "<<max<<endl;
    cout<<"The minimmum value is = "<<min<<endl;

}
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
    //vew the elements of array
    cout<<"The elements are:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout<<endl;
    //for summation
    int sum = sum_of_Array(arr, n);
    cout << "The sum of these elements = " << sum<<endl;

    //for average
    double avg =average(sum,n);
    cout<<"The average is the Elements = "<<avg<<endl;
    //for max and min element
    max_and_min(arr,n);
    return 0;
}