#include<bits/stdc++.h>
using namespace std;
long long f[1000000];
const long long mod = 1000000;

int main()
{
    f[1] = 1;
    f[2] = 2;
    f[3] = 3;
    f[0] = 1;
    for(int i=4;i<=100000;i++)
    {
        for(int k=1;k*(3*k-1)<=2*i;k++)
        {
            if(i-k*(3*k-1)/2>=0)
            {
                f[i] += ((k%2==0)?(-1):(1))*f[i-k*(3*k-1)/2];
                f[k] %= mod;
            }
            if(i-k*(3*k+1)/2>=0)
            {
                f[i] += ((k%2==0)?(-1):(1))*f[i-k*(3*k+1)/2];
                f[i] %= mod;
            }
        }
        if(f[i] % mod == 0) cout << i << endl;
    }
}
