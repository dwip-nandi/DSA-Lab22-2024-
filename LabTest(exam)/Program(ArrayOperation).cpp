#include <bits/stdc++.h>
using namespace std;
double hight_and_lowest(float arr[], int n)
{
    float hight = arr[0];
    float lowest = arr[0];
    int i,indexh=0,indexl=0;
    for ( i = 0; i < n; i++)
    {
        if (hight < arr[i]){
            hight = arr[i];
            if(hight=arr[i]){
                indexh = i;
            }
        }
            

        if (lowest > arr[i]){
            lowest = arr[i];
            if(lowest=arr[i]){
                indexl = i;
            }
        }
            
    }
    cout << "The Height WEIGHT is :" <<"Std["<<indexh<<"] :" << hight << endl;
    cout << "The Lowest WEIGHT is :" <<"Std["<<indexl<<"] :" << lowest << endl;
}
double average(float arr[], int n)
{
    double avg = 0;
    float total = 0;
    for (int i = 0; i < n; i++)
    {
        total +=arr[i];
    }
    avg =(float)total/n;

    cout<<"The average of the students WEIGHT is : "<<avg<<endl;
    return avg;
}
double newArray(float arr[],int n,float avg){
    float newarr[n+1];
    newarr[0]=avg;
    for(int i=1;i<n+1;i++){
        newarr[i]=arr[i-1];
    }
    cout<<"The array is : ";
    for(int i=0;i<n+1;i++){
       cout<< newarr[i]<<' ';
    }
    cout<<endl;
}

int main()
{
    cout << "Enter the Number of students:";
    int n;
    cin >> n;
    float arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the weight of student" << i + 1 << " : ";
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Std[" << i << "]" << "=>"  ;
        cout << arr[i];
        cout << endl;
    }
    cout << endl;

    // hight_and_lowest
    hight_and_lowest(arr, n);

    // average
    float avg =average(arr, n);
    //cout<<avg<<endl;
    //new array creat
    newArray(arr,n,avg);
}