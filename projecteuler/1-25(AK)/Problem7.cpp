#include<bits/stdc++.h>
using namespace std;

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

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
    getlist(1000000);
    cout << prime[10001] << endl;
}
