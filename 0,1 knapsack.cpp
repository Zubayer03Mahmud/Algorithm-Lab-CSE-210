#include<bits/stdc++.h>
using namespace std;
int weight[100];
int  profit[101];
int memo[100][100];

int func(int i, int Kcap)
{
    if(i==0 || Kcap==0) return 0;
    if(memo[i][Kcap]!=0) return memo[i][Kcap];
    int Nibo=0,NiboNa=0;
    if(Kcap-weight[i]>=0)
        Nibo = func(i-1,Kcap-weight[i]) + profit[i];
    NiboNa = func(i-1, Kcap);
    return memo[i][Kcap]=max(Nibo,NiboNa);
}1

void pathPrint(int i, int Kcap)
{
    if(i==0 || Kcap==0) return;
    if(memo[i][Kcap]>memo[i-1][Kcap]){
        cout<<i<<" ";
        pathPrint(i-1,Kcap-weight[i]);
    }
    else pathPrint(i-1,Kcap);
}

int main()
{
    int n,Kcap;
    cout<<"Enter the Number of Item: "; cin>>n;
    cout<<"Enter weights(kg) and profit(per kg) of the items"<<endl;
    for(int i=1;i<=n;i++){
       cin>>weight[i]>>profit[i];
    }
    cout<<"Enter Your knapsack Capacity: "; cin>>Kcap;
    cout<<"The Resultant Matrix"<<endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=Kcap; j++){
            cout<<setw(3)<<func(i,j)<<" ";
        }
        cout<<endl;
    }
    cout<<"\nMaximum Profit is : "<<func(n,Kcap)<<endl;

    cout<<"Selected Items no. are : ";
    pathPrint(n,Kcap);
}
