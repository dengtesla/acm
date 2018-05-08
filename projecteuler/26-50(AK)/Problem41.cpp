#include<bits/stdc++.h>
using namespace std;
#define MAX 9999999

//因为1—9的排列和1-8的排列一定都是3的倍数，所以最大只有可能是1-7的排列




bool isprime[MAX+10];
int prime[MAX+10];
int tot=1;

int digit[10];

void get_prime(int n)
{
    memset(isprime,1,sizeof(isprime));
    isprime[1] = 0;
    for(int i=2;i<=n;i++)
    {
        if(isprime[i]) prime[tot++] = i;
        for(int j=1;prime[j]*i<=n&&j<=tot;j++)
        {
            isprime[prime[j]*i] = 0;
            if(i%prime[j]==0) break;
        }
    }
}

int pending(int a)
{
    memset(digit,0,sizeof(digit));
    int i = 0;
    while(a)
    {
        digit[i] = a%10;
        a /= 10;
        i++;
    }
    //cout << i << endl;
    return i;
}

int main()
{
    bool flag = 0;
    get_prime(7654321);//while(cin >> test) cout << isprime[test] << endl;
    stack <int>stk;
    int ans = 0;
    for(int i=1;prime[i]!=0;i++)
    {
        int a = prime[i];
        int b = 10;
        while(b--)
        {
            stk.push(b);
        }
        int w = pending(prime[i]);
        sort(digit,digit+w);
        for(int j=0;j<w;j++)
        {
            if(digit[j]!=j+1)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        ans = prime[i];
        else flag = 0;
    }
    cout << ans << endl;

}
