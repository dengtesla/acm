#include<bits/stdc++.h>
using namespace std;
string card[4];
int player_level[1000][2];
int player_score[1000][2];
/*
1.High Card: Highest value card.
2.One Pair: Two cards of the same value.
3.Two Pairs: Two different pairs.
4.Three of a Kind: Three cards of the same value.
5.Straight: All cards are consecutive values.
6.Flush: All cards of the same suit.
7.Full House: Three of a kind and a pair.
8.Four of a Kind: Four cards of the same value.
9.Straight Flush: All cards are consecutive values of same suit.
10.Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
*/
//1-49 T-84 J-74 Q-81 K-75 A-65
long long ll[4];

void get_number(string s[])
{
     for(int j=0;j<=4;j++)
        {
            ll[j] = s[j][0]-48;
        }
}



void get_level(string s[],int level,int number)
{
    //1.
    for(int i=0;i<=4;i++)
    {
        level = 1;
        for(int j=0;j<=4;j++)
        {
            ll[j] = s[j][0]-48;
        }
        sort(ll,ll+5);
        for(int j=0;j<=4;j++)
        {
            number += pow(40,j)*ll[j];
        }
        memset(ll,0,sizeof(ll));
    }

    get_number(s);
    sort(ll,ll+5);    //2.
    if()
    {

    }
    if()
    {

    }
    if()
    {

    }
    if()
    {

    }
    if()
    {

    }
    if()
    {

    }
    if()
    {

    }
    if()
    {

    }
    if()
    {

    }
}

int main()
{
    freopen("problem54.in","r",stdin);
    int level;
    int number;
    int cot = 0;
    while(cin >> card[0] >> card[1] >> card[2] >> card[3] >> card[4])
    {
        get_level(card,level,number);
        player_level[cot/2][cot%2] = level;
        player_score[cot/2][cot%2] = number;
        cot++;
    }
}
