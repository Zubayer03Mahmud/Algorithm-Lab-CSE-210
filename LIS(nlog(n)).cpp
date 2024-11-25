#include<bits/stdc++.h>
using namespace std;

int ara[100];
int insertat[100];
vector<int>v;

void func(int n) ///O(nlog(n))
{
    for(int i=1; i<=n; i++){ ///O(n)
        if(v.empty() || ara[i]>v[v.size()-1]){
            v.push_back(ara[i]);
            insertat[i]=v.size();
        }
        else{
            auto it= lower_bound(v.begin(),v.end(),ara[i]); ///O(logn)
            *it=ara[i];
            insertat[i]=it-v.begin()+1;
        }
    }
}

void printLIS(int n)
{
    vector<int>ans;
    int len=v.size();
    for(int i=n; i>0; i--){
        if(insertat[i]==len){
            ans.push_back(ara[i]);
            len--;
            if(len==0) break;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<"LIS = "<<v.size()<<endl;
    for(auto u: ans) cout<<u<<" ";
}

int main()
{
    int n;
    cout<<"Enter no of element : ";
    cin>>n;
    for(int i=1; i<=n; i++) cin>>ara[i];
    func(n);
    printLIS(n);
    return 0;
}

/*
10
9 2 5 3 7 11 8 10 13 6
*/
