#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("p099_base_exp.txt","r",stdin);
    int mmm = 0;
    long double res = 0;
    for(int i=1;i<=1000;i++)
    {
        long long a,b;
        scanf("%lld,%lld",&a,&b);
        if(b*log(a)>res)
        {
            mmm = i;
            res = b*log(a);
        }
    }
    cout << mmm << endl;

}
