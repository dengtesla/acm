#include<bits/stdc++.h>
using namespace std;
#define N 2000000
vector <pair<long long,int>> d[2000004];

void init()
{
    d[1].push_back({1,1});
    for(long long i=2;i<=N;i++)
    {
        if(d[i].empty())
        {
            for(long long j=i;j<=N;j+=i)
                d[j].push_back({i,1});

            long long w=i*i;
            while(w<=N)
            {
                for(long long j=w;j<=N;j+=w)
                    d[j][d[j].size()-1].second++;
                w*=i;
            }

        }
    }
}
int ans[2000000];

void pending(int res,int w)
{
    if(res<=2*w-1&&res>=w+1)
        ans[w]++;

}



void dfs(int i,int w,int res)
{
    if(i>=d[w].size())
    {
        pending(res,w);
    }
    else
    {
        for(int j=0;j<=d[w][i].second;j++)
        {
            res*=pow(d[w][i].first,j);
            dfs(i+1,w,res);
            res/=pow(d[w][i].first,j);
        }
    }
}


void dod(int w)
{
    for(int i=0;i<d[w].size();i++)
    {
        d[w][i].second*=2;
    }
    if(w%2==0)
        d[w][0].second++;
    else
    d[w].push_back({2,1});

    dfs(0,w,1);
}



int main()
{
    init();
    int T=1500000;
    for(int i=2;i<=T;i+=2)
    {
        dod(i/2);
    }
    int aans = 0;
    for(int i=2;i<=T/2;i++)
    {
        if(ans[i]==2)
            aans++;
    }
    cout << aans << endl;
}
