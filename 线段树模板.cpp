/*
题目：https://vjudge.net/contest/441568#problem/L
思路：线段树模板，区间修改，区间查找，维护区间的和
注意：在修改时用懒标记，在需要查询时在修改节省时间
*/
//代码实现
#include<stdio.h>
int b[100015];
struct tree{
    int l,r;
    long long int sum,add;
}a[500045];

void creat(int rt,int l,int r){
    a[rt].l=l;
    a[rt].r=r;
    if(l==r){
        a[rt].sum=b[l];
        return;
    }
    int mid=(l+r)>>1;
    creat(rt*2,l,mid);
    creat(rt*2+1,mid+1,r);
    a[rt].sum=a[rt*2].sum+a[rt*2+1].sum;
}

void pushdown(int rt){
    if(a[rt].add!=0){
        a[rt*2].sum+=a[rt].add*(a[rt*2].r-a[rt*2].l+1);
        a[rt*2+1].sum+=a[rt].add*(a[rt*2+1].r-a[rt*2+1].l+1);
        a[rt*2].add+=a[rt].add;
        a[rt*2+1].add+=a[rt].add;
        a[rt].add=0;
    }
}

void ad(int rt,int l,int r,int x)
{
    if(l<=a[rt].l && r>=a[rt].r){
        a[rt].sum+=(long long int)(a[rt].r-a[rt].l+1)*x;
        a[rt].add+=x;
        return;
    }
    pushdown(rt);
    int mid=(a[rt].l+a[rt].r)>>1;
    if(l<=mid) ad(rt*2,l,r,x);
    if(r>mid) ad(rt*2+1,l,r,x);
    a[rt].sum=a[rt*2].sum+a[rt*2+1].sum;
}

long long int find(int rt,int l,int r)
{
    if(l<=a[rt].l && r>=a[rt].r) return a[rt].sum;
    pushdown(rt);
    int mid=(a[rt].l+a[rt].r)>>1;
    long long int ans=0;
    if(l<=mid) ans+=find(rt*2,l,r);
    if(r>mid) ans+=find(rt*2+1,l,r);
    return ans;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    scanf("%d",&b[i]);
    creat(1,1,n);
    getchar();
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        char p;
        scanf("%c",&p);
        if(p=='C')
        {
            scanf("%d%d%d",&x,&y,&z);
            ad(1,x,y,z);
        }
        else
         {
            scanf("%d%d",&x,&y);
            printf("%lld\n",find(1,x,y));
        }
        getchar();
    }
    return 0;
}
