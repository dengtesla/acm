///中缀表达式转后缀表达式
#include<bits/stdc++.h>
#include<stack>
const int MAX=100;
using namespace std;
char pp[MAX];//存储转换后的后缀表达式
void trans(char *str)//将中缀表达式转换后缀表达式
{
    stack<char>ss;
    int i,j;
    i=0;
    j=0;
    while(str[i]!='#')
    {
        if(str[i]=='(')
        {
            ss.push(str[i]);
        }
        else if(str[i]==')')
        {
            while(ss.top()!='(')
            {
                pp[j++]=ss.top();
                ss.pop();
            }
            ss.pop();

        }
        else if(str[i]=='+'||str[i]=='-')
        {
            while(!ss.empty()&&ss.top()!='(')
            {
                pp[j++]=ss.top();
                ss.pop();
            }
            ss.push(str[i]);
        }
        else if(str[i]=='*'||str[i]=='/')
        {
            while((!ss.empty()&&ss.top()=='*')||(!ss.empty()&&ss.top()=='/'))
            {
                pp[j++]=ss.top();
                ss.pop();
            }
            ss.push(str[i]);
        }
        else if(str[i]==' ')
        {
            i++;
            continue;
        }
        else
        {
            while(str[i]>='0'&&str[i]<='9')
            {
                pp[j++]=str[i];
                i++;
            }
            i--;
            pp[j++]='#';
        }
        i++;
    }
    while(!ss.empty())
    {
        pp[j++]=ss.top();
        ss.pop();
    }
    pp[j]='#';
    for(int k=0; k<=j; k++)//输出转化后的后缀表达式
    {
        printf("%c",pp[k]);
    }
    printf("\n");
}
void compvalue()//计算后缀表达式的值
{
    double d;
    stack<double>mm;
    int i;
    i=0;
    while(pp[i]!='#')
    {
        if(pp[i]=='+')
        {
            double r=mm.top();
            mm.pop();
            double l=mm.top();
            mm.pop();
            double result=l+r;
            mm.push(result);
        }
        else if(pp[i]=='-')
        {
            double r=mm.top();
            mm.pop();
            double l=mm.top();
            mm.pop();
            double result=l-r;
            mm.push(result);
        }
        else if(pp[i]=='*')
        {
            double r=mm.top();
            mm.pop();
            double l=mm.top();
            mm.pop();
            double result=l*r;
            mm.push(result);
        }
        else if(pp[i]=='/')
        {
            double r=mm.top();
            mm.pop();
            double l=mm.top();
            mm.pop();
            double result=l/r;
            mm.push(result);
        }
        else
        {
          d=0;
          while(pp[i]>='0'&&pp[i]<='9')
          {
              d=10*d+pp[i]-'0';
              i++;
          }
          mm.push(d);
        }
        i++;
    }
    printf("%lf\n",mm.top());
}
int main()
{
    char str[MAX];
    while(gets(str))
    {
        trans(str);
        compvalue();
    }
    return 0;
}
