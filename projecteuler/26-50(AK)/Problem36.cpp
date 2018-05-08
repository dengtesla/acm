#include<bits/stdc++.h>
using namespace std;

stack <int>stk;
stack <int>stk2;
bool flag;

int isBinary_palindrome(int n)
{
    while(!stk.empty()) stk.pop();
    while(!stk2.empty()) stk2.pop();
    flag = 0;
    while(n!=0)
    {
        int digit = 0;
        if(n%2) stk.push(1);
        else stk.push(0);
        n /= 2;
    }
    int t = stk.size();
    for(int i=1;i<=t/2;i++)
    {
        stk2.push(stk.top());
        stk.pop();
    }
    if(t%2) stk.pop();
    for(int i=1;i<=t/2;i++)
    {
        if(stk.top()==stk2.top()) ;
        else
        {
            flag = 1;
            break;
        }
        stk.pop();
        stk2.pop();
    }
    if(flag == 0)
        return 1;
    else return 0;
}


int main()
{
    long long ans = 0;

    for(int i=1;i<=999;i++) //考虑偶数位的回文数
    {
        if(i/10==0) ans += isBinary_palindrome(i+10*i)*(i+10*i);
        else if(i/100==0) ans += isBinary_palindrome(i/10+(i%10)*110+floor(i/10)*1000)*(i/10+(i%10)*110+floor(i/10)*1000);
        else ans += (floor(i/100)*100001+10010*floor((i-floor(i/100)*100)/10)+1100*(i%10))*isBinary_palindrome(floor(i/100)*100001+10010*floor((i-floor(i/100)*100)/10)+1100*(i%10));
    }

    for(int i=1;i<=99;i++) //考虑奇数位的回文数
    {
        for(int j=0;j<=9;j++)
        {
            if(i/10==0) ans += isBinary_palindrome(i*101+j*10)*(i*101+j*10);
            else ans += (floor(i/10)*10001+(i%10)*1010+j*100)*isBinary_palindrome(floor(i/10)*10001+(i%10)*1010+j*100);
        }
    }

    for(int i=1;i<=9;i++)
    {
        ans += isBinary_palindrome(i)*i;
    }
    cout << ans << endl;
    int i;
}
