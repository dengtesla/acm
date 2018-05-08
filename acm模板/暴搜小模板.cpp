#include<bits/stdc++.h>
using namespace std;

void dfs(int pos,int a[],int sz)
{
    if(pos >= sz)
    {
        for(int i=0;i!=sz;i++)
            cout << a[i] << " ";
        cout << endl;
        return ;
    }
    int temp = a[pos];
    a[pos] = 0;
    dfs(pos+1,a,sz);
    a[pos] = temp;
    dfs(pos+1,a,sz);
}

int main()
{
    int a[] = {1,2,3,4,5,6};

    dfs(0,a,end(a)-begin(a));
    string s;
    getline(cin,s);
}
