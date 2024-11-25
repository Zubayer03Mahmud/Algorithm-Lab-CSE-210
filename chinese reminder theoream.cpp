//chinese Remainder theorem
#include<bits/stdc++.h>
using namespace std;
int gcdExtended(int a, int b, int* x, int* y)
{
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  int x1, y1;
  int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
int inverseOf(int A,int M)
{
     int x, y;
  int g = gcdExtended(A, M, &x, &y);
  if (g != 1) {cout << "Inverse doesn't exist"; exit(0); }
  else {
    int res = (x % M + M) % M;
    return res;
  }
  return 0;

}
int main()
{
    cout<<"Enter number of data:";
    int n;
    cin>>n;
    int num[n],rem[n],M=1;
    for(int i=0; i<n; i++)
    {
        cout<<i+1<<"th\n";
        cout<<"\tnum=";
        cin>>num[i];
        cout<<"\trem=";
        cin>>rem[i];
        M*=rem[i];
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {
        ans+=num[i]*(M/rem[i])*inverseOf(M/rem[i],rem[i]);
    }
    cout<<"X= "<<ans%M <<endl;
    return 0;
}
/*
3
2
3
3
5
2
7
*/
