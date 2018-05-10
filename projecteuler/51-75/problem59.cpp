#include<bits/stdc++.h>
using namespace std;

/*
int main()
{
    //freopen("problem59.in","r",stdin);
    char buf[100];
    char w[] = {'g','o','d'};
    while(cin.getline(buf,100,','))
    {
        cout << buf << endl;
    }
}
*/
///97-122
int a[10000];

int main()
{
    freopen("problem59.in","r",stdin);
    scanf("%d",&a[0]);
    int cnt = 1;
    int w;
    while(scanf(",%d",&w))
    {
        a[cnt] = w;
        cnt++;
    }
    cnt--;
    int i[3];
    /*
    for(i[0]=97;i[0]<=122;i[0]++)
    {
        for(i[1]=97;i[1]<=122;i[1]++)
        {
            for(i[2]=97;i[2]<=122;i[2]++)
            {
                int cot = 0;
                for(int j=0;j<=cnt;j++)
                {
                    if(a[j]^i[j%3]<=122&&a[j]^i[j%3]>=97)
                        cot++;
                }
                //cout << cot << endl;
                if(cot>=cnt-2)
                    cout << i[0] << " " << i[1] << " " << i[2] << endl;
            }
        }
    }
    */

    i[0]='g';
    i[1]='o';
    i[2]='d';
    int cot = 0;
    long long ans = 0;
    for(int j=0;j<=cnt;j++)
    {
        //if(a[j]^i[j%3]<=122&&a[j]^i[j%3]>=97)
        {
            //cout << char(a[j]^i[j%3]);
            ans += a[j]^i[j%3];
        }
        //cot++;
    }
    cout << ans << endl;
}
