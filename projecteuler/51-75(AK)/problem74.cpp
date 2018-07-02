#include<bits/stdc++.h>
using namespace std;
int a[10];
int cnt = 0;


void init()
{
    a[0] = 1;
    a[1] = 1;
    for(int i=2;i<=9;i++)
        a[i] = i * a[i-1];
}


int nn[100];
void go(int n)
{

    nn[1] = n;
    //cout << nn[1];
    int t = 60;
    int cot=0;
    bool flag = 0;
    do
    {
        string w = to_string(nn[cot+1]);
        int res = 0;
        for(int i=0;i<w.size();i++)
        {
            res += a[w[i]-'0'];
        }
        cot++;
        nn[cot+1] = res;
        for(int i=1;i<cot+1;i++)
        {
            if(nn[i]==res)
            {
                flag=1;
                break;
            }
        }
        if(flag==1) break;
        //cout << " -> " << res;
    }while(cot<70);
    if(cot==60) cnt++;
}



int main()
{
    init();
    int k;
    int n = 1000000;
    for(int i=1;i<=n;i++)
        go(i);
    cout << cnt << endl;
}
