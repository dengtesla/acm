#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mmax = 25000000;
//ll mmax = 300;
const ll U[3][3] = {{1,2,2},{-2,-1,-2},{2,2,3}};
const ll A[3][3] = {{1,2,2},{2,1,2},{2,2,3}};
const ll D[3][3] = {{-1,-2,-2},{2,1,2},{2,2,3}};
int cnt = 0;
void dfs(ll i,ll j,ll k)
{
    if(i+j+k<=mmax) cnt++;
    else return;
    dfs(i+2*j+2*k,1ll*2*i+j+2*k,1ll*2*i+2*j+3*k);
    dfs(1ll*-1*i+2*j+2*k,1ll*-2*i+j+2*k,1ll*-2*i+2*j+3*k);
    dfs(i-2*j+2*k,1ll*2*i-j+2*k,1ll*2*i-2*j+3*k);
}

struct node
{
    int i,j,k;
};


int main()
{
    //dfs(1,1,1);
    //dfs(1,2,2);
    //dfs(3,3,5);
    //dfs(11,14,18);

    queue <node> q;
    node a;
    a.i = 1;
    a.j = 1;
    a.k = 1;
    q.push(a);
    while(!q.empty())
    {

        node w = q.front();
        if(w.i+w.j+w.k<=mmax)
        {
            cnt++;
            //cout << w.i << " " << w.j << " " << w.k << endl;
        }
        //
        node w1;
        w1.i = w.i+2*w.j+2*w.k;
        w1.j = 2*w.i+w.j+2*w.k;
        w1.k = 2*w.i+2*w.j+3*w.k;
        node w2;
        w2.i = -1*w.i+2*w.j+2*w.k;
        w2.j = -2*w.i+w.j+2*w.k;
        w2.k = -2*w.i+2*w.j+3*w.k;
        node w3;
        w3.i = w.i-2*w.j+2*w.k;
        w3.j = 2*w.i-w.j+2*w.k;
        w3.k = 2*w.i-2*w.j+3*w.k;
        if(w1.i+w1.j+w1.k<=mmax)
        {
            //if(w1.i<=w1.j&&w1.j<w1.k)cnt++;
            q.push(w1);
        }
        if(w2.i+w2.j+w2.k<=mmax&&w.i!=w.j)
        {
            //if(w2.i<=w2.j&&w2.j<w2.k)cnt++;
            q.push(w2);
        }
        if(w3.i+w3.j+w3.k<=mmax)
        {
            //if(w3.i<=w3.j&&w3.j<w3.k)cnt++;
            q.push(w3);
        }
        q.pop();
    }

    a.i = 1;
    a.j = 2;
    a.k = 2;
    q.push(a);
    while(!q.empty())
    {
        node w = q.front();
        if(w.i+w.j+w.k<=mmax)
        {
            cnt++;
            //cout << w.i << " " << w.j << " " << w.k << endl;
        }
        //cout << w.i << " " << w.j << " " << w.k << endl;
        node w1;
        w1.i = w.i+2*w.j+2*w.k;
        w1.j = 2*w.i+w.j+2*w.k;
        w1.k = 2*w.i+2*w.j+3*w.k;
        node w2;
        w2.i = -1*w.i+2*w.j+2*w.k;
        w2.j = -2*w.i+w.j+2*w.k;
        w2.k = -2*w.i+2*w.j+3*w.k;
        node w3;
        w3.i = w.i-2*w.j+2*w.k;
        w3.j = 2*w.i-w.j+2*w.k;
        w3.k = 2*w.i-2*w.j+3*w.k;
        if(w1.i+w1.j+w1.k<=mmax)
        {
            //if(w1.i<=w1.j&&w1.j<w1.k)cnt++;
            q.push(w1);
        }
        if(w2.i+w2.j+w2.k<=mmax&&w.i!=w.j)
        {
            //if(w2.i<=w2.j&&w2.j<w2.k)cnt++;
            q.push(w2);
        }
        if(w3.i+w3.j+w3.k<=mmax)
        {
            //if(w3.i<=w3.j&&w3.j<w3.k)cnt++;
            q.push(w3);
        }
        q.pop();
    }
/*
    a.i = 3;
    a.j = 3;
    a.k = 5;
    q.push(a);
    while(!q.empty())
    {
        node w = q.front();
        if(w.i+w.j+w.k<=mmax)
        {
            cnt++;
            cout << w.i << " " << w.j << " " << w.k << endl;
        }
        //cout << w.i << " " << w.j << " " << w.k << endl;
        node w1;
        w1.i = w.i+2*w.j+2*w.k;
        w1.j = 2*w.i+w.j+2*w.k;
        w1.k = 2*w.i+2*w.j+3*w.k;
        node w2;
        w2.i = -1*w.i+2*w.j+2*w.k;
        w2.j = -2*w.i+w.j+2*w.k;
        w2.k = -2*w.i+2*w.j+3*w.k;
        node w3;
        w3.i = w.i-2*w.j+2*w.k;
        w3.j = 2*w.i-w.j+2*w.k;
        w3.k = 2*w.i-2*w.j+3*w.k;
        if(w1.i+w1.j+w1.k<=mmax)
        {
            //if(w1.i<=w1.j&&w1.j<w1.k)cnt++;
            q.push(w1);
        }
        if(w2.i+w2.j+w2.k<=mmax&&w.i!=w.j)
        {
            //if(w2.i<=w2.j&&w2.j<w2.k)cnt++;
            q.push(w2);
        }
        if(w3.i+w3.j+w3.k<=mmax)
        {
            //if(w3.i<=w3.j&&w3.j<w3.k)cnt++;
            q.push(w3);
        }
        q.pop();
    }

    a.i = 11;
    a.j = 14;
    a.k = 18;
    q.push(a);
    while(!q.empty())
    {
        node w = q.front();
        if(w.i+w.j+w.k<=mmax)
        {
            cnt++;
            cout << w.i << " " << w.j << " " << w.k << endl;
        }
        //cout << w.i << " " << w.j << " " << w.k << endl;
        node w1;
        w1.i = w.i+2*w.j+2*w.k;
        w1.j = 2*w.i+w.j+2*w.k;
        w1.k = 2*w.i+2*w.j+3*w.k;
        node w2;
        w2.i = -1*w.i+2*w.j+2*w.k;
        w2.j = -2*w.i+w.j+2*w.k;
        w2.k = -2*w.i+2*w.j+3*w.k;
        node w3;
        w3.i = w.i-2*w.j+2*w.k;
        w3.j = 2*w.i-w.j+2*w.k;
        w3.k = 2*w.i-2*w.j+3*w.k;
        if(w1.i+w1.j+w1.k<=mmax)
        {
            //if(w1.i<=w1.j&&w1.j<w1.k)cnt++;
            q.push(w1);
        }
        if(w2.i+w2.j+w2.k<=mmax&&w.i!=w.j)
        {
            //if(w2.i<=w2.j&&w2.j<w2.k)cnt++;
            q.push(w2);
        }
        if(w3.i+w3.j+w3.k<=mmax)
        {
            //if(w3.i<=w3.j&&w3.j<w3.k)cnt++;
            q.push(w3);
        }
        q.pop();
    }
*/
    cout << cnt << endl;
}

