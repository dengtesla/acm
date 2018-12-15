#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long N=1;
    long long K=1;
    while((N+1)/2<=1000000000000||K%2==0)
    {
        long long nn = 3*N + 4*K;
        long long kk = 2*N + 3*K;
        N = nn;
        K = kk;
    }
    cout << (K+1)/2 << endl;
}
