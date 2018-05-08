#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(a%b==0) return b;
    else if(a>b) return gcd(a%b,b);
    else if(a<b) return gcd(b,a);
}

int main()
{
    int aa = 1;
    int cc = 1;
    for(int a=1;a<=9;a++)
        for(int b=1;b<=9;b++)
            for(int c=1;c<=9;c++)
                if(9*a*c == 10*a*b - b*c&&a!=b)
                {
                    //cout << a*10+b << "/" << b*10+c << " = " << a << "/" << c << endl;
                    aa*=a;
                    cc*=c;
                }
     cout << cc/gcd(aa,cc) << endl;
}
