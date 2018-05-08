#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
int prime[MAX+100];
bool isprime[MAX+10];
bool searched[MAX+10];

// Overlord Tesla!!

void get_prime(int n)
{
    memset(isprime,1,sizeof(isprime));
    isprime[1] = 0;
    int tot = 1;
    for(int i=2;i<=n;i++)
    {
        if(isprime[i]) prime[tot++] = i;
        for(int j=1;prime[j]*i<=n&&j<=tot;j++)
        {
            isprime[i*prime[j]] = 0;
            if(i%prime[j]==0) break;
        }
    }
}

int poww(int a,int b)
{
    int c = 1;
    for(int i =1;i<=b;i++)
    {
        c *= a;
    }
    return c;
}

int panduan(int n,int weishu)
{
    int w = n;
    for(int i=1;i<=weishu;i++)
    {
        int t = n % 10;
        if(t%2==0)
        {
            return 0;
        }
        n = n / 10; //if(w == 197) cout << n << " + ";
        n = n + poww(10,weishu-1) * t;// if(w == 197) cout << pow(10,weishu-1) * t << " = ";
        //if(w == 197) cout << n << endl;
        if(isprime[n]==0) return 0;
    }
    return 1;
}

int main()
{
    get_prime(1000000);
    int ans = 0;
    for(int i = 1;prime[i]!=0;i++)
    {
        int weishu = 0;
        int n = prime[i];
        while(n!=0)
        {
            n /= 10;
            weishu ++;
        }
        if(weishu==1) ans ++;
        else
        {
            if(panduan(prime[i],weishu)==1) //cout << prime[i] << endl;
                ans += 1;
        }
    }
    //cout << 197 / 10 + pow(10,2)*7 << endl;
    cout << ans << endl;
}
