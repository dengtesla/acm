#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long n = 4;
  int a[100001];
  memset(a,0,sizeof(a));
  a[0] = 1;
  a[1] = 1;
  for(long long i=3;i<=n-1;i+=2)
  {

    for(int j=0;j<=i*(i-1)/2;j++)
    a[j+i] += a[j];
  }
//  cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << " " << a[5] << endl;
}
