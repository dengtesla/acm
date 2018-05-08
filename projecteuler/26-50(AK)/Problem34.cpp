#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[10];
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3*a[2];
    a[4] = 4*a[3];
    a[5] = 5*a[4];
    a[6] = 6*a[5];
    a[7] = 7*a[6];
    a[8] = 8*a[7];
    a[9] = 9*a[8];
    int ans = 0;
    for(int i = 1;i<=30000000;i++)
    {
        int t = i;
        int sum = 0;
        while(t!=0)
        {
            sum += a[t%10];
            t = t / 10;
        }
        if(i == sum) ans += sum;
           // cout << sum << endl;
    }
    cout << ans-3 << endl;
    return 0;


}
