#include<bits/stdc++.h>
using namespace std;

bool is_p(int n[])///判断是不是回文数
{
    int length = 50;
    while(n[length]==0)
    {
        length--;
    }
    if(length==0) return 1;
    for(int i=0;i<length-i;i++)
    {
        if(n[i]!=n[length-i]) return 0;
    }
    return 1;
}

void change_add(int n[])///颠倒相加
{
    int length = 50;
    while(n[length]==0)
    {
        length--;
    }
    int a[100];
    memset(a,0,sizeof(a));
    for(int i=0;i<=length;i++)
    {
        a[length-i] = n[i];
    }
    for(int i=0;i<=length;i++)
    {
        n[i] += a[i];
        if(n[i]>=10)
        {
            n[i] %= 10;
            n[i+1] += 1;
        }
    }
}

bool is_l(int n)///判断是不是Lychrel numbers
{
    int nn[100];
    memset(nn,0,sizeof(nn));
    int i=0;
    while(n)
    {
        nn[i] = n % 10;
        i++;
        n /= 10;
    }
    int time = 50;
    while(time)
    {
        change_add(nn);
        if(is_p(nn)) return 0;
        time--;
    }
    return 1;
}

int main()
{
    int ans = 0;
    for(int i=1;i<=10000;i++)
    {
        if(is_l(i)) ans+=1;
    }
    cout << ans << endl;
}
