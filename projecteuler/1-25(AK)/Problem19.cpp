#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ans=0;
    int mod = 2-31;
    int a[13] = {31,31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i=1901;i<=2000;i++)
    {
        for(int j=1;j<=12;j++)
        {
            if(i%100==0)
            {
                if(i%400==0)
                    a[2]=29;
                else
                    a[2]=28;
            }
            else if(i%4==0) a[2]=29;
            else a[2]=28;

            mod = (mod + a[j-1]) % 7;
            if(mod == 0) ans++;
        }
    }
    cout << ans << endl;
}
