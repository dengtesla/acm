#include<bits/stdc++.h>
using namespace std;
long long dp[50];

int main()
{
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    dp[4]=8;
    for(int i=5;i<=50;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];
    }
    cout << dp[50] << endl;
}
