#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>p, pair<int,int>p2){
    return p.second<p2.second;
}
void activitySelect(vector<pair<int,int> > w){

    sort(w.begin(),w.end(),cmp);
    int last = 0;
    for(int i = 0;i<w.size();i++){
        if(w[i].first>=last){
           cout<<w[i].first<<" "<<w[i].second<<endl;
            last = w[i].second;
        }
    }
}
int main(){
    vector< pair<int,int> > v;
    cout<<"Enter Number of activities: ";
    int n; cin>>n;
    cout<<"Enter the activities Starting and Ending Time: "<<endl;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }
    cout<<"Following activities are selected "<<endl;
    activitySelect(v);
}
/*
7
3 7
2 4
5 8
6 9
1 11
10 12
0 3;
// = {{3,7},{2,4},{5,8},{6,9},{1,11},{10,12},{0,3} };
*/
