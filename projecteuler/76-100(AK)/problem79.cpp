#include<bits/stdc++.h>
using namespace std;

int way[10][10];
bool is[10];

bool pending()
{
    int cnt = 0;
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(way[i][j]==1) cnt++;
        }
    }
    if(cnt==0) return 1;
    else return 0;
}

int cc;
int main()
{
    freopen("problem79.in","r",stdin);
    for(int i=1;i<=50;i++)
    {
        int w;
        cin >> w;
        int a = w/100;
        int b = (w-a*100)/10;
        int c = w%10;
        way[a][b] = 1;
        way[b][c] = 1;
    }

    for(int i=0;i<=9;i++)
    {
        int cnt1 = 0;
        int cnt2 = 0;
        for(int j=0;j<=9;j++)
        {
            if(way[i][j]==1) cnt1++;
            if(way[j][i]==1) cnt2++;
        }
        if((cnt1+cnt2)!=0) is[i] = 1;
        else is[i] = 0;
        if(cnt1==0&&cnt2!=0) cc = i;
    }

    for(int i=0;i<=9;i++)
    {
        if(is[i]==0) continue;
        int cnt = 0;
        for(int j=0;j<=9;j++)
        {
            if(way[j][i]==1) cnt++;
        }
        if(cnt==0)
        {
            cout << i;
            for(int k=0;k<=9;k++)
                way[i][k]=0;
            if(pending())
            {
                cout << cc << endl;
                break;
            }
            is[i]=0;
            i = 0;

        }
    }
}
