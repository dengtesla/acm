#include<bits/stdc++.h>
using namespace std;

string mul(string a,int b)
{
    string c;
    char s;
    int len=a.length();
    int ok=0;
    for(int i=len-1;i>=0;i--)
    {
        int temp=(a[i]-'0')*b+ok;
        ok=temp/10;
        s=temp%10+'0';
        c=s+c;
    }
    while(ok)
    {
        s=ok%10+'0';
        c=s+c;
        ok/=10;
    }
    return c;
}

int main()
{
    string aa = "1";
    int sum = 0;
    for(int i = 1;i<=100;i++)
    {
        aa = mul(aa,i);
    }
    //    for(int i = 0;i<=aa.length()-1;i++)
    //        cout << aa[i];
    //    cout << endl;
    for(int i = 0;i<=aa.length()-1;i++)
        sum += aa[i]-'0';
    //cout << aa[aa.length()] -'0'<< endl;
    cout << sum << endl;
}
