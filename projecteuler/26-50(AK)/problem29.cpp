#include<bits/stdc++.h>
using namespace std;
/*
int fang(int a,int b)
{
    int t = a;
    for(int i = b;i>0;i--)
        a = a * t;
    return a;
}
*/
int main()
{
    bool istrue[101][101];
    int ans=0;
    int k;
    int t;
    memset(istrue,1,sizeof(istrue));
    for(int i=2;i<=10;i++)
    {
        k=i*i;
        t=2;
        while(k<=100)
        {
            for(int j=2;j<=100;j++)
            {
                if(j%t==0)
                {
                    istrue[k][j/t] = false;
                }
            }
            k=k*i;
            t++;
        if(k==8||k==27||k==64)
            for(int j=2;j<=200/3;j+=2) istrue[k][j] = false;
        if(k==32)
            for(int j=2;j<=40;j+=2) istrue[k][j] = false;
        if(k==32)
            for(int j=3;j<=300/5;j+=3) istrue[k][j] = false;
        if(k==32)
            for(int j=4;j<=400/5;j+=4) istrue[k][j] = false;
        if(k==64)
            for(int j=5;j<=500/6;j+=5) istrue[k][j] = false;
        if(k==64)
            for(int j=4;j<=400/6;j+=2) istrue[k][j] = false;
        if(k==81||k==16)
            for(int j=3;j<=300/4;j+=3) istrue[k][j] = false;
        }
    }
    for(int i=2;i<=100;i++)
        for(int j=2;j<=100;j++)
            if(istrue[i][j]) ans++;
    cout << ans << endl;
  //  for(int i=2;i<=100;i++) cout << "27^" << i << "is" << istrue[27][i] << endl;

//    for(int i=2;i<100;i++)
  //      for(int j=2;j<100;j++);
    //        if(istrue[i][j]==false) cout << i << "^" << j << "is not min" <<endl;


}
