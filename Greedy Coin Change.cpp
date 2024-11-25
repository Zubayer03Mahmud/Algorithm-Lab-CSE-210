///coin changing
///complexity O(n) n==number of denominations;
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1,5,10,25,100};
    int i = 0, t=0, cnt=0, ca=0,n;
    cout<<"Enter the amount : ";
    cin>>n;
    reverse(v.begin(),v.end());

    cout<<"\nCoins quantity :\n";
    while(i<v.size() && n>0){
        ca  = n/v[i];
       cout<<"\t"<<v[i]<<"-> " <<ca<<"\n";
        n = n%v[i]; i++; cnt+=ca;
    }
    cout<<"Total coin used : "<<cnt<<"\n";
    return 0;
}
