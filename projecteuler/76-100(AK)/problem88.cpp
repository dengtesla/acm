#include<bits/stdc++.h>
using namespace std;

int w[20];
int val[12000+100];

dfs(int n,int sz,int now,int mm)
{
    if(now==n)
    {
        int add = 0;
        int mul = 1;
        for(int i=0;i<sz;i++)
        {
            add += w[i];
            mul *= w[i];
        }
        int w = mul - add + sz;
        if(w<=12000) val[w] = min(val[w],n);
    }
    else
    {
        for(int i=mm;i*now<=n;i++)
        {
            if((n%(now*i)==0))
            {
                w[sz] = i;
                dfs(n,sz+1,now*i,i);
            }
        }
    }

}

int main()
{
    memset(val,0x3f,sizeof(val));
    for(int i=2;i<=15000;i++)
    {
        dfs(i,0,1,2);
    }
    sort(val+2,val+12001);
    int sz = unique(val+2,val+12001)-(val+2);
    int ans = 0;
    for(int i=0;i<sz;i++)
    {
        ans += val[2+i];
    }
    cout << ans << endl;
}
