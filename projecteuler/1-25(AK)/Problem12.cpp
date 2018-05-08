#include<bits/stdc++.h>
using namespace std;

int prime[1000010],primesize;
bool isprime[1000100];
int prime_cishu[1001000];

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

int fenjie(long long t)
{
    int c=0,ans=1;
    int aa = t;
    memset(prime_cishu,0,sizeof(prime_cishu));
    for(int i=1;i<=aa/2;i++)
    {
        if(t%prime[i]==0)
        {
           //cout << i << endl;
            t = t / prime[i];
            prime_cishu[i]++;
            i--;

        }
        if(t == 1)
        {
            c = i;
            break;
        }
    }
    //cout << t << endl;
    for(int i=1;i<=c+1;i++)
    {
        ans *= (prime_cishu[i]+1);
    }
    return ans;
}


int main()
{
    getlist(1000000);
    long long ans = 1;
    int n=2;
    while(fenjie(ans)<=500)
    {
        ans = (1+n)*n/2;
        n++;
    }
    cout << ans << endl;
    //cout << fenjie(76576500) << endl;
    return 0;
}
