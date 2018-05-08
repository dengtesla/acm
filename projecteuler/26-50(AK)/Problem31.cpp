#include<bits/stdc++.h>
using namespace std;
int dp[220];
int main()
{
    //int dp[220];
    //memset(dp,0,sizeof(dp));
    dp[0]=1;
    int a[8] = {1,2,5,10,20,50,100,200};
    for(int i = 0;i < 8;i++)
        for(int j = a[i];j<=200;j++){
            dp[j] += dp[j-a[i]];
            //cout << "dp[" << j << "] += dp[" << j-a[i] << "]" << endl;
        }
    cout << dp[200] << endl;
}
