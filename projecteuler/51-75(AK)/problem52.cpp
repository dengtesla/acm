#include<bits/stdc++.h>
using namespace std;
int a1[10];
int a2[10];
int a3[10];
int a4[10];
int a5[10];
int a6[10];

int get_wei(int i)
{
    int t = 0;
    while(i)
    {
        i /= 10;
        t++;
    }
    return t;
}

int istrue(int i)
{
    int n2 = 2*i;
    int n3 = 3*i;
    int n4 = 4*i;
    int n5 = 5*i;
    int n6 = 6*i;
    if(get_wei(2*i)!=get_wei(6*i))
        return 0;
    int t = get_wei(2*i);
    for(int i=0;i<t;i++)
    {
        a2[i] = n2%10;
        n2 /= 10;
    }
    for(int i=0;i<t;i++)
    {
        a3[i] = n3%10;
        n3 /= 10;
    }
    for(int i=0;i<t;i++)
    {
        a4[i] = n4%10;
        n4 /= 10;
    }
    for(int i=0;i<t;i++)
    {
        a5[i] = n5%10;
        n5 /= 10;
    }
    for(int i=0;i<t;i++)
    {
        a6[i] = n6%10;
        n6 /= 10;
    }
    sort(a2,a2+t);
    sort(a3,a3+t);
    sort(a4,a4+t);
    sort(a5,a5+t);
    sort(a6,a6+t);

    int cnt = 0;
    for(int i=0;i<t;i++)
    {
        if(a2[i]==a3[i]&&a3[i]==a4[i]&&a4[i]==a5[i]&&a5[i]==a6[i])
            cnt ++;
    }
    if(cnt==t)
        return 1;
    else return 0;
}


int main()
{
    for(int i=1;i<=1000000;i++)
    {
        if(istrue(i))
            cout << i;
    }
}
