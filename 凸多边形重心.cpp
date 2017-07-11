#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct centre
{
       double x , y ;
};
int cas , n ;
int a,b;
double Area( centre p0 , centre p1 , centre p2 )
{
       double area = 0 ;
       area =  p0.x * p1.y + p1.x * p2.y + p2.x * p0.y - p1.x * p0.y - p2.x * p1.y - p0.x * p2.y;
       return area / 2 ;  // 另外在求解的过程中，不需要考虑点的输入顺序是顺时针还是逆时针，相除后就抵消了。
}
int main ()
{
    centre p0 , p1 , p2 ;
    double sum_x , sum_y , sum_area , area,xx,yy;
    int q;
    scanf ( "%d" , &n ) ;
    scanf("%d",&q);
          sum_x = sum_y = sum_area = 0 ;
          scanf ( "%lf%lf" , &p0.x , &p0.y ) ;
          scanf ( "%lf%lf" , &p1.x , &p1.y ) ;
          if(n==3)
          {
              scanf("%lf%lf",&p2.x,&p2.y);
              xx=(p1.x+p2.x+p0.x)/3;
              yy=(p1.y+p2.y+p0.y)/3;
          }
          else{
          for ( int i = 2 ; i < n ; ++i )
          {
              scanf ( "%lf%lf" , &p2.x , &p2.y ) ;
              area = Area(p0,p1,p2) ;
              sum_area += area ;
              sum_x += (p0.x + p1.x + p2.x) * area ;
              sum_y += (p0.y + p1.y + p2.y) * area ;
              p1 = p2 ;
          }
          xx=sum_x / sum_area / 3;
          yy=sum_y / sum_area / 3;
          //printf ( "%.20lf %.20lf\n" , sum_x / sum_area / 3 , sum_y / sum_area / 3 ) ;
          }

   for(int i=0;i<q;i++)
   {
       scanf("%d",&a);
       scanf("%d",&b);
       double c=((double)b-yy)/((double)a-xx);
       printf("%.20lf\n",c);
        printf("%.20lf\n",atan(c));
   }
    return 0 ;
}
