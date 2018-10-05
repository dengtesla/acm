#include<bits/stdc++.h>
using namespace std;
#define ll long long


const ll U[3][3] = {{1,2,2},{-2,-1,-2},{2,2,3}};

const ll A[3][3] = {{1,2,2},{2,1,2},{2,2,3}};

const ll D[3][3] = {{-1,-2,-2},{2,1,2},{2,2,3}};

struct tri
{
    ll i;
    ll j;
    ll k;
    bool tag;
}tt[10000000];

void init()
{
    for(int i=0;i<100000;i++)
    {
        tt[i].i = 0;
        tt[i].j = 0;
        tt[i].k = 0;
        tt[i].tag = 1;
    }
}


tri multi(tri a,const ll (&m)[3][3])
{
    tri w;
    w.i = abs(a.i*m[0][0] + a.j*m[1][0] + a.k*m[2][0]);
    w.j = abs(a.i*m[0][1] + a.j*m[1][1] + a.k*m[2][1]);
    w.k = abs(a.i*m[0][2] + a.j*m[1][2] + a.k*m[2][2]);
    if(w.i>w.j) swap(w.i,w.j);
    return w;
}

bool cmp(const tri &a,const tri &b)
{
    if(a.i>b.i)
        return false;
    else if(a.i==b.i)
    {
        if(a.j>b.j) return false;
        else if(a.j==b.j)
        {
            if(a.k>b.k) return false;
            else if(a.k==b.k) return false;
        }
    }
    return true;
}

bool cmp2(const tri &a,const tri &b)
{
    if(a.i==b.i&&a.j==b.j&&a.k==b.k) return true;
    return false;
}

int cnt = 0;

bool pending(tri tt)
{
    if(tt.i+tt.j>tt.k) return true;
    else return false;
}


void dfs(tri ini)
{
    if(ini.i+ini.j+ini.k>75000000) return;
    tri w1 = multi(ini,U);
    tri w2 = multi(ini,A);
    tri w3 = multi(ini,D);
    ll p1 = w1.i + w1.j + w1.k;
    ll p2 = w2.i + w2.j + w2.k;
    ll p3 = w3.i + w3.j + w3.k;
    if(p1<=75000000) {if(pending(w1)) tt[cnt++] = w1;dfs(w1);}
    if(p2<=75000000) {if(pending(w2)) tt[cnt++] = w2;dfs(w2);}
    if(p3<=75000000) {if(pending(w3)) tt[cnt++] = w3;dfs(w3);}
    return;
}






int main()
{
    init();
    tri ini;
    ini.i = 2;
    ini.j = 2;
    ini.k = 3;
    tt[cnt++] = ini;

    dfs(ini);
/*
    while(1)
    {
        tri w1 = multi(ini,U);
        tri w2 = multi(ini,A);
        tri w3 = multi(ini,D);
        ll p1 = w1.i + w1.j + w1.k;
        ll p2 = w2.i + w2.j + w2.k;
        ll p3 = w3.i + w3.j + w3.k;
        if(p1<=75000000) tt[cnt++] = w1;
        if(p2<=75000000) tt[cnt++] = w2;
        if(p3<=75000000) tt[cnt++] = w3;
        if(p1>75000000&&p2>75000000&&p3>75000000) break;

    }tri w1 = multi(ini,U);
        tri w2 = multi(ini,A);
        tri w3 = multi(ini,D);
        ll p1 = w1.i + w1.j + w1.k;
        ll p2 = w2.i + w2.j + w2.k;
        ll p3 = w3.i + w3.j + w3.k;
        if(p1<=75000000) tt[cnt++] = w1;
        if(p2<=75000000) tt[cnt++] = w2;
        if(p3<=75000000) tt[cnt++] = w3;
        if(p1>75000000&&p2>75000000&&p3>75000000) break;
*/
    sort(tt,tt+cnt,cmp);
    cnt = unique(tt,tt+cnt,cmp2)-tt;
    cout << cnt << endl;
    //for(int i=0;i<cnt;i++)
    //    cout << tt[i].i << " " << tt[i].j <<  " " << tt[i].k << endl;
}
