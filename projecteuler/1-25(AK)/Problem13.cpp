#include<bits/stdc++.h>
using namespace std;

string sum(string s1,string s2)
{
    if(s1.length()<s2.length())
    {
        string temp=s1;
        s1=s2;
        s2=temp;
    }
    int i,j;
    for(i=s1.length()-1,j=s2.length()-1;i>=0;i--,j--)
    {
        s1[i]=char(s1[i]+(j>=0?s2[j]-'0':0));   //×¢ÒâÏ¸½Ú
        if(s1[i]-'0'>=10)
        {
            s1[i]=char((s1[i]-'0')%10+'0');
            if(i) s1[i-1]++;
            else s1='1'+s1;
        }
    }
    return s1;
}

int main()
{
    freopen("Problem13.in","r",stdin);
    string Map;
    string ans;
    //memset(Map,0,sizeof(Map));
    //memset(ans,0,sizeof(ans));
    for(int i=0;i<100;i++)
    {
        //for(int j=0;j<50;j++)
        //{
            cin >> Map;
        //}
        ans = sum(ans,Map);
    }
    for(int i = 0;i <= 9;i++)
        cout << ans[i];
    //string a1 = "37107287533902102798797998220837590246510135740250";
    //string a2 = "46376937677490009712648124896970078050417018260538";
    //cout << sum(a1,a2) << endl ;
}
