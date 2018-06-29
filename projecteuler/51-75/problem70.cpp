#include<bits/stdc++.h>
using namespace std;
const int MAX = 10000000;


int mu[MAX+10];
bool isprime[MAX+10];
int prime[MAX+10];

void get_mobius(int n)
{
    mu[1] = 1;
    int tot = 0;
    memset(isprime,1,sizeof(isprime));
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
        {
            prime[++tot] = i;
            mu[i] = -1;
        }
        for(int j=1;prime[j]*i<=n;j++)
        {
            isprime[prime[j]*i] = 0;
            if(i%prime[j]==0)
            {
                mu[prime[j]*i] = 0;
                break;
            }
            mu[prime[j]*i]=-mu[i];
        }
    }
}

int euler[MAX+10];

void get_euler(int n)
{
    euler[1] = 1;
    int tot = 0;
    memset(isprime,1,sizeof(isprime));
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
        {
            prime[++tot] = i;
            euler[i] = i-1;
        }
        for(int j=1;prime[j]*i<=n;j++)
        {
            isprime[prime[j]*i] = 0;
            if(i%prime[j]==0)
            {
                euler[prime[j]*i] = prime[j]*euler[i];
                break;
            }
            euler[prime[j]*i] = euler[i]*(prime[j]-1);
        }
    }
}

bool com(const int &a,const int &b)
{
    int aa[10],bb[10];
    int a_length = 0;
    int b_length = 0;
    int _a = a;
    int _b = b;
    memset(aa,0,sizeof(aa));
    memset(bb,0,sizeof(bb));
    while(_a!=0)
    {
        aa[a_length] = _a%10;
        _a /= 10;
        a_length++;
    }
    while(_b!=0)
    {
        bb[b_length] = _b%10;
        _b /= 10;
        b_length++;
    }
    if(a_length!=b_length)
        return false;
    else
    {
        sort(aa,aa+a_length);
        sort(bb,bb+b_length);
        for(int i=0;i<a_length;i++)
        {
            if(aa[i]!=bb[i])
                return false;
        }
    }
    return true;
}

//debug
int main()
{
    get_euler(10000000);
    //if(com(euler[87109],87109)) cout << "yeah!" << endl;
    double ww = 2;
    int ans = 0;
    for(int i=2;i<=10000000;i++)
    {
        if(com(euler[i],i))
        {
            //cout << "now the ans is " << ans << endl;
            if((1.0*i/euler[i])<ww)
            {
                ww = 1.0*i/euler[i];
                ans = i;
                //cout << "now the ans is " << ans << endl;
            }
        }
    }
    cout << ans << endl;
}



