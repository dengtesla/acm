#include<bits/stdc++.h>
using namespace std;

int main()
{
    long double a = 1;
    int ans = 0;
    while(pow(10,(a-1)/a)<=8)
    {
        ans += 10-ceil(pow(10,(a-1)/a));
        a++;
    }
    a--;
    ans+=(21-a);
    cout << ans << endl;
}
