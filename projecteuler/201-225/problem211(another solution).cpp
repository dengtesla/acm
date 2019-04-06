#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
#define N 64000000
vector <pair<int,char> > d[N+110];

void init()
{
    d[1].push_back({1,1});
    for(int i=2;i<=N;i++)
    {
        if(d[i].empty())
        {
            for(int j=i;j<=N;j+=i)
                d[j].push_back({i,1});

            long long w=(long long)i*(long long)i;
            while(w<=N)
            {
                for(int j=w;j<=N;j+=w)
                    d[j][d[j].size()-1].second++;
                w*=i;
            }

        }
    }
}

long long poww(long long a,int b)
{
    long long ans = 1;
    long long base = a;
    while(b)
    {
        if(b&1) ans *= base;
        base *= base;
        b>>=1;
    }
    return ans;
}


long long ans = 1;
void get_ans()
{

    for(int t=2;t<N;t++)
    {
        long long *res = new long long;
        *res = 1;
        //long long res = 1;
        for(int i=0;i<d[t].size();i++)
        {
            long long *p = new long long;
            *p = d[t][i].first;
            int *time = new int;
            *time = d[t][i].second;
            //long long p = d[t][i].first;
            //int time = d[t][i].second;
            //long long rr = poww(p,time+1)-1;
            long long *rr = new long long;
            *rr = poww(*p,*time+1)-1;
            if((*time)&1)
            {
                *rr /= (*p)*(*p)-1;
                *rr *= poww(*p,*time+1)+1;
            }
            else
            {
                *rr /= *p-1;
                long long *ll = new long long;
                *ll = (poww(*p,*time+1)+1)/(*p+1);
                *rr *= *ll;
                delete ll;
            }
            *res *= *rr;

            delete p;
            delete time;
            delete rr;
        }
        if(t<=20) cout << t << " " << *res << endl;
        long long *k = new long long;
        *k = (long long)(sqrt(*res)+0.5);
        if((*k)*(*k)==(*res))
        {
            ans += t;
        }
        delete k;
        delete res;
    }
}



int main()
{
    init();cout << 111111 << endl;
    get_ans();
    cout << ans << endl;
}
