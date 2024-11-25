#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int lb,int mid,int ub)
{
    int n1=mid-lb+1;
    int n2=ub-mid;
    int L[n1];
    int M[n2];
    for(int i=0;i<n1;i++)
    {
        L[i]=a[lb+i];

    }
    for(int j=0;j<n1;j++)
    {
        M[j]=a[mid+1+j];

    }
    int i,j,k;
    i=0;
    j=0;
    k=lb;
    while(i<n1 && j<n2)
    {
        if(L[i]<=M[j])
        {
            a[k]=L[i];
            i++;

        }
        else
        {

            a[k]=M[j];
            j++;
        }
        k++;
    }
     while(i<n1)
    {

            a[k]=L[i];
            i++;
            k++;

    }
     while(j<n2)
    {

            a[k]=M[j];
            j++;
            k++;

    }
}

void mergesort(int a[],int lb,int ub)
{

    if(lb<ub)
    {
        int mid=(lb+ub)/2;

        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
int main()
{
    int n;
    cout<<"Enter the array size:";
    cin>>n;
    int a[n];
    cout<<"Enter the element:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    cout<<"Sorted array:";
  for(int i=0;i<n;i++){

   cout<<a[i]<<" ";
  }
}

