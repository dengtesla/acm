#include <stdio.h>
//交换list[a],list[b]
void Swap(int list[], int a, int b)
{
    int temp = 0;
    temp = list[a];
    list[a] = list[b];
    list[b] = temp;
    return;
}
//将list区间[a,n]之间的数据由小到大排序
void Sort(int list[], int a, int n)
{
    int temp = 0;
    for (int i = 1; i < n-a; ++i)
        for (int j = a+1; j < n-1; ++j)
            if (list[j] > list[j+1])
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
    return;
}
//全排列
void Prim(int list[], int n)
{
    int num = 1, a = 0, b = 0;
    for (int i = n; i > 0; --i)     //计算有多少种情况，就循环多少次
        num *= i;
    while (num--)
    {
        if(num == 10*9*8*7*6*5*4*3*2 - 1000000)
        for (int i = 0; i < n; ++i) //打印情况
            printf("%d",list[i]);
        //printf("\n");

        for (int i = n-1; i > 0; --i) //从右往左，找出第一个左边小于右边的数，设为list[a]
            if (list[i-1] < list[i])
            {
                a = i-1;
                break;
            }
        for (int j = n-1; j > a; --j) //从右往左，找出第一个大于list[a]的数，设为list[b]
            if (list[j] > list[a])
            {
                b = j;
                break;
            }
        Swap(list, a, b);         //交换list[a],list[b]
        Sort(list, a, n);         //将list[a]后面的数据，由小往大排列
    }
    return;
}
//主函数
int main()
{
    int list[] = {0,1,2,3,4,5,6,7,8,9};
    Prim(list,10);
    return 0;
}
