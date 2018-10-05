#include<bits/stdc++.h>
using namespace std;


//��С��listsize������ȫ������С˳������prime[]�����prime[1]=2��
//ͬʱ���Ե���isprime[]����O(1)��ѯĳ�����ǲ�������������isprime(8)=0��˵��8����������
//���Ӷ�O(n)
#define MAXIMUM 26
int prime[1000000];
bool isprime[1000000];

void get_prime(int listsize)
{
    int primesize=1;
    memset(isprime,1,sizeof(isprime));
    isprime[1] = false;
    for(int i=2;i<=listsize;i++)
    {
        if(isprime[i]) prime[primesize++]=i;
        for(int j=1;i*prime[j]<=listsize&&j<=primesize;j++)
        {
            isprime[i*prime[j]] = false;
            if(i%prime[j]==0) break;
        }
    }
}

//����a�������ֽ⣬���������Ӵ�С�������ڽṹ��p[].value�У���������p[].time��
struct p
{
    int value;
    int time;
}p[MAXIMUM];

void prime_factorization(long long n)
{
    memset(p,0,sizeof(p));
    long long psize=0;
    long long a = n;
    for(int t = 1;1LL*prime[t]*prime[t]<=n;t++)
    {
        if(a%prime[t]==0) p[++psize].value = prime[t];
        while(a%prime[t]==0)
        {
            p[psize].time += 1;
            a = a / prime[t];
        }
        if(a<=90000)
        if(isprime[a])
        {
            p[++psize].value = a;
            p[psize].time += 1;
            a = 1;
            break;
        }
        if(a==1) break;
    }
    if(a!=1)
    {
        p[++psize].value = a;
        p[psize].time = 1;
    }
}


//debug��
int main()
{
    int j;
    get_prime(800000);

    while(cin >> j)
    {
        if(isprime[j]) cout<<j<<" is a prime"<<endl;
        else cout<<j<<" is not a prime"<<endl;
    }
    /*
    for(int i = 2;i<=10;i++)
    {
        prime_factorization(i);
        j = 1;
        while(p[j].value!=0)
        {
            cout << "����"  << p[j].value << "����Ϊ:" << p[j].time << " " ;
            j++;
        }
        cout << endl;
    }
    */
}
