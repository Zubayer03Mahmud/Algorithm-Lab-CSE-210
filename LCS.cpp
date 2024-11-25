// LCS tabular dp
#include<bits/stdc++.h>
using namespace std;
int LCS(string &s1, string &s2, int n, int m)
{
    int i,j,table[n+1][m+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0) table[i][j]=0;
            else if(s1[i-1]==s2[j-1]) table[i][j]=table[i-1][j-1]+1;
            else table[i][j]=max(table[i-1][j],table[i][j-1]);
        }
    }
    return table[n][m];
}
int main()
{
    string s1,s2;
    int n,m;
    cout<<"Enter the 1st string: ";
    cin>>s1;
    cout<<"Enter the 2nd string: ";
    cin>>s2;
    n=s1.size();
    m=s2.size();
    cout<<"Length of LCS is: "<<LCS(s1,s2,n,m)<<endl;
}

