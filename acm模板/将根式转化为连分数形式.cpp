#include<bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> b;
vector<int> c;

void get_fractions(int n)
{
    a.clear();
    b.clear();
    c.clear();
    int AA;
    AA = floor(sqrt(n));
    int c0 = n-AA*AA;
    int a0 = (sqrt(n)+AA)/(n-AA*AA);
    int b0 = a0*(n-AA*AA)-AA;
    c.push_back(c0);
    a.push_back(a0);
    b.push_back(b0);
    int i=0;
    do
    {
        int ccc = (n - b[i]*b[i])/c[i];
        int aaa = (sqrt(n)+b[i])/ccc;
        int bbb = aaa*ccc-b[i];
        if(a[0]==aaa&&b[0]==bbb&&c[0]==ccc)
            break;
        c.push_back(ccc);
        a.push_back(aaa);
        b.push_back(bbb);
        i++;
    }while(1);

    printf("[%d;(",AA);
    vector<int>::iterator it;
    for(it=a.begin();it!=a.end();it++)
        cout<<*it<<(it==a.end()-1?")]":",");
    //for(auto& x : a) cout << x;
    cout << endl;

}

int main()
{
    int n;
    while(cin >> n)
    {
        if(floor(sqrt(n))*floor(sqrt(n))==n)
        {
            cout << sqrt(n) << endl;
            continue;
        }
        get_fractions(n);
    }

    return 0;
}
