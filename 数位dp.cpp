#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

//thanks to pyf ...

#define N 10000

int Map[N][N];
int dp[N][N];
int n;
void top_to_bottom()
{
		memset(dp,0,sizeof(dp));
		//正着从上到下 对i层每个j的最大值是dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+Map[i][j];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(j!=1)
					dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
				dp[i][j] = max(dp[i][j],dp[i-1][j]);
				dp[i][j] += Map[i][j];	
			}	
		} 
		int ans = -1;
		for(int i=1;i<=n;i++)//在底层找答案
			ans = max(ans,dp[n][i]);
		cout << ans << endl; 
}
void bottom_to_top()
{
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++) // 底层赋值
		dp[n][i] = Map[n][i]; 
	for(int i=n-1;i>=1;i--)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + Map[i][j];
		}
	}
	cout << dp[1][1] << endl;
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				cin >> Map[i][j];	
			}	
		}	
		top_to_bottom();
		bottom_to_top();
	}	
}

