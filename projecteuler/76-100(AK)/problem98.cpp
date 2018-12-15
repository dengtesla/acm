#include<bits/stdc++.h>
using namespace std;

string ans[3000];
string ans2[3000];
long long res = 0;
map<char,int> m;

bool isq(long long w)
{
    long long k = sqrt(w);
    if(k*k==w) return 1;
    return 0;
}


void dfs(string w,int len,string a,string b,int now)
{
    if(now==len)
    {
        /*
        for(int i=0;i<len;i++)
        {
            cout << w[i] << " : " << m[w[i]] << " ";
        }
        cout << endl;
        */
        long long res1 = 0;
        long long res2 = 0;
        if(m[a[0]]==0) return;
        if(m[b[0]]==0) return;
        for(int i=0;i<a.size();i++)
        {
            res1 *= 10;
            res1 += m[a[i]];
        }
        for(int i=0;i<b.size();i++)
        {
            res2 *= 10;
            res2 += m[b[i]];
        }
        if(isq(res1)&&isq(res2))
        {
            //if(max(res1,res2)==80514729) cout << a << " " << b << endl;
            res = max(res,max(res1,res2));
        }
    }
    else
    {
        for(int i=0;i<=9;i++)
        {
            bool flag = 0;
            for(int j=0;j<now;j++)
            {
                if(m[w[j]]==i)
                {
                    flag = 1;
                }
            }
            if(flag==0)
            {
                m[w[now]] = i;
                dfs(w,len,a,b,now+1);
            }
        }
    }
}

void gogogo(string a,string b)
{
    string w = a;
    sort(w.begin(),w.end());
    int len = unique(w.begin(),w.end())-w.begin();
    m.clear();
    dfs(w,len,a,b,0);

}


int main()
{
    freopen("problem98.in","r",stdin);
    string w;
    cin >> w;
    int cnt = -1;
    int sta = 0;
    int cnt2 = 0;
    for(int i=0;i<w.size();i++)
    {
        if(sta==1&&w[i]!='"')
        {
            //cout << w[i] << endl;
            ans[cnt].push_back(w[i]);
            ans2[cnt].push_back(w[i]);
            //ans[cnt][cnt2++] = w[i];
        }
        if(w[i]=='"')
        {
            if(sta==0) cnt++;
            sta = 1 - sta;
            continue;
        }
        if(w[i]==',') continue;
    }
    //cout << ans[cnt] << endl;
    for(int i=0;i<=cnt;i++)
    {
        sort(ans2[i].begin(),ans2[i].end());
    }
    for(int i=0;i<=cnt;i++)
    {
        for(int j=i+1;j<=cnt;j++)
        {
            if(ans2[i]==ans2[j])
            {
                //cout << ans[i] << endl;
                gogogo(ans[i],ans[j]);
            }
        }
    }
    cout << res << endl;
}
