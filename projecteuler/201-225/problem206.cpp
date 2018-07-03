#include<bits/stdc++.h>
using namespace std;

bool pending(long long i)
{
    long long w = i*i;
    string t = to_string(w);
    for(int j=1;j<=9;j++)
        if(t[2*(j-1)]-'0'!=j)
            return 0;
    return 1;
}




int main()
{
    long long down = (long long)sqrt(10000000000000000);
    long long up =   (long long)sqrt(19999999999999999);
    for(long long i = down;i<=up;i++)
    {
        if(pending(i))
        {
            cout << i << 0 << endl;
            break;
        }
    }
}
