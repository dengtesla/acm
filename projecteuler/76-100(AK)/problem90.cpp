#include<bits/stdc++.h>
using namespace std;
int dice1[10];
int dice2[10];
int cnt = 0;

int ans1[] = {0,0,0,1,2,3,4,6,8};
int ans2[] = {1,4,9,6,5,6,9,4,1};

void check()
{
    bool flag = 1;
    for(int i=0;i<=8;i++)
    {
        bool cc = 0;
        for(int k1 = 1;k1<=6;k1++)
        {
            for(int k2 = 1;k2<=6;k2++)
            {
                if(dice1[k1]==ans1[i]&&dice2[k2]==ans2[i]) cc = 1;
                if(dice1[k1]==ans2[i]&&dice2[k2]==ans1[i]) cc = 1;
                if(ans1[i]==6)
                {
                    if(dice1[k1]==9&&dice2[k2]==ans2[i]) cc = 1;
                    if(dice1[k1]==ans2[i]&&dice2[k2]==9) cc = 1;
                }
                if(ans2[i]==6||ans2[i]==9)
                {
                    if(dice1[k1]==ans1[i]&&dice2[k2]==15-ans2[i]) cc = 1;
                    if(dice1[k1]==15-ans2[i]&&dice2[k2]==ans1[i]) cc = 1;
                }
            }
        }
        if(!cc) return;
    }
    if(flag) cnt++;
}


int main()
{
    for(dice1[1]=0;dice1[1]<=9;dice1[1]++)
    for(dice1[2]=dice1[1]+1;dice1[2]<=9;dice1[2]++)
    for(dice1[3]=dice1[2]+1;dice1[3]<=9;dice1[3]++)
    for(dice1[4]=dice1[3]+1;dice1[4]<=9;dice1[4]++)
    for(dice1[5]=dice1[4]+1;dice1[5]<=9;dice1[5]++)
    for(dice1[6]=dice1[5]+1;dice1[6]<=9;dice1[6]++)
        for(dice2[1]=0;dice2[1]<=9;dice2[1]++)
        for(dice2[2]=dice2[1]+1;dice2[2]<=9;dice2[2]++)
        for(dice2[3]=dice2[2]+1;dice2[3]<=9;dice2[3]++)
        for(dice2[4]=dice2[3]+1;dice2[4]<=9;dice2[4]++)
        for(dice2[5]=dice2[4]+1;dice2[5]<=9;dice2[5]++)
        for(dice2[6]=dice2[5]+1;dice2[6]<=9;dice2[6]++)
            check();
    cout << cnt/2 << endl;
}
