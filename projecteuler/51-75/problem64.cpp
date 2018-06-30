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
        c.push_back(ccc);
        a.push_back(aaa);
        b.push_back(bbb);
        //cout << aaa << endl;
        if(i>=3)
        if(a[0]==a[i-1]&&a[1]==a[i]&&a[2]==a[i+1])
        {
            a.erase(a.begin());
            a.erase(a.begin());
            a.erase(a.begin());
            //a.erase(a.begin()+3);
            break;
        }
        i++;
    }while(1);
    //cout << i << endl;
    vector<int>::iterator it;
    for(it=a.begin();it!=a.end();it++)
        cout<<*it<<endl;
}

int main()
{
    int n;
    cin >> n;
    get_fractions(n);
    return 0;
}
