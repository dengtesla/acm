#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long ans = 100000000000;
    int a1,a2;
    for(int i=1;i<=20000;i++)
    {
        for(int j=i+1;j<=20000;j++)
        {
            long long t1 = 3*(j-i)*(j+i)-j+i;
            long long t2 = 3*j*j+3*i*i-i-j;
            if(floor(sqrt(12*t1+1))*floor(sqrt(12*t1+1))==(12*t1+1)&&floor(sqrt(12*t2+1))*floor(sqrt(12*t2+1))==(12*t2+1))
            {
                if(((int)sqrt(12*t1+1))%6==5&&((int)sqrt(12*t2+1))%6==5)
                    {
                        if(t1<=ans)
                        {
                            ans = t1;
                            a1 = i;
                            a2 = j;
                        }
                    }
            }
        }
    }
    cout << ans/2 << endl;
}
