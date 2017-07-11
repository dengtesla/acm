#include<stdio.h>
#include<math.h>

int main()
{
    void hanoi(int n,char one,char two,char three);
    int m;
    printf("input the number of diskes:");
    scanf("%d",&m);
    printf("The step to move %d diskes:\n",m);
    hanoi(m,'A','B','C');
}

void hanoi(int n,char one,char two,char three)
{
    void move(char x,char y);
    if(n==1)
        move(one,three);
        //若n为1，进行最后一步，把one座上最后一个盘移到three座。
    else
    {
        /*
        要完成将n个汉诺塔从one座移到three座，
        我们的想法是先将n-1个汉诺塔座移到two座，
        再将第n个汉诺塔移到three座，
        再将n-1个（已经移到two座的）汉诺塔移到three座。
        */
        hanoi(n-1,one,three,two);  //将n-1个汉诺塔座移到two座
        move(one,three);           //将第n个汉诺塔移到three座
        hanoi(n-1,two,one,three);  //将n-1个（已经移到two座的）汉诺塔移到three座

    }
}

void move(char x,char y)
{
    printf("%c->%c\n",x,y);
}
