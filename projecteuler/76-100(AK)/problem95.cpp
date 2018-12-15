#include<bits/stdc++.h>
using namespace std;
int vis[1000000+100];
int max_len = 0;
int min_val = 10000000;

int get_len(int a)
{
    int ans = 1;
    for(int i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
        {
            ans += i;
            if(a/i!=i) ans += a/i;
        }
    }
    return ans;
}
map<int,bool> m;

int main()
{
    for(int i=10;i<=1000000;i++)
    {//cout << i << endl;
        if(i%10000==0) cout << i << endl;
        //if(vis[i]) continue;
        //vis[i] = 1;
        bool flag = 1;
        m.clear();
        m[i] = 1;
        int w = get_len(i);
        if(w==i) continue;
        m[w] = 1;
        int cnt = 1;
        int ans = min(i,w);
        while(w!=i)
        {
            cnt++;
            w = get_len(w);
            if(m[w]==1&&w!=i)
            {
                flag = 0;
                break;
            }
            m[w] = 1;
            ans = min(w,ans);
            if(w==1)
            {
                flag = 0;
                break;
            }
            if(w>=1000000)
            {
                flag = 0;
                break;
            }
            //else vis[w] = 1;
        }
        if(flag==0) continue;
        if(cnt>max_len)
        {
            max_len = cnt;
            min_val = ans;
        }
        if(cnt==max_len)
            min_val = min(min_val,ans);
    }
    cout << min_val << endl;
}
