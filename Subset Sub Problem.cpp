#include<bits/stdc++.h>
using namespace std;
#define LL long long
vector<int> c= {1,5,7,9};
int dp[10001][10001];
bool func(LL n, LL k) {
    if(k==0) return 1;
    if(n<0 || k<0) return 0;
    if(dp[n][k]!=-1) return (bool)dp[n][k];
    LL p=func(n-1, k-c[n]);
    LL np=func(n-1,k);
    return dp[n][k] = p | np;
}

void print(LL n,LL k) {
    if(n<0 || k<0) return;
    bool p=func(n-1, k-c[n]);
    bool np=func(n-1,k);
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
    cout<<"Enter k Subset Sub using (1,5,7,9) : ";
    cin>>k;
    if(func(3,k)) {
        cout<<"Possible to make  using below elements:"<<endl;
        print(3,k);
    } else cout<<"Not possible to make"<<endl;
    return 0;
}
