#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_prime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return n != 1;
}


int path[5];

bool ok(int x, const vector<int>& p, int dep)
{
    for (int i = 0; i < dep; i++)
    {
        int y = path[i];
        string a = to_string(x), b = to_string(y);
        string aa = a + b, bb = b + a;
        ll t1 = stoll(aa), t2 = stoll(bb);
        if (!is_prime(t1)) return  0;
        if (!is_prime(t2)) return  0;
    }
    return 1;
}

void dfs(int id, const vector<int>& p, int dep)
{
    if (dep == 5)
    {
        cerr << "find an answer!" << endl;
        int ans = 0;
        for (int i = 0; i < 5; i++) cout << path[i] << " ", ans += path[i];
        cout << "\n" << ans << endl;
        int x;
        cin >> x;
        return;
    }
    for (int i = id + 1; i < p.size(); i++)
        if (ok(p[i], p, dep)) path[dep] = p[i], dfs(i, p, dep + 1);

}

int main()
{
    vector<int> p;
    int n=10000;
    //cin >> n;
    for (int i = 3; i <= n; i++)
        if (is_prime(i)) p.push_back(i);
    ll ans = 0x3f3f3f3f;
    int m = p.size();
    dfs(0, p, 0);
    cout << ans << endl;
    return 0;
}
