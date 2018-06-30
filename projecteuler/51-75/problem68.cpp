#include<bits/stdc++.h>
using namespace std;
int n;
int res[11];
string ress[100];
int ans[11];
int cnt = 0;

bool cmp(const string &a,const string &b)
{
    if(a.size()!=b.size())
        return a.size()<b.size();
    else return a<b;
}


bool pending()
{
    if(ans[1]+ans[6]+ans[7]==ans[2]+ans[7]+ans[8]&&ans[2]+ans[7]+ans[8]==ans[3]+ans[8]+ans[9]&&ans[3]+ans[8]+ans[9]==ans[4]+ans[9]+ans[10]&&ans[4]+ans[9]+ans[10]==ans[5]+ans[10]+ans[6])
    {
        string s[10];
        int ii = 1;
        for(int i=1;i<=5;i++)
        {
            ii = ans[ii]>ans[i]?i:ii;
        }
        for(int i=1;i<=5;i++)
        {
            s[i] = to_string(ans[(i-1)%5+1])+to_string(ans[i+5])+to_string(ans[i%5+6]);
        }
        string ss[10];
        for(int i=1;i<=5;i++)
        {
            ss[1] += s[(ii-2+i)%5+1];
        }
        //sort(ss+1,ss+6);
        //cout << ss[2] << endl;
        if(ss[1].size()==16)
        {
            ress[cnt] = ss[1];
            cnt++;
        }

        //cout << ss[1] << endl;
    }
}




void dfs(int depth)
{
    if(depth==11)
    {
        pending();
    }
    else
    {
        for(int i=1;i<=10;i++)
        {
            if(res[i]==1)
            {
                ans[depth] = i;
                res[i]=0;
                dfs(depth+1);
                res[i]=1;
            }
        }
    }
}


int main()
{
    n = 10;
    for(int i=1;i<=10;i++)
    {
        res[i] = 1;
    }
    dfs(1);
    sort(ress,ress+cnt);
    cout << ress[cnt-1] << endl;
}
