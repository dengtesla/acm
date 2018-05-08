#include<bits/stdc++.h>
using namespace std;


const int MAX = 200;
int nextt[MAX];

void getNext(string t)
{
    int j, k;
    memset(nextt,0,sizeof(nextt));
    j = 0; k = -1; nextt[0] = -1;
    while(j < t.length())
    {
        if(k == -1 || t[j] == t[k])
            nextt[++j] = ++k;
        else
            k = nextt[k];
    }
}
/*
返回模式串t在主串s中首次出现的位置
返回的位置是从0开始的。
*/
int KMP_Index(string t,string s)
{
    int i = 0, j = 0;
    getNext(t);

    while(i < s.length() && j < t.length())
    {
        if(j == -1 || s[i] == t[j])
        {
            i++; j++;
        }
        else
            j = nextt[j];
    }
    if(j == t.length())
        return i - t.length();
    else
        return -1;
}
/*
返回模式串t在主串s中出现的次数
*/
int KMP_Count(string t,string s)
{
    int ans = 0;
    int i, j = 0;

    if(s.length() == 1 && t.length() == 1)
    {
        if(s[0] == t[0])
            return 1;
        else
            return 0;
    }
    getNext(t);
    for(i = 0; i < s.length(); i++)
    {
        while(j > 0 && s[i] != t[j])
            j = nextt[j];
        if(s[i] == t[j])
            j++;
        if(j == t.length())
        {
            ans++;
            j = nextt[j];
        }
    }
    return ans;
}


int main()
{
    string s = "abcabcdabce";
    string t = "abc";
    cout << KMP_Count(t,s) << endl;
}
