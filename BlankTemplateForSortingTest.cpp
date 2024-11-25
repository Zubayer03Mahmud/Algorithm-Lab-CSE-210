#include<bits/stdc++.h>
using namespace std;
int ar[100004];
void WriteFile()
{
    freopen("Input.txt","w",stdout);

    int N =10000;
    cout<<N<<endl;
    for(int i=0; i<N; i++)
    {
        int x = rand();
        cout<<x<<" ";
    }
    cout<<endl;

}

int br[100];

float QuickSort(int arr[],int N)
{
    float time = 0;
    clock_t start= clock();

    /// Coding Start




    /// Coding End


    clock_t total=  clock() - start;
//     time = start - ed;
    cerr<<setprecision(10)<<fixed;
    cerr<<"Total Time Taken in Quick Sort is "<< float(total)/1000.0<<endl;
}

float MergeSort(int ar[],int N)
{
    float time = 0;
    clock_t start= clock();

    /// Coding Start

    /// Coding End


    clock_t total=  clock() - start;
//     time = start - ed;
    cerr<<setprecision(10)<<fixed;
    cerr<<"Total Time Taken in Quick Sort is "<< float(total)/1000.0<<endl;
}

float BubbleSort(int ar[],int N)
{
    float time = 0;
    clock_t start= clock();

    /// Coding Start

    for(int i=0; i<N-1; i++)
    {
        bool check = true;
        for(int j=0; j<N-1-i; j++)
        {
            if(ar[j]> ar[j+1])
            {
                swap(ar[j],ar[j+1]);
                check = false;

            }
        }
        if(check == true)
            break;
    }

    cout<<"\nSorted Array(Bubble Sort) list is : ";

    for(int i=0; i<N; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<"\n";

    /// Coding End


    clock_t total=  clock() - start;
//     time = start - ed;
    cerr<<setprecision(10)<<fixed;
    cerr<<"Total Time Taken in Bubble Sort is "<< float(total)/1000.0<<endl;
}


float SelectionSort(int ar[],int N)
{
    float time = 0;
    clock_t start= clock();

    /// Coding Start

    for(int i=0; i<N-1; i++)
    {
        int min_index = i;

        for(int j=i+1; j<N; j++)
        {
            if(ar[j] < ar[min_index])
                min_index = j;
        }
        if(min_index != i)
            swap(ar[min_index], ar[i]);
    }

    cout<<"\nSorted aray (Selection Sort) : ";
    for(int i=0; i<N; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<"\n";


    /// Coding End


    clock_t total=  clock() - start;
//     time = start - ed;
    cerr<<setprecision(10)<<fixed;
    cerr<<"Total Time Taken in Selection Sort is "<< float(total)/1000.0<<endl;
}

float InsertionSort(int ar[],int N)
{
    float time = 0;
    clock_t start= clock();

    /// Coding Start
        for(int i=0; i<=N-1; i++)
    {
        int j = i;
        while(j>=0 && ar[j] < ar[j-1])
        {
            swap(ar[j], ar[j-1]);
            j--;

        }
    }

    cout<<"\nSorted array (Insertion Sort) : ";
    for(int i=0; i<N; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<"\n";


    /// Coding End


    clock_t total=  clock() - start;
//     time = start - ed;
    cerr<<setprecision(10)<<fixed;
    cerr<<"Total Time Taken in Insertion Sort is "<< float(total)/1000.0<<endl;
}
int main()
{
    WriteFile();

    freopen("Input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N;
    scanf("%d",&N);
    for(int i=0; i<N; i++)
    {
        scanf("%d",&ar[i]);
    }
    BubbleSort(ar,N);
    SelectionSort(ar,N);
    InsertionSort(ar,N);
//    QuickSort(ar,N ); ///
//    MergeSort(ar,N );
    ///....


    return 0;
}
