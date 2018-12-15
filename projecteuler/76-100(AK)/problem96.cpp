#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
int wwwww = 0;

namespace dlx{

int id[10][10] , Cid[10][10] , Rid[10][10] , Mid[10][10] , bel[10][10] ;
int Rcnt , Rmean[1000] ;
struct Node{
    Node *lf , *rg , *up , *dn , *col ;
    int Rnum , Cnum , Ccnt ;
}w[5005] , *C[350] , *R[1000] , *Head , *tw = w ;


void Insert( int r_ , int c_ ){
    Node *nd = ++tw ;
    C[c_]->Ccnt ++ ;
    nd->Rnum = r_ , nd->Cnum = c_ , nd->col = C[c_] ;
    nd->up = C[c_]->up ; nd->dn = C[c_] ;
    C[c_]->up->dn = nd ; C[c_]->up = nd ;

    if( !R[r_] ){
        R[r_] = nd ;
        R[r_]->lf = R[r_]->rg = R[r_] ;
    } else {
        nd->lf = R[r_]->lf , nd->rg = R[r_] ;
        R[r_]->lf->rg = nd , R[r_]->lf = nd ;
    }
}

void insertLine( int i , int j , int x ){
    Rcnt ++ ; Rmean[Rcnt] = x ;
    Insert( Rcnt , id[i][j] ) ;
    Insert( Rcnt , Rid[i][x] ) ;
    Insert( Rcnt , Cid[j][x] ) ;
    Insert( Rcnt , Mid[ bel[i][j] ][x] ) ;
}

void init(){
    int tmp = 0 ;
    for( int i = 1 ; i <= 9 ; i ++ )
        for( int j = 1 ; j <= 9 ; j ++ )
            id[i][j] = ++tmp , Rid[i][j] = id[i][j] + 81 ,
            Cid[i][j] = Rid[i][j] + 81 , Mid[i][j] = Cid[i][j] + 81 ;
    for( int i = 1 ; i <= 9 ; i ++ ){
        for( int j = 1 ; j <= 9 ; j ++ )
            bel[i][j] = ( i - 1 ) / 3 * 3 + ( j + 2 ) / 3 ;
    }

    Head = ++tw ;
    for( int i = 1 ; i <= 324 ; i ++ )
        C[i] = ++tw , C[i]->Ccnt = 0 , C[i]->Cnum = i ;
    for( int i = 1 ; i <= 324 ; i ++ ){
        C[i]->up = C[i]->dn = C[i] ;
        C[i]->rg = C[i+1] , C[i]->lf = C[i-1] ;
    }
    C[0] = R[0] = Head ;
    C[1]->lf = Head , Head->rg = C[1] ;
    C[324]->rg = Head , Head->lf = C[324] ;
}

void remove( Node *nd ){
    nd->lf->rg = nd->rg ;
    nd->rg->lf = nd->lf ;
    for( Node *i = nd->dn ; i != nd ; i = i->dn ){
        for( Node *j = i->rg ; j != i ; j = j->rg ){
            j->col->Ccnt -- ;
            j->up->dn = j->dn , j->dn->up = j->up ;
        }
    }
}

void resume( Node *nd ){
    for( Node *i = nd->up ; i != nd ; i = i->up ){
        for( Node *j = i->lf ; j != i ; j = j->lf ){
            j->col->Ccnt ++ ;
            j->up->dn = j , j->dn->up = j ;
        }
    }
    nd->lf->rg = nd ;
    nd->rg->lf = nd ;
}

int sta[10005] , topp , ans[10][10] ;


void print(){
    sort( sta + 1 , sta + topp + 1 ) ;
    wwwww += Rmean[sta[1]]*100 + Rmean[sta[2]]*10 + Rmean[sta[3]];
    /*
    for(int j=1;j<=3;j++)
    {
        printf("%d",Rmean[sta[j]]);
    }
    */
    /*
    for( int i = 1 , tmp = 0 ; i <= 9 ; i ++ ){
        for( int j = 1 ; j <= 9 ; j ++ )
            tmp ++ , printf( "%d " , Rmean[ sta[tmp] ] ) ;
        puts( "" ) ;
    }
    */
}

bool solve(){
    if( Head->rg == Head ){
        print() ; return true ;
    }
    Node *now = Head->rg ;
    for( Node *tmp = now->rg ; tmp != Head ; tmp = tmp->rg )
        if( tmp->Ccnt < now->Ccnt ) now = tmp ;

    remove( now ) ;
    for( Node *i = now->dn ; i != now ; i = i->dn ){//当前选第i行
        for( Node *j = i->rg ; j != i ; j = j->rg )//所有i行有的元素,其他行都不能有
            remove( j->col ) ;

        sta[++topp] = i->Rnum ;
        if( solve() ) return true ;
        topp -- ;

        for( Node *j = i->lf ; j != i ; j = j->lf )
            resume( j->col ) ;
    }
    resume( now ) ;
    return false ;
}
string ma[10];
void gogogo()
{
    int w;
    scanf("%*s%d",&w);
    //cout << 111111 << endl;

        for(int i = 1;i<=9;i++)
        {
            std::cin >> ma[i];
            cout << ma[i] << endl;
        }
        dlx::init() ;
        for( int i = 1 , x ; i <= 9 ; i ++ ){
            for( int j = 1 ; j <= 9 ; j ++ ){
                x = ma[i][j-1]-'0';
                //cout << x << " ";
                //scanf( "%d" , &x ) ;
                if( !x ){
                    for( int k = 1 ; k <= 9 ; k ++ )
                        insertLine( i , j , k ) ;
                } else insertLine( i , j , x ) ;
            }//cout << endl;
        }
        solve() ;
        return;
}


}


int main(){
    //freopen("problem96.in","r",stdin);
    int T = 50;
    while(T--)
    {
        dlx::gogogo();
        cout << wwwww << endl;
    }
}
/*
8 0 0 0 0 0 0 0 0
0 0 3 6 0 0 0 0 0
0 7 0 0 9 0 2 0 0
0 5 0 0 0 7 0 0 0
0 0 0 0 4 5 7 0 0
0 0 0 1 0 0 0 3 0
0 0 1 0 0 0 0 6 8
0 0 8 5 0 0 0 1 0
0 9 0 0 0 0 4 0 0

483+245+462+137+523+176+143+487+814+761

976+962+397+639+697+361+359+786+743+782

428+425+348+124+361+581+387+345+235+298

761+132+698+852+453+516+945+365+134+193

814+384+469+316+586+954+159+861+294+351

4231+6702+3532+5049+5188 = 24702

*/
