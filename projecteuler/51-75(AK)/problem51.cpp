#include<bits/stdc++.h>
using namespace std;
#define INF 1000000
bool isprime[1005010];
int prime[1005000];
//bool searched[1000010];
int aa[3];
//int shuwei[10];

int poww(int a,int b)
{
    int i = 1;
    while(b--)
    {
        i *= a;
    }
    return i;
}

void init()
{
    memset(isprime,1,sizeof(isprime));
    isprime[1] = false;
    int tot = 1;
    for(int i=2;i<=1001000;i++)
    {
        if(isprime[i]) prime[tot++] = i;
        for(int j=1;j<=tot&&prime[j]*i<=1001000;j++)
        {
            isprime[prime[j]*i] = false;
            if(i%prime[j]==0) break;
        }
    }
}

int zero(int i)
{
    int cnt = 0;
    int j = 0;
    while(i!=0)
    {
        if(i%10==0)
        {
            aa[cnt] = j;
            cnt++;
        }
        j++;
        i /= 10;
        if(cnt == 3) return 3;
    }
    return 0;
}

int one(int i)
{
    int cnt = 0;
    int j = 0;
    while(i!=0)
    {
        if(i%10==1)
        {
            aa[cnt] = j;
            cnt++;
        }
        j++;
        i /= 10;
        if(cnt == 3) return 3;
    }
    return 0;
}

int two(int i)
{
    int cnt = 0;
    int j = 0;
    while(i!=0)
    {
        if(i%10==2)
        {
            aa[cnt] = j;
            cnt++;
        }
        j++;
        i /= 10;
        if(cnt == 3) return 3;
    }
    return 0;
}

int prime_time(int i)
{
    int a[10];
    int cot = 0;
    int cnt = 0;
    while(i!=0)
    {
        a[cot] = i % 10;
        i/=10;
        cot ++;
    }
    cot--;
    for(int i = 0;i<=9;i++)
    {
        int res = 0;
        for(int j = 0;j<=cot;j++)
        {
            if(j==aa[0])
                res += poww(10,aa[0])*i;
            else if(j==aa[1])
                res += poww(10,aa[1])*i;
            else if(j==aa[2])
                res += poww(10,aa[2])*i;
            else
                res += poww(10,j)*a[j];


        }
        if(aa[2]==cot&&i==0&&isprime[res]) cnt--;
        if(isprime[res]) cnt++;

    }
    return cnt;
}

int main()
{
    init();
    aa[0] = 1;
    aa[1] = 3;
    aa[2] = 5;
    //int i;
    //while(cin >> i) cout << isprime[i] << endl;//cout << "cccccc" << endl;
    //cout << prime_time(121313) << endl;
    for(int i=100;prime[i]<=1000000;i++)
    {
        //if(prime[i]==121313) cout << "yyyyyy" << endl;
        if(zero(prime[i])==3)
            if(prime_time(prime[i])==8)
            cout << prime[i] << endl;
        if(one(prime[i])==3)
        {
            //if(prime[i]==121313) cout << "yyyyyy" << endl;
            if(prime_time(prime[i])==8)
                cout << prime[i] << endl;
        }
        if(two(prime[i])==3)
            if(prime_time(prime[i])==8)
            cout << prime[i] << endl;
    }
}
