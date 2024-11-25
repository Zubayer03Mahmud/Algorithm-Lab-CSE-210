#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void insertionSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
            swap(arr[i], arr[minIndex]);
    }
}

void MergeSort(vector<int> &A,int l, int r)
{


    if(l>=r) return;
    int mid = (l+r)/2;
    int B[r-l+1];
    /// Divide
    MergeSort(A,l,mid);

    MergeSort(A,mid+1,r);


    int i=l, j=mid+1,k=0;
    while (i <= mid && j <= r)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }

    while (i <= mid)
    {
        B[k++] = A[i++];
    }

    while (j <= r)
    {
        B[k++] = A[j++];
    }
    for (int i = 0; i < k; ++i)
    {
        A[l + i] = B[i];
    }

    return ;
}

void Merge(vector<int> &A,int l, int mid, int r)
{
    int B[r-l+1];
    int i=l, j=mid+1,k=0;
    while (i <= mid && j <= r)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }

    while (i <= mid)
    {
        B[k++] = A[i++];
    }

    while (j <= r)
    {
        B[k++] = A[j++];
    }
    for (int i = 0; i < k; ++i)
    {
        A[l + i] = B[i];
    }

    return ;
}

void KMergeSort(vector<int> &A, int l, int r,int k)
{

    if (l < r)
    {
        int range = (r - l + 1) / k;
        int rem = (r - l + 1) % k;

        vector<int> mid(k);
        mid[0] = l-1;
        for (int i = 1; i < k; ++i)
        {
            mid[i] = mid[i - 1] + range +   (i <= rem ? 1 : 0);
        }

        for (int i = 0; i < k; ++i)
        {
            int left = mid[i]+1;
            int right = (i == k - 1) ? r : mid[i + 1] ;
            KMergeSort(A, left, right, k);
        }

        for (int i = 1; i < k; ++i)
        {
            Merge( A,l, mid[i - 1], mid[i] );
        }
        Merge( A,l, mid[k-1], r );
    }
}

void TMergeSort(vector<int> &A,int l, int r)
{
    if (l < r)
    {
        int range = r - l + 1;
        int mid1 = l + range / 3;
        int mid2 = l + 2 * range / 3;
        TMergeSort(A,l, mid1);
        TMergeSort(A,mid1 + 1, mid2);
        TMergeSort(A,mid2 + 1, r);
        Merge(A,l, mid1, mid2);
        Merge(A,l,mid2,r);
    }
}

void ttMergeSort(vector<int> &A,int l, int r)
{
    if (l < r)
    {
        int range = r - l + 1;
        int mid = l + range / 3;
        ttMergeSort(A,l, mid);
        ttMergeSort(A,mid + 1, r);
        Merge(A,l,mid,r);
    }
}

void RQuickSort(vector<int> &A, int l, int r)
{

    if(l>=r)return ;

    clock_t start = clock();
    srand(start);

    int lower = l;
    int upper = r;

    int p=lower + rand() % (upper - lower + 1);
    int L=l, R = r;

    while(l!=r)
    {

        if(p==l)
        {
            if(A[r]>=A[p])
                r--;
            else
            {
                swap(A[p],A[r]);
                p=r;
            }

        }

        else
        {
            if(A[l]<=A[p])
                l++;
            else
            {
                swap(A[p],A[l]);
                p=l;
            }

        }

    }

    RQuickSort(A,L,p-1);
    RQuickSort(A,p+1,R);


}


void QuickSort(vector<int> &A,int l, int r)
{

    if(l>=r)return ;


    int p=l;
    int L=l, R = r;

    while(l!=r)
    {

        if(p==l)
        {
            if(A[r]>=A[p])
                r--;
            else
            {
                swap(A[p],A[r]);
                p=r;
            }

        }

        else
        {
            if(A[l]<=A[p])
                l++;
            else
            {
                swap(A[p],A[l]);
                p=l;
            }

        }

    }

    QuickSort(A,L,p-1);
    QuickSort(A,p+1,R);


}

void heapify(vector <int> &a, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;


    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;


    if (largest != i)
    {
        swap(a[i],a[largest]);


        heapify(a, n, largest);
    }
}


void heapSort(vector <int> &a, int n)
{


    for (int i = n / 2 - 1; i >= 0; i--)
    {

        heapify(a, n, i);
    }


    for (int i = n - 1; i > 0; i--)
    {

        swap (a[0],a[i]);


        heapify(a, i, 0);
    }
}

void print(vector<int> A)
{
    int n=A.size();
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n,choice;


    do
    {
        cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

        cout << "\nChoose a sorting algorithm:\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Quick Sort\n";
        cout << "6. Heap Sort\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bubbleSort(arr);
            print(arr);
            break;
        case 2:
            selectionSort(arr);
            print(arr);
            break;
        case 3:
            insertionSort(arr);
            print(arr);
            break;
        case 4:
            char op;
            cout << "Choose merge sort\n";
            cout << "    1.2-Way Merge Sort\n";
            cout << "    2.3-Way Merge Sort\n";
            cout << "    3.k-Way Merge Sort\n";
            cout << "    4.2/3-Way Merge Sort\n";

            cin>>op;
            switch(op)
            {
            case 1:
                MergeSort(arr,0,n-1);
                print(arr);
                break;
            case 3:
                int k;
                cout<<"Enter k\n";
                cin>>k;
                KMergeSort(arr,0,n-1,k);
                print(arr);
                break;
            case 2:
                TMergeSort(arr,0,n-1);
                print(arr);
                break;
            case 4:
                ttMergeSort(arr,0,n-1);
                print(arr);
                break;
            }

            break;
        case 5:

            cout << "Choose Quick sort\n";
            cout << "    1.Traditional quick sort\n";
            cout << "    2.Randomized quick sort\n";
            cin>>op;
            switch(op)
            {
            case 1:
                QuickSort(arr,0,n-1);
                print(arr);
                break;
            case 2:
                RQuickSort(arr,0,n-1);
                print(arr);
                break;
            }
            break;
        case 6:
            heapSort(arr,n);
            print(arr);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please enter a number between 0 and 6.\n";
        }
        cout<<"Press 1 to continue and 0 to exit\n";
        cin>>choice;
    }
    while (choice != 0);

    return 0;
}

