#include<bits/stdc++.h>
using namespace std;
#define N 64000000
vector <pair<long long,int>> d[64000014];

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


int main()
{
    init();cout << 111111 << endl;
    int t;
    while(cin >> t)
    for(int i=0;i<d[t].size();i++)
    {
        cout << "factor " << d[t][i].first << " is " << d[t][i].second << endl;
    }
}
