#include<bits/stdc++.h>
using namespace std;


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

string a[10];
string b[10];


struct card
{
    int value;
    int suit;
};

struct player
{
    int level;
    card c[6];
}p1,p2;

bool cmp(const card &a,const card &b)
{
    return a.value<b.value;
}

int get_value(char a)
{
    switch(a)
    {
        case '2':return 2;
        case '3':return 3;
        case '4':return 4;
        case '5':return 5;
        case '6':return 6;
        case '7':return 7;
        case '8':return 8;
        case '9':return 9;
        case 'T':return 10;
        case 'J':return 11;
        case 'Q':return 12;
        case 'K':return 13;
        case 'A':return 14;

    }
}

int get_suit(char a)
{
     switch(a)
    {
        case 'H':return 1;
        case 'C':return 2;
        case 'S':return 3;
        case 'D':return 4;
    }
}

int level(player p)
{
    //sort(p.c,p.c+5,cmp);///from lower to higher
    if(p.c[0].suit==p.c[1].suit&&p.c[1].suit==p.c[2].suit&&p.c[2].suit==p.c[3].suit&&p.c[3].suit==p.c[4].suit)
    {
        if(p.c[0].value+1==p.c[1].value&&p.c[1].value+1==p.c[2].value&&p.c[2].value+1==p.c[3].value&&p.c[3].value+1==p.c[4].value)
        {
            if(p.c[0].value==10)
            {
                p.level = 10;
                return 10;
            }
            else
            {
                p.level = 9;
                return 9;
            }
        }
    }

    if(p.c[0].value==p.c[1].value&&p.c[1].value==p.c[2].value&&p.c[2].value==p.c[3].value)
    {
        p.level = 8;
        return 8;
    }
    else if(p.c[4].value==p.c[3].value&&p.c[1].value==p.c[2].value&&p.c[2].value==p.c[3].value)
    {
        p.level = 8;
        return 8;
    }

    if(p.c[0].value==p.c[1].value&&p.c[2].value==p.c[3].value&&p.c[3].value==p.c[4].value)
    {
        p.level = 7;
        return 7;
    }
    else if(p.c[0].value==p.c[1].value&&p.c[2].value==p.c[1].value&&p.c[3].value==p.c[4].value)
    {
        p.level = 7;
        return 7;
    }

    if(p.c[0].suit==p.c[1].suit&&p.c[1].suit==p.c[2].suit&&p.c[2].suit==p.c[3].suit&&p.c[3].suit==p.c[4].suit)
    {
        p.level = 6;
        return 6;
    }
    if(p.c[0].value+1==p.c[1].value&&p.c[1].value+1==p.c[2].value&&p.c[2].value+1==p.c[3].value&&p.c[3].value+1==p.c[4].value)
    {
        p.level = 5;
        return 5;
    }

    if(p.c[0].value==p.c[1].value&&p.c[1].value==p.c[2].value)
    {
        p.level = 4;
        return 4;
    }
    else if(p.c[2].value==p.c[3].value&&p.c[1].value==p.c[2].value)
    {
        p.level = 4;
        return 4;
    }
    else if(p.c[2].value==p.c[3].value&&p.c[3].value==p.c[4].value)
    {
        p.level = 4;
        return 4;
    }

    if(p.c[0].value==p.c[1].value&&p.c[2].value==p.c[3].value)
    {
        p.level = 3;
        return 3;
    }
    else if(p.c[0].value==p.c[1].value&&p.c[4].value==p.c[3].value)
    {
        p.level = 3;
        return 3;
    }
    else if(p.c[2].value==p.c[1].value&&p.c[4].value==p.c[3].value)
    {
        p.level = 3;
        return 3;
    }

    if(p.c[0].value==p.c[1].value||p.c[1].value==p.c[2].value||p.c[2].value==p.c[3].value||p.c[3].value==p.c[4].value)
    {
        p.level = 2;
        return 2;
    }

    p.level = 1;
    return 1;
}


int com(string a[],string b[])
{
    for(int i=0;i<=4;i++)
    {
        p1.c[i].value = get_value(a[i][0]);
        p1.c[i].suit = get_suit(a[i][1]);
        p2.c[i].value = get_value(b[i][0]);
        p2.c[i].suit = get_suit(b[i][1]);
    }
    sort(p1.c,p1.c+5,cmp);
    sort(p2.c,p2.c+5,cmp);
    p1.level = level(p1);
    p2.level = level(p2);
    if(p1.level>p2.level)
        return 1;
    else if(p1.level<p2.level)
        return 0;
    ///p1.level==p2.level
    int l = p1.level;
    if(l==1)
    {
        for(int i=4;i>=0;i--)
        {
            if(p1.c[i].value<p2.c[i].value)
                return 0;
            else if(p1.c[i].value>p2.c[i].value)
                return 1;
        }
        return 0;
    }
    else if(l==2)
    {
        int p1_max;
        int p2_max;
        for(int i=3;i>=0;i--)
        {
            if(p1.c[i].value==p1.c[i+1].value)
            {
                p1_max = p1.c[i].value;
                p1.c[i].value = -1;
                p1.c[i+1].value = -1;
                sort(p1.c,p1.c+5,cmp);
                break;
            }
        }
        for(int i=3;i>=0;i--)
        {
            if(p2.c[i].value==p2.c[i+1].value)
            {
                p2_max = p2.c[i].value;
                p2.c[i].value = -1;
                p2.c[i+1].value = -1;
                sort(p2.c,p2.c+5,cmp);
                break;
            }
        }
        if(p1_max>p2_max) return 1;
        else if(p1_max<p2_max) return 0;
        else
        {
            for(int i=4;i>=0;i--)
            {
                if(p1.c[i].value<p2.c[i].value)
                    return 0;
                else if(p1.c[i].value>p2.c[i].value)
                    return 1;
            }
            return 0;
        }
    }
    else if(l==3)
    {
        int p1_max[2];
        int p2_max[2];
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=3;i>=0;i--)
        {
            if(p1.c[i].value==p1.c[i+1].value)
            {
                p1_max[cnt1] = p1.c[i].value;
                p1.c[i].value = -1;
                p1.c[i+1].value = -1;
                cnt1++;
                //sort(p1.c,p1.c+5,cmp);
                if(cnt1==2) break;
            }
        }
        sort(p1.c,p1.c+5,cmp);
        for(int i=3;i>=0;i--)
        {
            if(p2.c[i].value==p2.c[i+1].value)
            {
                p2_max[cnt2] = p2.c[i].value;
                p2.c[i].value = -1;
                p2.c[i+1].value = -1;
                cnt2++;
                //sort(p1.c,p1.c+5,cmp);
                if(cnt2==2) break;
            }
        }
        sort(p2.c,p2.c+5,cmp);
        if(p1_max[0]>p2_max[0])
        {
            return 1;
        }
        else if(p1_max[0]<p2_max[0])
        {
            return 0;
        }
        else
        {
            if(p1_max[1]>p2_max[1])
            {
                return 1;
            }
            else if(p1_max[1]<p2_max[1])
            {
                return 0;
            }
            else if(p1.c[4].value>p2.c[4].value) return 1;
            else return 0;
        }
    }
    else if(l==4)
    {
        int p1_max;
        int p2_max;
        for(int i=2;i>=0;i--)
        {
            if(p1.c[i].value==p1.c[i+1].value&&p1.c[i+1].value==p1.c[i+2].value)
            {
                p1_max = p1.c[i].value;
                p1.c[i].value = -1;
                p1.c[i+1].value = -1;
                p1.c[i+2].value = -1;
                sort(p1.c,p1.c+5,cmp);
                break;
            }
        }
        for(int i=3;i>=0;i--)
        {
            if(p2.c[i].value==p2.c[i+1].value&&p2.c[i+1].value==p2.c[i+2].value)
            {
                p2_max = p2.c[i].value;
                p2.c[i].value = -1;
                p2.c[i+1].value = -1;
                p2.c[i+2].value = -1;
                sort(p2.c,p2.c+5,cmp);
                break;
            }
        }
        if(p1_max>p2_max) return 1;
        else if(p1_max<p2_max) return 0;
        else
        {
            for(int i=4;i>=0;i--)
            {
                if(p1.c[i].value<p2.c[i].value)
                    return 0;
                else if(p1.c[i].value>p2.c[i].value)
                    return 1;
            }
            return 0;
        }
    }
    else if(l==5)
    {
        if(p1.c[0].value>p2.c[0].value) return 1;
        else return 0;
    }
    else if(l==6)
    {
        for(int i=4;i>=0;i--)
        {
            if(p1.c[i].value<p2.c[i].value)
                return 0;
            else if(p1.c[i].value>p2.c[i].value)
                return 1;
        }
        return 0;
    }
    else if(l==7)
    {
        int p1_max[2];
        int p2_max[2];
        if(p1.c[1].value==p1.c[2].value)
        {
            p1_max[0] = p1.c[0].value;
            p1_max[1] = p1.c[4].value;
        }
        else
        {
            p1_max[1] = p1.c[0].value;
            p1_max[0] = p1.c[4].value;
        }
        if(p2.c[1].value==p2.c[2].value)
        {
            p2_max[0] = p2.c[0].value;
            p2_max[1] = p2.c[4].value;
        }
        else
        {
            p2_max[1] = p2.c[0].value;
            p2_max[0] = p2.c[4].value;
        }
        if(p1_max[0]>p2_max[0])
        {
            return 1;
        }
        else if(p1_max[0]<p2_max[0])
        {
            return 0;
        }
        else
        {
            if(p1_max[1]>p2_max[1])
            {
                return 1;
            }
            else return 0;
        }
    }
    else if(l==8)
    {
        int p1_max[2];
        int p2_max[2];
        if(p1.c[1].value==p1.c[2].value)
        {
            p1_max[0] = p1.c[0].value;
            p1_max[1] = p1.c[4].value;
        }
        else
        {
            p1_max[1] = p1.c[0].value;
            p1_max[0] = p1.c[4].value;
        }
        if(p2.c[1].value==p2.c[2].value)
        {
            p2_max[0] = p2.c[0].value;
            p2_max[1] = p2.c[4].value;
        }
        else
        {
            p2_max[1] = p2.c[0].value;
            p2_max[0] = p2.c[4].value;
        }
        if(p1_max[0]>p2_max[0])
        {
            return 1;
        }
        else if(p1_max[0]<p2_max[0])
        {
            return 0;
        }
        else
        {
            if(p1_max[1]>p2_max[1])
            {
                return 1;
            }
            else return 0;
        }
    }
    else if(l==9)
    {
        if(p1.c[0].value>p2.c[0].value)
            return 1;
        else return 0;
    }
    else if(l==10)
        return 0;
}



int main()
{
    freopen("problem54.in","r",stdin);
    int ans = 0;
    for(int i=1;i<=1000;i++)
    {
        cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
        cin >> b[0] >> b[1] >> b[2] >> b[3] >> b[4];
        if(com(a,b))
            ans++;
        /*
        for(int i=0;i<=4;i++)
        {
            cout << p1.c[i].value << " ";
        }
        cout << endl;
        */
        //cout << p1.level << endl;
        //cout << p2.level << endl;
    }
    cout << ans << endl;
}





