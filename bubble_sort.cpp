#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter no of elements : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array element : ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    //bubble sort
    for(int i=0; i<n-1; i++)
    {
        //bool check = true;
        for(int j=0; j<n-1-i; j++)
        {
            if(arr[j]> arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                //check = false;
            }
        }
//        if(check == true)
//            break;
    }
    cout<<"\nSorted Array(Bubble Sort) list is : ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
