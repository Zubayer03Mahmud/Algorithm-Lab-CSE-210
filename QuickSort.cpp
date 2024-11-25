#include<bits/stdc++.h>
using namespace std;

int A[]={-10001,1,4,5,7,2,3,6};
///       0     1 2 3 4 5 6 7
int n=7;

void QuickSort(int l, int r)
{
    /// Base Case.
    if(l>=r)return ;

/// For randomized quick sort, we need to edit the line below.
/// For randomized quick sort, p should be random value within the range from l to r.

    int p=l;
    int L=l, R = r;

    while(l!=r)
    {
        /// pivot left a
        if(p==l)
        {
            /// Compare A[p] , A[r]
            /// Satisfy Criteria: A[r]>=A[p]  , r--;
            /// Otherwise, swap (A[r], A[p]) && p = r;
            ///
        }
        /// pivot right a
        else
        {
            /// Compare A[p] , A[l]
            /// Satisfy Criteria: A[l]<=A[p]  --> l++;
            /// Otherwise, swap (A[l], A[p]) && p = l;
            ///
        }

    }

    /// l=r=p

    (L=1,R=4)
    QuickSort(L,p-1);
    QuickSort(p+1,R);


}



int main()
{
    QuickSort(1,7);
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
