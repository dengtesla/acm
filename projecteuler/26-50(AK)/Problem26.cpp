#include<bits/stdc++.h>
using namespace std;
int prime[100000],listsize;
bool isprime[10000];

void getlist(int listsize)
{
    int primesize=0;
    memset(isprime,1,sizeof(isprime));
    isprime[1] = false;
    for(int i=2;i<=listsize;i++)
    {
        if(isprime[i]) prime[++primesize]=i;
        for(int j =1;i*prime[j]<=listsize&&j<=primesize;j++)
        {
            isprime[prime[j]*i] = false;
            if(i%prime[j]==0) break;
        }
    }
}


int main()
{
    //getlist(1000);
    int a;
    int ans=0;
    int ans1=0;
    int ins = 1;
    bool tot[1001];
    memset(tot,false,sizeof(tot));
    for(int i = 1;i<=1000;i++)
    {
        a = i;
        while(a%2==0&&tot[a]==false)
        {
            tot[a]==true;
            a /= 2;
        }
        while(a%5==0&&tot[a]==false)
        {
            tot[a]==true;
            a /= 5;
        }
        if(tot[a]==false)
        {
            for(int k=1;k<=1000;k++){
                ins *= 10;
                if((ins+a)%a==1){
                        if(k>ans){
                    ans = max(ans,k);
                    ans1 = a;
                        }
                    //cout << "The " << a << " is " << k << endl;
                    break;
                }
                else ins = ins % a;
            }
            ins = 1;
            tot[a]==true;
        }
    }
    cout << ans1 << endl;
}
