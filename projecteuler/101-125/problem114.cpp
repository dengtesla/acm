#include<bits/stdc++.h>
using namespace std;
long long dp[70][3];



int main()
{
    int c=50;
    //while(cin >> c)
    {
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    dp[1][0]=1;
    dp[2][0]=1;
    dp[3][0]=1;
    dp[0][1]=0;
    dp[1][1]=0;
    dp[2][1]=0;
    dp[3][1]=1;

    for(int i=4;i<=c;i++)
    {
        //dp[i][0]=dp[i-1][0]+dp[i-1][1];
        for(int j=0;j<=i-3;j++)
            dp[i][1]+=dp[j][0];
            //if(i==4) cout << "$$$$$$" << dp[i][1];
        dp[i][0]+=dp[i-1][0];
        if(i==5){
        //cout << "********" << dp[i][0] << endl;
        //cout << "&&&&&&" << dp[i-1][1] << endl;
        }
        dp[i][0]+=dp[i-1][1];
    }
    cout << dp[c][1]+dp[c][0] << endl;
    //cout << "dp[" << c << "][1]= " << dp[c][1] << endl;
    //cout << "dp[" << c << "][0]= " << dp[c][0] << endl;
    }
}
