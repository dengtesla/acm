#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tmax=0,t=0;
    int ans=0;
    long long k=1;
    for(int i=1;i<=1000000;i++)
    {
        t=0;
        k=i;
        while(k!=1)
        {
            if(k%2==0)
            {
                k=k/2;
                t++;
            }
            else
            {
                k=3*k+1;
                t++;
            }
        }
        if(t>=tmax)
        {
            ans = i;
            tmax = t;
            //cout << tmax << endl;
        }
    }
    cout << ans << endl;
}
