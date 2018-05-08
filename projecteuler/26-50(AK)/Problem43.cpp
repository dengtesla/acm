#include<bits/stdc++.h>
using namespace std;

long long getsum(int a[])
{
    int t=0;
    long long res=0;
    while(t<10)
    {
        res = res * 10 + a[t];
        t++;
    }
    return res;
}




int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int prime[7] = {2,3,5,7,11,13,17};
    bool flag = 0;
    long long ans = 0;
    while(next_permutation(a,a+10))
    {
        for(int i=2;i<=8;i++)
        {
            if((a[i-1]*100+a[i]*10+a[i+1])%prime[i-2]==0) ;
            else
            {
                flag = 1;
                break;
            }
        }
        if(flag) flag=0;
        else
        {
            ans += getsum(a);
        }
    }
    cout << ans << endl;
}
