#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=0,m=0;
    for(int a = 1;a <= 1000;a++)
    {
        for(int b = a;b <= 1000;b++)
        {
            if(2000*(a+b)==2*a*b+1000000)
            {
                n=a;m=b;
                //cout << a << " " << b << " " << 2000*(a+b) << endl;
                break;
            }
        }
        if(2000*(n+m)==2*n*m+1000000)
                break;
    }
    cout << n*m*(1000-m-n) << endl;
}
