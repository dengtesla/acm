#include<bits/stdc++.h>
using namespace std;
const long double di = log(10);
#define ll long long
const ll mod = 1000000000;

int sss[11];
bool check(int n){
    long double log_val = 1.0*(1.0*n*log((1.0+sqrt(5))/2.0) - log(sqrt(5)))/di;
    long double res = pow(10.0,log_val-(ll)log_val);
    res *= 1e9;
    //printf("%.15Lf\n",res);
    string s = to_string(res);
    //cout << s << endl;
    for(int i=0;i<=9;i++){
        sss[i] = s[i]-'0';
    }
    sort(sss,sss+9);
    bool flag = 1;
    for(int i=0;i<9;i++){
        if(sss[i]!=i+1){flag = 0;break;}
    }
    return flag;
}




int val[11];

int main()
{
    int n;
    //while(cin >> n) cout << check(n) << endl;
    ll fa = 1;
    ll fb = 1;
    int cnt = 3;
    while(1){
        if(cnt%1000000==0) cout << cnt << endl;
        ll fc = fa + fb;
        fc %= mod;
        if(cnt>=20){
            ll w = fc;
            int i=0;
            memset(val,0,sizeof val);
            while(w){
                val[i++] = w % 10;
                w /=10;
            }
            sort(val,val+9);
            bool flag = 1;
            for(int j=0;j<9;j++){
                if(val[j]!=j+1){flag=0;break;}
            }
            if(flag==1){
                if(check(cnt)){
                    cout << cnt << endl;
                    return 0;
                }
            }
        }
        fa = fb;
        fb = fc;
        cnt++;
    }
}
