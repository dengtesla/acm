#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 10000

int main()
{
    int n,l;
    int a[N];
    double ans;
    scanf("%d %d",&n,&l);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    ans = max(a[0]-0,l-a[n-1]);
    for(int i=1;i<=n;i++)
    {
        ans = max(ans, (a[i] - a[i-1]) / 2.0);
    }
    printf("%.10lf\n",ans);
    return 0;
}
