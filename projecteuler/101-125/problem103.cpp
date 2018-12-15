#include<bits/stdc++.h>
using namespace std;
int a[8];
int choice[8];
bool flag = 0;
bool fin = 0;

bool check()
{
    int cnt1=0,cnt2=0;
    int sum1=0,sum2=0;
    for(int i=1;i<=7;i++)
    {
        if(choice[i]==1)
        {
            cnt1++;
            sum1 += a[i];
        }
        else if(choice[i]==2)
        {
            cnt2++;
            sum2 += a[i];
        }
    }
    if(cnt1==0||cnt2==0) return 1;
    if(cnt1>cnt2&&sum1<=sum2)
    {
        return 0;
    }
    if(sum1==sum2) return 0;
    return 1;
}

void ddfs(int pla,int mmax)
{
    if(flag==1) return;
    if(pla>mmax)
    {
        if(!check()) flag = 1;
    }
    else
    {
        for(int i=0;i<=2;i++)
        {
            choice[pla] = i;
            ddfs(pla+1,mmax);
        }
    }
}

void dfs(int pla,int mmax,int now_max)
{
    if(fin == 1) return;
    if(pla>mmax)
    {
        ddfs(1,mmax);
        if(flag == 1)
        {
            flag=0;
        }
        else
        {
            for(int i=1;i<=7;i++)
                cout << a[i];
            cout << endl;
            fin = 1;
        }
    }
    else
    {
        for(int i=now_max;i<=50;i++)
        {
            a[pla] = i;
            dfs(pla+1,mmax,i+1);
        }
    }
}



int main()
{
    a[1] = 20;
    dfs(2,7,21);
}
