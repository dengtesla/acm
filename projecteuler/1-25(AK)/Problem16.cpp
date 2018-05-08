#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "1";
    int len;
    for(int i=1;i<=1000;i++)
    {
        len = s.length();
        int flag = 0;
        for(int j=len-1;j>=0;j--)
        {
            int tp = (s[j] - '0')*2+flag;
            flag = tp/10;
            s[j] = tp % 10 + '0';
        }
        if(flag != 0) s = "1" + s;
    }

    int ans = 0;
    len = s.length();
    for(int i=0;i<len;i++)
    {
        ans += s[i] - '0';
    }
    cout << ans << endl;
    return 0;
}
