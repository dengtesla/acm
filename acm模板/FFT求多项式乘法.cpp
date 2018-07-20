#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <bitset>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#define fuck(x) cout<<"["<<x<<"]";
#define FIN freopen("input.txt","r",stdin);
#define FOUT freopen("output.txt","w+",stdout);
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MX = 3e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

const double pi = acos(-1.0);
struct cp {
    double x, y;
    cp() {}
    cp (double x, double y): x(x), y(y) {}
    inline cp operator + (const cp &b) {
        return cp(x + b.x, y + b.y);
    }
    inline cp operator - (const cp &b) {
        return cp(x - b.x, y - b.y);
    }
    inline cp operator * (const cp &b) {
        return cp(x * b.x - y * b.y, x * b.y + y * b.x);
    }
} a[MX], b[MX];

int r[MX];
void fft(cp a[], int opt, int n) {
    for(int i = 0; i < n; i++) {
        if(i < r[i]) swap(a[i], a[r[i]]);
    }
    for(int i = 1; i < n; i <<= 1) {
        cp wn(cos(pi / i), opt * sin(pi / i));
        for(int p = i << 1, j = 0; j < n; j += p) {
            cp w(1, 0);
            for(int k = 0; k < i; k++, w = wn * w) {
                cp x = a[j + k], y = w * a[j + k + i];
                a[j + k] = x + y; a[j + k + i] = x - y;
            }
        }
    }
}
/*多项式a，最高次为n，多项式b，最高次为m
从0到n项的系数
卷积结果等于后来a[].x
复杂度O(nlogn)，最后的最高项为n+m
*/
void solve(cp a[], cp b[], int n, int m) {
    int l = 0, nn, nm = n + m;
    for(nn = 1; nn <= nm; nn <<= 1) l++;
    for(int i = n + 1; i <= nn; i++) a[i] = cp(0, 0);
    for(int i = m + 1; i <= nn; i++) b[i] = cp(0, 0);
    n = nn; m = nm;

    for(int i = 0; i < n; i++) {
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    }
    fft(a, 1, n); fft(b, 1, n);
    for(int i = 0; i <= n; i++) {
        a[i] = a[i] * b[i];
    }
    fft(a, -1, n);
    for(int i = 0; i <= m; i++) {
        a[i].x /= n;
    }
}

int main() {
    int n, m; //FIN;
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= n; i++) scanf("%lf", &a[i].x);
    for(int i = 0; i <= m; i++) scanf("%lf", &b[i].x);
    solve(a, b, n, m);
    for(int i = 0; i <= n + m; i++) {
        printf("%d%c", (int)(a[i].x + 0.5), i == n + m ? '\n' : ' ');
    }
}
