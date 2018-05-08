#include<bits/stdc++.h>
using namespace std;

int prime[10000000],primesize;
bool isprime[10000000];

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

int main()
{
    long long sum=0;
    getlist(2000100);
    for(int i=1;prime[i]<=2000000;i++)
    {
        sum += prime[i];
    }
    //cout << prime[1] << " " << prime[2] << endl;
    cout << sum << endl;
}
