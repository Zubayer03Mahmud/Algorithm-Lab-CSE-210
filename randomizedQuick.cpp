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

int partition_r(int arr[], int low, int high)
{
    srand (time(NULL));
    int random = low + rand() % (high - low );

    //cout<<random<<endl;
    swap(arr[random], arr[low]);
    return partition(arr,low,high);
}


void Ran_Qsort(int arr[], int low, int high)
{
    if(low<high)
    {
        //partition index
        int pt = partition_r(arr, low, high);
        Ran_Qsort(arr, low, pt -1);
        Ran_Qsort(arr, pt+1, high);
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
    Ran_Qsort(arr,0,n-1);
    cout<<"Sorted Array(Randomized Quick Sort): ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;

}
