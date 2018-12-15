#include<bits/stdc++.h>
using namespace std;
int l[5];


int main()
{
    int cnt = 0;
    int n = 50;
    for(int x1=0;x1<=n;x1++)
    {
        for(int y1=0;y1<=n;y1++)
        {
            for(int x2=0;x2<=n;x2++)
            {
                for(int y2=0;y2<=n;y2++)
                {
                    l[0] = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
                    l[1] = x1*x1 + y1*y1;
                    l[2] = x2*x2 + y2*y2;
                    sort(l,l+3);
                    if(l[0]+l[1] == l[2]&&l[0]!=0&&l[1]!=0&&l[2]!=0) cnt++;
                }
            }
        }
    }
    cout << cnt/2 << endl;
}
