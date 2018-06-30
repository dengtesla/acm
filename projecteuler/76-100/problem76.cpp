#include<bits/stdc++.h>
using namespace std;

int n,cnt;

void solve(int sum,int pre)
{
    if(sum==n)
    {
        cnt++;
        return ;
    }
    for(int i=pre;i<=n-sum;i++)
    {
        solve(sum+i,i);
    }
}



int main()
{
    cnt = 0;
    n = 100;
    solve(0,1);
    cout << cnt-1 << endl;
}
