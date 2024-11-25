#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cout<<"Enter no of elements : ";
    cin>>n;

    int arr[n];
    cout<<"Enter array element : ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    //insertion sort
    for(int i=0; i<=n-1; i++)
    {
        int j = i;
        while(j>=0 && arr[j] < arr[j-1])
        {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
    cout<<"\nSorted array (Insertion Sort) : ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}

