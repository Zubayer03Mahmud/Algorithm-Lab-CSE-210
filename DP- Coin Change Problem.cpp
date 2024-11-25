#include<bits/stdc++.h>
using namespace std;
#define LL long long
vector<int> c= {1,5,7,9};
int dp[10001][10001];
LL func(LL n, LL k) {
    if(k==0) return 0;
    if(n<0 || k<0) return INT_MAX;
    if(dp[n][k]!=-1) return dp[n][k];
    LL p=func(n, k-c[n])+1;
    LL np=func(n-1,k);
    return dp[n][k]=min(p,np);
}
void print(LL n,LL k) {
    if(n<0 || k<0) return;
    LL p=func(n, k-c[n])+1;
    LL np=func(n-1,k);
    if(p==func(n,k)) {
        cout<<c[n]<<" ";
        print(n,k-c[n]);
        return;
    }
    print(n-1,k);
}
int main() {
    memset(dp,-1,sizeof(dp));
    LL k;
    cout<<"Coin value to make using(1,5,7,9) : ";
    cin>>k;
    cout << "Minimum number of coins needed to make " << k << " is : " << func(3,k)<<endl;
    cout<<"the coins are: ";
    print(3,k);
    return 0;
}

