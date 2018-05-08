#include<bits/stdc++.h>
using namespace std;

string add(string a,string b)
{
    string c;
    int len1=a.length();
    int len2=b.length();
    int len=max(len1,len2);
    for(int i=len1;i<len;i++)
        a = "0" + a;
    for(int i=len2;i<len;i++)
        b = "0" + b;
    int ok = 0;
    for(int i = len-1;i>=0;i--)
    {
        char temp = a[i] + b[i] - '0' + ok;
        if(temp > '9')
        {
            ok=1;
            temp-=10;
        }
        else ok = 0;
        c = temp + c;
    }
    if(ok) c = "1" + c;
    return c;
}

int main()
{
    string f[10000];
    f[1] = "1";
    f[2] = "1";
    for(int i=3;f[i].length()<1000;i++)
    {
        f[i] = add(f[i-1],f[i-2]);
        if(f[i].length()==1000)
        {
            cout << i;
            break;
        }
    }
}
