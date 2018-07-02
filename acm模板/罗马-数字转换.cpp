#include<bits/stdc++.h>
using namespace std;
char str[10]="IVXLCDM";
int num[10]={1,5,10,50,100,500,1000};


int roman_to_num(char s[])
{
    int len=strlen(s);
    int cnt=0,a[20];
    for(int i=0;i<len;i++)
    {
        int f=0,t;
        if(s[i]==s[i+1]&&i!=len-1)
        {
            if(s[i]==s[i+2]&&i!=len-2)
            {
                f=2;
            }
            else
                f=1;
        }
        for(int k=0;k<7;k++)
            if(s[i]==str[k])
        {
            t=k;
            break;
        }
        a[cnt++]=num[t]*(f+1);
        i+=f;


    }
    int sum=0;
    for(int i=0;i<cnt;i++)
        sum+=a[i];


    for(int i=0;i<cnt-1;i++)
    {
        if(a[i]<a[i+1])sum-=2*a[i];
    }
    return sum;
}


string num_to_roman(int num)
{
    char* digit[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
	char* ten[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
	char* hundreds[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	char* thousand[7] = {"","M","MM","MMM","MMMM","MMMMM","MMMMMM"};
	string ans;

	ans = string(thousand[num/1000]) + string(hundreds[num%1000/100]) + string(ten[num%100/10]) + string(digit[num%10]);
	return ans;
}


int main()
{
    char a[101];
    scanf("%s",a);
    cout << roman_to_num(a) << endl;
    cout << num_to_roman(roman_to_num(a)) << endl;
}
