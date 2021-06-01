/*
题目：https://vjudge.net/contest/441568#problem/K
思路：线段树模板，单点修改，范围查询，维护区间最大值
*/
//代码实现
#include<stdio.h>
const int max_n=200010;
typedef struct
{
    int l,r;
    int max_data;
}tree;
tree a[800040];
int b[200010];
int max(int a,int b)
{
    return a>b?a:b;
}
void pushup(int head)
{
    a[head].max_data=a[head*2].max_data>a[head*2+1].max_data?a[head*2].max_data:a[head*2+1].max_data;
}
void creat(int rt,int l,int r)
{
    a[rt].l=l,a[rt].r=r;
    if(l==r)
    {
        a[rt].max_data=b[l];
        return ;
    }
    int mid=(l+r)>>1;
    creat(rt*2,l,mid);
    creat(rt*2+1,mid+1,r);
    pushup(rt);
}
void update(int rt,int x,int c)
{
    if(a[rt].l==a[rt].r)
    {
        a[rt].max_data=c;
        return ;
    }
    int mid=(a[rt].l+a[rt].r)>>1;
    if(x<=mid)update(rt*2,x,c);
    else update(rt*2+1,x,c);
    pushup(rt);
}
int find(int rt,int l,int r)
{
    if(a[rt].l>=l&&a[rt].r<=r)
    {
        return a[rt].max_data;
    }
    int mid=(a[rt].l+a[rt].r)>>1;
    int ans=0;
    if(l<=mid) ans=max(ans,find(rt*2,l,r));
    if(r>mid) ans=max(ans,find(rt*2+1,l,r));
    return ans;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        creat(1,1,n);
        getchar();
        for(int i=1;i<=m;i++)
        {
            char x;
            scanf("%c",&x);
            if(x=='Q')
            {
                int g,h;
                scanf("%d%d",&g,&h);
                printf("%d\n",find(1,g,h));
            }
            else if(x=='U')
            {
                int g,h;
                scanf("%d%d",&g,&h);
                update(1,g,h);
            }
            getchar();
        }
    }
}
