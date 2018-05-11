#include<bits/stdc++.h>
using namespace std;

int f[8][220];
int vis[220];
int a[8];

bool flag = 0;


struct edge
{
    bool open;
    int value1;
    int value2;
}e[220][220][8];

void init()
{
    for(int k=0;k<=6;k++)
        for(int i=0;i<=210;i++)
            for(int j=0;j<=210;j++)
            {
                e[i][j][k].open = 0;
                e[i][j][k].value1 = 0;
                e[i][j][k].value2 = 0;
            }
}

void build()
{
    init();
    for(int i=0;i<=5;i++)
    {
        int j1 = 19;
        while(f[a[i]][j1]<10000)
        {
            if(f[a[i]][j1]>=1000)
            {
                int j2 = 19;
                while(f[a[(i+1)%6]][j2]<10000)
                {
                    if(f[a[(i+1)%6]][j2]>=1000)
                    {
                        if(f[a[i]][j1]%100==f[a[(i+1)%6]][j2]/100)
                        {
                            e[j1][j2][a[i]].open = 1;
                            e[j1][j2][a[i]].value1 = f[a[i]][j1];
                            e[j1][j2][a[i]].value2 = f[a[(i+1)%6]][j2];
                        }
                    }
                    j2++;
                }
            }
            j1++;
        }
    }
}

stack <edge> ans;
int res = 0;


int bfs(int st,int ed,int k)
{
    if(k==6)
    {
        if(st==ed)
        {
            //cout << "Found!" << endl;
            while(!ans.empty())
            {
                //cout << ans.top().value1  << " " << ans.top().value2 << endl;
                res += ans.top().value1;
                ans.pop();
            }
            cout << res << endl;
            flag=1;
        }

    }
    else if(flag==0)
    {
        for(int i=1;i<=180;i++)
        {
            if(vis[i]==0&&e[ed][i][a[k]].open)
            {
                vis[i] = 1;
                ans.push(e[ed][i][a[k]]);
                bfs(st,i,k+1);
                if(!ans.empty()) ans.pop();
                vis[i] = 0;
            }
        }
    }
    else return 0;
}


int main()
{
    ///打表存储6个函数的函数值（x从1到200）
    for(int i=1;i<=220;i++)
    {
        f[0][i] = i*(i+1)/2;
        f[1][i] = i*i;
        f[2][i] = i*(3*i-1)/2;
        f[3][i] = i*(2*i-1);
        f[4][i] = i*(5*i-3)/2;
        f[5][i] = i*(3*i-2);
    }
    for(int i=0;i<=5;i++)
        a[i] = i;
    do
    {
        build();///以a[i]的顺序建图
        //int a,b;
        //while(cin >> a >> b) cout << e[a][b].value1 << " " << e[a][b].value2 << endl;
        for(int i=45;i<=140;i++)
        {
            if(flag==0&&f[0][i]<10000&&f[0][i]>=1000)
            {
                memset(vis,0,sizeof(vis));
                bfs(i,i,0);
                if(flag==1) return 0;
            }
            else return 0;
        }
    }while(next_permutation(a+1,a+6)&&flag==0);
    if(flag==0) cout << "Not found" << endl;
}
