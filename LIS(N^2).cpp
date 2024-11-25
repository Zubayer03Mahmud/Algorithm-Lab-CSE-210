#include<bits/stdc++.h>
using namespace std;
int a[100];
 int memo[100];
int Prev[100];
 int f(int n)
{
    if(n==0)return 0;

    int MaxLis = 0;
    if(memo[n]!=-1) return memo[n];
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]<a[n])
        {
        int LisTillIthTerm = f(i);
        int curLis = LisTillIthTerm + 1;
        if(curLis>MaxLis)
            MaxLis = curLis, Prev[n]=i;
        }
    }
    memo[n]=MaxLis;
    return memo[n];
}
void Print(int ind)
{
     vector<int>ans;
    while(a[ind]!=INT_MIN){
        ans.push_back(a[ind]);
        ind=Prev[ind];
    }
    reverse(ans.begin(),ans.end());
    for(auto u: ans) cout<<u<<" ";
}
int main()
{
    int n;
    cout<<"Enter no of element : ";
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[0]=INT_MIN;
    for(int i=0;i<=10;i++)memo[i]=-1;
   int ind=0,mx=0;
    for(int i=0;i<=10;i++){
        int k=f(i);
        if(k>mx){
            mx=k;
            ind=i;
        }
    }
    cout<<"LIS = "<<mx<<endl;
    Print(ind);
    return 0;
}



