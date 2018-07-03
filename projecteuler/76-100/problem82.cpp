#include<bits/stdc++.h>
using namespace std;

int a[100][100];
int dp[100][100];

int main()
{
    freopen("problem82.in","r",stdin);
    int n;
    //cin >> n ;
    n = 80;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i][1]);
        for(int j=2;j<=n;j++)
        {
            scanf(",%d",&a[i][j]);
        }
    }
    int ans = 100000000;
    for(int k=1;k<=n;k++)
    {
        memset(dp,0,sizeof(dp));
        dp[k][2] = a[k][1] + a[k][2];
        for(int i=k-1;i>=1;i--)
            dp[i][2] = dp[i+1][2] + a[i][2];
        for(int i=k+1;i<=n;i++)
            dp[i][2] = dp[i-1][2] + a[i][2];
        //for(int i=3;i<=n;i++)
        //    dp[1][i] = dp[1][i-1] + a[1][i];
        for(int i=3;i<n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[j][i] = dp[j][i-1] + a[j][i];
            }

            for(int j=k-1;j>=1;j--)
                dp[j][i] = min(dp[j+1][i] + a[j][i],dp[j][i]);

            for(int j=k+1;j<=n;j++)
                dp[j][i] = min(dp[j-1][i] + a[j][i],dp[j][i]);

            for(int j=1;j<n;j++)
                dp[j+1][i] = min(dp[j][i]+a[j+1][i],dp[j+1][i]);
            for(int j=n;j>=2;j--)
                dp[j][i] = min(dp[j-1][i]+a[j][i],dp[j][i]);
        }

        for(int i=1;i<=n;i++)
            dp[i][n] = dp[i][n-1]+a[i][n];

        for(int i=1;i<=n;i++)
        {
            ans = min(ans,dp[i][n]);
        }
    }

    cout << ans << endl;
}
