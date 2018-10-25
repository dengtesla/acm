#include<bits/stdc++.h>
using namespace std;

char s[500000];
char s_new[1000000+10];
int pos[1000000+10];

int manacher(char *s)
{
    int len = strlen(s);
    s_new[0] = '$';
    s_new[1] = '#';
    for(int i=0;i<len;i++)
    {
        s_new[2*(i+1)] = s[i];
        s_new[2*(i+1)+1] = '#';
    }
    s_new[2*(len+1)] = '\0';
    int len2 = strlen(s_new);
    int mx = 0,ans = 0,po = 0;
    for(int i=1;i<len2;i++)
    {
        if(i<mx) pos[i] = min(pos[2*po-i],mx-i);
        else pos[i] = 1;
        while(s_new[i-pos[i]]==s_new[i+pos[i]]) pos[i]++;
        if(mx<i+pos[i])
        {
            po = i;
            mx = i+pos[i];
        }
        ans = max(ans,pos[i]-1);
    }
    return ans;
}


int main()
{
    while (printf("请输入字符串：\n"))
    {
        scanf("%s", s);
        printf("最长回文长度为 %d\n\n", manacher(s));
        for(int i=0;i<strlen(s_new);i++) cout << s_new[i];
        cout << endl;
        for(int i=0;i<strlen(s_new);i++) cout << pos[i];
        cout << endl;
    }
    return 0;
}
