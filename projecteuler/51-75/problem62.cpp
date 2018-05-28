#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string,int> mymap;
    map<string,long long> v;
    long long n = 100000;
    for(long long i=1;i<=n;i++)
    {
        long long w = i*i*i;
        string s = to_string(w);
        sort(s.begin(),s.end());
        if(mymap.find(s)==mymap.end())
        {
            mymap[s] = 1;
            v[s] = w;
        }
        else
        {
            mymap[s]++;
        }
        if(mymap[s]==5)
        {
            cout << v[s] << endl;
            return 0;
        }
    }
}
