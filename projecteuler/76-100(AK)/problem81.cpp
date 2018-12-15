#include<bits/stdc++.h>
using namespace std;
int a[100][100];

int dp[100][100];



int main()
{
    freopen("problem81.in","r",stdin);
    for(int i=1;i<=80;i++)
    {
        scanf("%d",&a[i][1]);
        for(int j=2;j<=80;j++)
        {
            scanf(",%d",&a[i][j]);
        }
    }



    dp[1][1] = a[1][1];

    for(int i=2;i<=80;i++)
    {
        dp[i][1] = dp[i-1][1] + a[i][1];
        dp[1][i] = dp[1][i-1] + a[1][i];
    }
    for(int i=2;i<=80;i++)
    {
        for(int j=2;j<=80;j++)
        {
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + a[i][j] ;
        }
    }


    cout << dp[80][80] << endl;
    //cout << 11111111 << endl;
}
