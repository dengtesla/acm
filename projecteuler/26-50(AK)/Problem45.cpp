#include<bits/stdc++.h>
using namespace std;

int main()
{
    for(int t=1;t<=1000000;t++)
    {
        long long a = 2*t*t+3*t+1;
        if(floor(sqrt(24*a+1))*floor(sqrt(24*a+1))==(24*a+1)&&((long long)(floor(sqrt(24*a+1))))%6==5)
            if(a!=40755)
            {
                cout << a << endl;
                break;
            }

    }
}
