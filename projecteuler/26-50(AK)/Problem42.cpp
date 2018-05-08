#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("Problem42.in","r",stdin);
    int ans = 0;
    int res = 0;
    char ch;
    while((ch = getchar())!=-1)
    {
        if(isalpha(ch))
        {
            res += toupper(ch) - 'A' + 1 ;
        }
        else
        {
            if(floor(sqrt(res*8+1))*floor(sqrt(res*8+1))==(res*8+1)&&res!=0) ans++;
            res = 0;
        }
    }
    cout << ans << endl;
}
