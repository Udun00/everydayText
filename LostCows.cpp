/*
题目：https://vjudge.net/contest/441568#problem/M
思路：从后往前模拟，a[i]的真实数字=a[i]+（1到a[i]+1）之间用过的数字的数目
*/
//代码实现
#include<stdio.h>
int a[80010];
int b[80010];
int c[80010];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    a[1]=0;
    int sum=0;
    for(int i=n;i>=1;i--)
    {
        int s=a[i]+1;
        for(int k=1;k<=s;k++)
        {
            if(c[k]==1)
            {
                s++;//判断下于1到s的数有哪些用了，用了就往后移一位
            }
        }
        b[i]=s;
        c[s]=1;
    }
    for(int i=1;i<=n;i++)printf("%d\n",b[i]);
}
