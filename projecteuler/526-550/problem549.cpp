#include<bits/stdc++.h>
using namespace std;

int p[100000000+10];
bool isp[100000000+10];
int val[100000000+10];
int mv[100000000+10];
int mvt[100000000+10];


void seive1(int sz)
{
    memset(isp,1,sizeof isp);
    isp[1] = 0;
    int tot = 0;
    for(int i=2;i<=sz;i++)
    {
        if(isp[i])
        {
            p[++tot] = i;
            mv[i] = i;
            mvt[i] = 1;
        }
        for(int j=1;p[j]*i<=sz&&j<=tot;j++)
        {
            isp[p[j]*i] = 0;
            if(i%p[j]==0)
            {
                mv[i*p[j]] = p[j];
                mvt[i*p[j]] = mvt[i] + 1;
                break;
            }
            mv[i*p[j]] = p[j];
            mvt[i*p[j]] = 1;
        }
    }
}

int poww(int a,int b)
{
    int base = a;
    int ans = 1;
    while(b)
    {
        if(b&1)
        {
            ans *= base;
        }
        base *= base;
        b>>=1;
    }
    return ans;
}

long long get_val(long long p,long long n)
{
    long long res = 0;
    while(n)
    {
        res += n/p;
        n/=p;
    }
    return res;
}



long long gogogo(long long p,long long k)
{
    if(k==1) return p;
    long long l = 1,r = 100000000,mid;
    mid = (l+r)/2;
    while(l<r)
    {
        mid = (l+r)/2;
        long long w = get_val(p,mid*p);
        if(w<k)
        {
            l = mid+1;
        }
        else if(w>=k)
        {
            r = mid;
        }
    }
    return l*p;

}

void seive2(int sz)
{
    val[1] = 1;
    int tot = 0;
    for(int i=2;i<=sz;i++)
    {
        if(isp[i])
        {
            tot++;
            val[i] = i;
        }
        for(int j=1;p[j]*i<=sz&&j<=tot;j++)
        {
            if(i%p[j]==0)
            {
                int w = poww(mv[i*p[j]],mvt[i*p[j]]);
                if(i*p[j]==w)
                {
                    val[i*p[j]] = gogogo(mv[i*p[j]],mvt[i*p[j]]);
                }
                else
                {
                    val[i*p[j]] = max(val[w],val[i*p[j]/w]);
                }
                break;
            }
            val[i*p[j]] = max(p[j],val[i]);
        }
    }
}

int main()
{
    seive1(100000002);
    seive2(100000002);
    long long res = 0;
    for(int i=2;i<=100000000;i++)
    {
        res += val[i];
    }
    cout << res << endl;
}

