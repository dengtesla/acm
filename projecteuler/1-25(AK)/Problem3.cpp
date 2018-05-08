#include<bits/stdc++.h>
using namespace std;

// The prime factors of 13195 are 5, 7, 13 and 29.
//
// What is the largest prime factor of the number 600851475143 ?

int prime[1000000],primesize;
bool isprime[1000000];

void getlist(int listsize)
{
  memset(isprime,1,sizeof(isprime));
  isprime[1]=false;
  for(int i=2;i<=listsize;i++)
  {
    if(isprime[i]) prime[++primesize]=i;
    for(int j=1;j<=primesize&&i*prime[j]<=listsize;j++)
    {
      isprime[i*prime[j]]=false;
      if(i%prime[j]==0) break;
    }
  }
}

long long n=600851475143;

int main()
{
    int ans;
  int a = sqrt(n);
  getlist(a);
  //cout << prime[2] << endl;
  for(int i=1;prime[i]!=0;i++)
  {
      //cout << prime[i] << endl;
    if(n%prime[i]==0)
    {
        ans=prime[i];
      //cout << prime[i] << endl;
    }
  }
  cout << ans << endl;
}

/*
int main()
{
    getlist(101);
    for(int i=1;i<=101;i++)
    {
        cout << prime[i] << endl;
    }
}
*/
