#include<bits/stdc++.h>
using namespace std;
int prime[1000000];
bool isprime[10000000];

void getlist(int listsize)
{
    memset(isprime,1,sizeof(isprime));
    isprime[1] = false;
    int primesize = 0;
    for(int i = 2;i<=listsize;i++)
    {
        if(isprime[i]) prime[++primesize] = i;
        for(int j = 1;i*prime[j]<=listsize&&j<=primesize;j++)
        {
            isprime[i*prime[j]] =false;
            if(i%prime[j]==0) break;
        }
    }
}

int main()
{
    getlist(10000000);
    //int c=0;
    int ans1 = 0;
    int ans2 = 0;
    //for(int i=1;prime[i]<=1000;i++) c++;
    for(int b=1;prime[b]<=1000;b++)
    {
        for(int a=-1000;a<=1000;a++)
        {
            for(int ss=-1;ss!=3;ss+=2)
            {
                int cnt=0;
                for(int n=0;isprime[n*n+a*n+prime[b]]!=false&&n*n+a*n+prime[b]>0;n++)
                    cnt ++;
                if(cnt>=ans1)
                {
                    ans1 = cnt;
                    ans2 = a*prime[b];
                }
            }
        }
    }
    //cout << ans1 << endl;
    cout << ans2 << endl;
}
