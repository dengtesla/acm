#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n = 1e18;
    long long z = 0;
    for(int e = log(n-2)/log(2);e > 1;e--)
    {
        double e1 = 1.0/e;
        long long a = pow(n,e1);
        while(pow(a,e) + a > n) a--;
        z += a-1;
        for(int i = 1;(a = pow(n,e1/=e)-1)>0;i++) z += a*(2*i + 1);
    }
    cout << z << endl;
}
