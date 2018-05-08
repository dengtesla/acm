#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 1;
    int cnt = 0;
    for(int n=1;n<=100;n++)
    {
        for(int r=1;r<=1+n/2;r++)
        {
            if(r==1) ans = n;
            else
            {
                ans *= n-r+1;
                ans /= r;
            }
            //cout << cnt << endl;
            if(ans>1000000)
            {
                //cout << "The " << n << "th is " << r << ". So the number is " << n+1-2*r << endl;;
                cnt += n+1-2*r;
                //cout << cnt << endl;
                break;
            }
        }
    }
    cout << cnt << endl;
}
