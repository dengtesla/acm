#include<bits/stdc++.h>
using namespace std;
#define N 2000000
vector <pair<int,int>> d[N+4];

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

bool pending(int a,int c)
{
    //cout << 111111 << endl;
    map <int,int> res;
    for(auto it = 0;it<d[a].size();it++)
    {
        res[d[a][it].first] = d[a][it].first;
    }
    //cout << 2111111 << endl;
    for(auto it = 0;it<d[c].size();it++)
    {
        //res[d[c][it].first] = d[c][it].first;
        //res[(*it).first] = (*it).first;
        res[d[c][it].first] = d[c][it].first;
    }

    for(auto it = 0;it<d[c-a].size();it++)
    {
       //res[d[c-a][it].first] = d[c-a][it].first;
       //res[(*it).first] = (*it).first;
       res[d[c-a][it].first] = d[c-a][it].first;
    }
    long long ress=1;
    for(auto it = res.begin();it!=res.end();it++)
    {
        //cout << res[i] << endl;
        if(it->second!=0)
            ress *= it->second;
    }
    //res.clear();
    if(ress<c)
    {
        //cout << 1111111 << endl;
        return 1;
    }
    else return 0;


}



int main()
{
    init();
    //cout << 11111 << endl;
    int n;
    n = 120000;
    /*
    int m;
    while(cin >> n >> m)
    {
        cout << pending(n,m) << endl;
    }
    */
    long long ans = 0;
    for(int c=1;c<n;c++)
    {
        for(int a=1;a<c/2;a++)
        {
            if(__gcd(a,c)==1)
            {
                if(pending(a,c))
                {
                    ans += 1LL*c;
                    //cout << "a is " << a << endl;
                    //cout << "c is " << c << endl;
                }
            }
        }
    }

    cout << ans << endl;
}

