#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("problem22.in","r",stdin);
    string str,s,a[60000];
    cin >> str;
    int j = 0;
    for(int i=0;i<str.length();i++)
        if(str[i]>='A'&&str[i]<='Z')s+=str[i];
        else{
            if(s.length()==0) continue;
            a[j++]=s;
            s="";
        }
        sort(a,a+j);
        long long sum = 0,sum1;
        for(int i = 0;i<j;i++)
        {
            sum1 = 0;
            for(int k = 0;k<a[i].length();k++)
                sum1+=a[i][k]-'A'+1;
            sum += sum1*(i+1);
        }
        cout << sum << endl;
        return 0;
}
