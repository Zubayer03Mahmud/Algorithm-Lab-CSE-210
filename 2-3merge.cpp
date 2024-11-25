#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int mid,int r)

{
    int n1=mid-l+1;
    int n2=r-mid;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++)
    {
        L[i]=a[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        R[j]=a[mid+1+j];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k++]=L[i++];
        }
        else
        {

            a[k++]=R[j++];
        }
    }
    while(i<n1)
    {
        a[k++]=L[i++];
    }
    while(j<n2)
    {
        a[k++]=R[j++];
    }


}
void towbythreewaymerge(int a[],int l,int r)
{
    if(l<r)
    {
        int range=r-l+1;
        int mid=l+range/3;
        towbythreewaymerge(a,l,mid);
        towbythreewaymerge(a,mid+1,r);
        merge(a,l,mid,r);
    }

}
int main()
{
    int n;
    cout<<"Enter the size:";
    cin>>n;
    int a[n];
    cout<<"Enter array element:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    towbythreewaymerge(a,0,n-1);
    cout<<"Sorted array(2 by 3 way ) : ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
