#include<bits/stdc++.h>
using namespace std;

int main()
{
     int a[10];
     a[0]=0;
     a[1]=1;
     a[2]=32;
     a[3]=243;
     a[4]=1024;
     a[5]=5*5*5*5*5;
     a[6]=6*6*6*6*6;
     a[7]=7*7*7*7*7;
     a[8]=8*8*8*8*8;
     a[9]=9*9*9*9*9;
     int ans = 0;
     for(int i=10;i<400000;i++)
     {

       int j = i;
       int cnt = 0;
       while(j/10!=0)
       {
         cnt += a[j%10];
         j = j / 10;
       }
       cnt += a[j%10];
       if(cnt == i)   ans += i; //cout << i << endl;
     }
     cout << ans << endl;
}
