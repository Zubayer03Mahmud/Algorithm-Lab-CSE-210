#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int n,int i)
{
    int largest =i;
    int l=2*i+1;
    int r=2*i+2;
    while(l<n && a[l]>a[largest])
    {
        largest=l;
    }
    while(r<n && a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}
void heapSort(int a[],int n)
{
    for(int i=n/2-1; i>=0; i--)
    {

        heapify(a,n,i);
    }
    for(int i=n-1; i>=0; i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }

}
void printArray(int a[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{

    int n;
    cout<<"Enter array size:";
    cin>>n;
    int a[n];
    cout<<"Enter the array element:";

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    heapSort(a,n);
    cout<<"Sorted array(Heap Sort) :";
    printArray(a,n);
}
