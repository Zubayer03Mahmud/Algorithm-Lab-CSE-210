///Fractional Knapsack
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int,int>> v;
    cout<<"Enter the Number of Item: ";
    int n,i=0,p=0,w;
    cin>>n;
    cout<<"Enter weights(kg) and profit(per kg) of the items"<<endl;
    for(int i=0;i<n;i++){
        int p,w; cin>>w>>p;
        v.push_back({p,w});
    }
     sort(v.begin(),v.end(),greater<pair<int,int>>());
   cout<<"Enter Your knapsack Capacity: "; cin>>w;
    cout<<"\nthe Greedy Selection: "<<endl;
    while(i<v.size() && w>0){
        if(v[i].second>w){
            p+= w*v[i].first;
             cout<<"Item that Profits "<<v[i].first<<"-> ";
            cout<<w<<"kg profit = "<<v[i].first*w<<'\n';
            w = 0;
        }else{
            w -= v[i].second;
            p+= v[i].second*v[i].first;
            cout<<"Item that Profits "<<v[i].first<<"-> ";
            cout<<v[i].second<<"kg profit = "<<v[i].first*v[i].second<<'\n';
        }
        i++;
    }
    cout<<"Total Profit = "<<p<<endl;

}
