#include<bits/stdc++.h>
using namespace std;
//partition
int partition( int arr[], int low, int high)
{
    //pivot first element
    int pivot = arr[low];
    int start = low;
    int endd = high;

    while(start < endd)
    {
        while(arr[start] <= pivot)
        {
            {
                start++;
            }
            while(arr[endd] > pivot)
            {
                endd--;
            }
            if(start < endd)
            {
                swap(arr[start], arr[endd]);
            }
        }
        swap(arr[low], arr[endd]);
        return endd;
    }

}


void quicksort(int arr[], int low, int high)
{
    if(low<high)
    {
        //partition index
        int pt = partition(arr, low, high);
        quicksort(arr, low, pt -1);
        quicksort(arr, pt+1, high);
    }

}
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
    quicksort(arr,0,n-1);
    cout<<"\nSorted Array(Quick Sort) list is : ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;

}
