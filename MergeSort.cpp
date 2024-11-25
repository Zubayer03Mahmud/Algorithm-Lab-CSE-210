#include<bits/stdc++.h>
using namespace std;

int A[]={-10001,1,4,5,7,2,3,6};
///       0     1 2 3 4 5 6 7
int n=7;
int temp[100];
void MergeSort(int l, int r)
{                 10      20

/// When we have less than equals to one element in the range,
    /// Then the range is either sorted or the range is invalid.
    /// And thats the base case.

    int mid = (l+r)/2;

    /// Divide
    MergeSort(l,mid);

    MergeSort(mid+1,r);

    /// Conqure Part
    /// Given Array is named as "A"
    A [1 2 5 7]       [ 4 3 6]
       i=l   mid    j=mid+1  r
    /// Temporary Array is named as "B"
    B [] [] [] []       [] [] []
       l l+1 l+2 l+3           r




        /// Assume that, Subarray A[l,mid] range is sorted.
        /// Assume that, Subarray A[mid+1,r] range is sorted.
        ///Now, we need to merge these subarrays,
        /// to produce a sorted subarray A[l,r] which is also sorted.

        for(int k=l;k<=r;k++)
        {

///      Both bucket a element ase.
         B[i]  B[j]
         if(i<=mid && j<=r)
         {
             /// Dekhbo, A[i] choto , naki A[j] choto,
             A[i] choto hole, A[i] ke nibo, i++ hobe,
             Otherwise, A[j] ke nibo, j++ hobe.
         }
         else if(i<=mid) /// Only left bucket a element ase.
         {
             A[i] ke nibo, i++;
         }
         else /// Only right bucket a element ase.
         {
             A[j] ke nibo, j++;
         }
          B[k] te winner boshbe.
        }

        /// Copy from B to A
            for(int k=l;k<=r;k++)A[k]=B[k];


        return ;
}



int main()
{
    MergeSort(1,7);

//    BuildHeap();
//    cout<<"Performed BuildHeap Successfully!\n";
//
//    Heapsort();
//    cout<<"Performed HeapSort Successfully!\n";


        cout<<"After Heapsort\n";
        for(int j=1;j<=n;j++)
        {
            cout<<A[j]<<"  ";
        }
        cout<<endl;


//    clock_t start = clock();
//    srand(start);
//
//    for(int i=1;i<=5;i++)
//    {
//        cout<<rand()<<endl;
//    }

    return 0;
}
