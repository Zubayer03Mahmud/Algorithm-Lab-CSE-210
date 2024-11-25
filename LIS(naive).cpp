#include<bits/stdc++.h>
using namespace std;
int n;
int ara[100000];
int dp[10000];
int lis(int a)
{
    if(dp[a]!=0) return dp[a];
    int ans=1;
    for(int i=1;i<=a;i++){
            if(ara[a]>ara[i]){
        ans=max(ans,lis(i)+1);
            }
    }
    dp[a]=ans;
    return ans;
}

int main()
{

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,lis(i));
    }
    cout<<ans<<endl;


    return 0;
}
