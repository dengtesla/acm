#include<bits/stdc++.h>
using namespace std;
int a[100000];

void qsort(int a[],int st,int ed)
{
    if(st>=ed) return;
    int base = a[st];
    int i=st,j=ed;
    while(i!=j)
    {
        while(a[j]>=base&&j>i)
        {
            j--;
        }
        while(a[i]<=base&&i<j)
        {
            i++;
        }
        swap(a[i],a[j]);
    }
    swap(a[i],a[st]);
    qsort(a,st,i-1);
    qsort(a,i+1,ed);
}



int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    qsort(a,1,n);
    for(int i=1;i<=n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
