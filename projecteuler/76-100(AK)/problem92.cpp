#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n=10000000;
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        int ii = i;
        while(ii!=89&&ii!=1)
        {
            string w = to_string(ii);
            int res = 0;
            for(int j=0;j<w.size();j++)
            {
                res += (w[j]-'0')*(w[j]-'0');
            }
            ii = res;
        }
        if(ii==89) cnt++;
    }
    cout << cnt << endl;
}
