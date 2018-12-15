#include<bits/stdc++.h>
using namespace std;

int getS(int x1,int y1,int x2,int y2,int x3,int y3)
{
    int s = x1*y2-x2*y1 + x3*y1-x1*y3 + x2*y3-x3*y2;
    s = abs(s);
    s /= 2;
    return s;
}



int main()
{
    int x1,x2,x3;
    int y1,y2,y3;
    int cnt = 0;
    freopen("problem102.in","r",stdin);
    while(scanf("%d,%d,%d,%d,%d,%d",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
    {
        int s1 = getS(x1,y1,x2,y2,0,0);
        int s2 = getS(x1,y1,x3,y3,0,0);
        int s3 = getS(x2,y2,x3,y3,0,0);
        int s4 = getS(x1,y1,x2,y2,x3,y3);
        if(s1+s2+s3<=s4&&s1!=0&&s2!=0&&s3!=0) cnt++;
    }
    cout << cnt << endl;
}
