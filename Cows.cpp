/*
题目：https://vjudge.net/contest/441568#problem/I
思路：树状数组，先把每一对牛喜欢吃草的范围按右边降序排序，从找左边有多少左边界就有多少牛比它强
注意：有多组输入，注意初始化树状数组和答案数组
*/
//代码实现
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int tree[100010];
int n;
int Max_n;
typedef struct
{
    int l,r;
    int wz;
}k;
k a[100010];
int ans[100010];
bool cmp(k x1, k x2)
{
    if(x1.r==x2.r)return x1.l<x2.l;
    else return x1.r>x2.r;
}
int low(int x)
{
    return x&(-x);
}
void add(int x)
{
    while(x<=Max_n)
    {
        tree[x]++;
        x+=low(x);
    }
}
int getsum(int x)
{
   int ans=0;
    while(x>0)
    {
        ans+=tree[x];
        x-=low(x);
    }
    return ans;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        Max_n=-1;
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].l,&a[i].r);
            a[i].l++,a[i].r++;//让l和r从1开始
            a[i].wz=i;
            Max_n=max(Max_n,a[i].r);//找到最大右边界，减少时间
        }
        a[0].l=-1,a[0].r=-1;
        sort(a+1,a+1+n,cmp);//排序
        memset(ans,0,sizeof(ans));
       for(int i=1; i<=n; i++){
			if(a[i].l==a[i-1].l&&a[i].r==a[i-1].r) ans[a[i].wz]=ans[a[i-1].wz];//如果左右边界相同，则比它强的牛也相同
			else ans[a[i].wz]=getsum(a[i].l);//查询有多少牛比它强
			add(a[i].l);//更新树状数组
		}
        for(int i=1;i<=n;i++)
        {
            if(i!=1)printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
}
