#include<bits/stdc++.h>
using namespace std;




int main()
{
    long long fuck = 10000000;
    int ans = -1;
    for(int n=2;n<=100;n++)
    {
        for(int m=2;m<=100;m++)
        {
            long long res = n*(n-1)*m*(m-1)/4;
            if(abs(res-2000000)<=fuck)
            {
                fuck = abs(res-2000000);
                ans = (m-1)*(n-1);
            }
        }
    }
    cout << ans << endl;
}
