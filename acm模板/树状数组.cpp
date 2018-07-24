#include<bits/stdc++.h>
using namespace std;

const int maxn = 100007;
int c[maxn];

int lowbit(int n)
{
    return n & (-n);
}

int query(int x)
{
    int res = 0;
    while(x>0)
    {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}

int update(int x,int val)
{
    while(x<maxn)
    {
        c[x] += val;
        x += lowbit(x);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin >> x >> y;
        update(x,y);
    }
    cout << "give me your question!" << endl;
    int l,r;
    while(cin >> l >> r)
    {
        cout << "In [" << l << "," << r << "] ,all the number's sum is: " << query(r)-query(l-1) << endl;
    }
}
