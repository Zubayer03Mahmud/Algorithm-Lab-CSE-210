#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter no of elements : ";
    cin>>n;
    int ar[n];
    cout<<"Enter aray element : ";
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
    }

    //selection sort
    for(int i=0; i<n-1; i++)
    {
        int min_index = i;

        for(int j=i+1; j<n; j++)
        {
            if(ar[j] < ar[min_index])
                min_index = j;
        }
        if(min_index != i)
            swap(ar[min_index], ar[i]);
    }
    cout<<"\nSorted aray (Selection Sort) : ";
    for(int i=0; i<n; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
