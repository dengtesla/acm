#include<bits/stdc++.h>
using namespace std;

string s[41];
int m[40][40];

struct rec {int x,y,z;}edge[500010];
int fa[100010],n,mm,ans;
bool operator <(rec a,rec b)
{
    return a.z<b.z;
}
int get(int x)
{
    if(x==fa[x]) return x;
    return fa[x] = get(fa[x]);
}





int main()
{
    freopen("problem107.in","r",stdin);
    for(int i=0;i<40;i++) cin >> s[i];
    for(int i=0;i<40;i++)
    {
        int cnt = 0;
        int num = 0;
        for(int j=0;j<s[i].size();j++)
        {
            if(s[i][j]=='-') continue;
            else if(s[i][j]==',')
            {
                m[i][cnt] = num;
                cnt++;
                num = 0;
            }
            else
            {
                num *= 10;
                num += s[i][j]-'0';
            }
            if(j==s[i].size()-1) m[i][cnt] = num;
        }
    }
    int mm = 0;
    int fin = 0;
    for(int i=0;i<40;i++)
    {
        for(int j=0;j<40;j++)
        {
            if(m[i][j]!=0)
            {
                edge[++mm].x = i+1;
                edge[mm].y = j+1;
                edge[mm].z = m[i][j];
                fin += m[i][j];
            }
        }
    }
    sort(edge+1,edge+mm+1);
    for(int i=1;i<=40;i++) fa[i] = i;
    int ans = 0;
    for(int i=1;i<=mm;i++)
    {
        int x = get(edge[i].x);
        int y = get(edge[i].y);
        if(x==y) continue;
        fa[x] = y;
        ans += edge[i].z;
    }
    cout << fin/2 - ans << endl;
}
