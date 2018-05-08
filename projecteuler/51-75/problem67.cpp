#include<bits/stdc++.h>
using namespace std;


int main()
{
    freopen("problem67.in","r",stdin);
    int Map[200][200];
    int dp[200][200];
    memset(Map,0,sizeof(Map));
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin >> Map[i][j];
        }
    }
    for(int i=100;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + Map[i][j];
        }
    }
    cout << dp[1][1] << endl;
}
