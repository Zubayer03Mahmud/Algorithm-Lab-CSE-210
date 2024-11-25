#include<bits/stdc++.h>
using namespace std;

int A[]={-10001,1,4,5,7,2,3,6};
///       0     1 2 3 4 5 6 7
int n=7;
//
//         (1)4
//
//     (2)1     (3)5
//
//  7(4) 2(5) 3(6)  (7)6


void Heapify(int i)
{
    /// if(i<=n/2) --> intermediate node.
    /// Otherwise heapify korbo na.
    if(i>n/2)return ; /// Because it not an intermediate node.


    int currentnode = i;
    int leftchild = 2*i;
    int rightchild = 2*i +1;

    ///if( (Jodi right child na thake) othoba (A[leftchild]> A[rightchild]) )
    if( (2*i +1 >n) || (A[leftchild]> A[rightchild]) )
    {
        /// compare current node with leftchild
        if(A[leftchild]>A[currentnode])
        {
            swap(A[leftchild],A[currentnode]);
            Heapify(leftchild);
        }
        /// Else current node is the largest one,
        /// So, we do not need to swap.
    }
    else {
        if(A[rightchild]>A[currentnode])
        {
            swap(A[rightchild],A[currentnode]);
            Heapify(rightchild);
        }
        /// Else current node is the largest one,
        /// So, we do not need to swap.
    }
}

void BuildHeap()
{

    int m=n/2; /// intermediateNode
    for(int i=m;i>=1;i--)
    {
        cout<<"Before Heapify\n";
            for(int j=1;j<=n;j++)
        {
            cout<<A[j]<<"  ";
        }
        cout<<endl;
        cout<<"-----------------\n";

        Heapify(i);
        cout<<"After Heapify\n";
            for(int j=1;j<=n;j++)
        {
            cout<<A[j]<<"  ";
        }
        cout<<endl;
        cout<<"-----------------\n";

    }
}


void Heapsort()
{
    /// N

    int N = n;
    int i = n;
    while(n>=1)
    {

        cout<<"Before Heapify\n";
            for(int j=1;j<=n;j++)
        {
            cout<<A[j]<<"  ";
        }
        cout<<endl;
        cout<<"-----------------\n";


///        cout<<A[1]<<" ";

        swap(A[1],A[n]);
        n--;
        Heapify(1);


        cout<<"After Heapify\n";
            for(int j=1;j<=n;j++)
        {
            cout<<A[j]<<"  ";
        }
        cout<<endl;
        cout<<"-----------------\n";
        getchar();



    }

    n = N;
}

int main()
{

    BuildHeap();
    cout<<"Performed BuildHeap Successfully!\n";

    Heapsort();
    cout<<"Performed HeapSort Successfully!\n";


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
