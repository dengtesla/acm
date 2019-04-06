#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define ll long long

int dp[10000+10][10000+10];

int l[1000];
int r[1000];
int cnt = 0;

int dfs(int a,int b){
    if(dp[a][b]!=0) return dp[a][b];
    ll ans = 0;
    for(int i=0;i<cnt;i++){
        if(a>=l[i]&&b>=r[i]){
            ans += dfs(a-l[i],b-r[i]);
            ans %= mod;
        }
        if(l[i]*l[i]+r[i]*r[i]>a*a+b*b) break;
    }
    return dp[a][b] = ans;
}

int fb[50];

int main(){
    //freopen("ttest.txt","w",stdout);
    dp[0][0] = 1;
    fb[1] = 1;
    fb[2] = 2;
    for(int i=3;i<=20;i++){
        fb[i] = fb[i-1] + fb[i-2];
    }
    for(int i=1;i<=20;i++){
        for(int a=0;a<=10000&&a<=fb[i];a++){
            int b_2 = fb[i]*fb[i] - a*a;
            int b = (int)sqrt(b_2);
            if(b*b==b_2&&b<=10000){
                l[cnt] = a;
                r[cnt] = b;
                cnt++;
            }
        }
    }
    cout << dfs(10000,10000) << endl;
}

