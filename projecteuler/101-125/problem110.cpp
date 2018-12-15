#include<bits/stdc++.h>
using namespace std;
#define ll long long


#define MAXIMUM 26
int prime[1000000];
bool isprime[1000000];

void get_prime(int listsize)
{
    int primesize=1;
    memset(isprime,1,sizeof(isprime));
    isprime[1] = false;
    for(int i=2;i<=listsize;i++)
    {
        if(isprime[i]) prime[primesize++]=i;
        for(int j=1;i*prime[j]<=listsize&&j<=primesize;j++)
        {
            isprime[i*prime[j]] = false;
            if(i%prime[j]==0) break;
        }
    }
}

struct factor
{
    ll time[20];
    ll value[20];
    ll res;
};

queue<factor> q;

bool check(factor w,int t)
{
    ll res = 1;
    for(int i=1;i<=t;i++)
    {
        res *= (2*w.time[i]+1);
    }
    res += 1;
    res /=2;
    //cout << t << " : " << res << endl;
    if(res>4000000) return 1;
    return 0;
}

void gogogo(factor w,int t)
{
    for(int i=1;i<=t;i++)
    {
        cout << w.time[i] << " ";
    }
    cout << endl;
}

int main()
{
    ll ans = 1000000000000000000;
    get_prime(500000);
    factor p;
    int n;
    for(int i=1;i<=15;i++)
    {
        p.value[i] = prime[i];
    }

    for(int i=12;i<=15;i++)
    {
        while(!q.empty()) q.pop();
        p.res = 1;
        for(int j=1;j<=i;j++)
        {
            p.time[j] = 1;
            p.res *= p.value[j];
        }
        //cout << p.res << endl;
        q.push(p);
        while(!q.empty())
        {
            //cout << q.size() << endl;
            factor test = q.front();
            for(int j=1;j<=i;j++)
            {
                if(j==1)
                {
                    factor ttest = test;
                    ttest.time[j]++;
                    ttest.res *= ttest.value[j];
                    //cout << ttest.res << endl;
                    if(ttest.res<0) continue;
                    if(check(ttest,i)){ans = min(ans,ttest.res);/*gogogo(ttest,i);*/}
                    else q.push(ttest);
                }
                else
                {
                    if(test.time[j]<test.time[j-1])
                    {
                        factor ttest = test;
                        ttest.time[j]++;
                        ttest.res *= ttest.value[j];
                        //cout << ttest.res << endl;
                        if(ttest.res<0) continue;
                        if(check(ttest,i)){ans = min(ans,ttest.res);/*gogogo(ttest,i);*/}
                        else q.push(ttest);
                    }
                }
            }
            q.pop();
        }
    }
    cout << ans << endl;
}
/*
9350130049860600

Process returned 0 (0x0)   execution time : 5.699 s
Press any key to continue.

*/
