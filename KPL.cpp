/*
题目：https://vjudge.net/contest/441568#problem/F
思路：利用队列存储原数据，利用数组和插入排序存升序的数据（利用二分查找找到插入位置或删除位置），每回查询时输出中间的数（数据太水了）
*/
//代码实现
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#define ll long long int
using namespace std;
queue <ll> q;
ll num[100010];
ll sum;
void ins(ll x)
{
    int k=lower_bound(num,num+sum,x)-num;
    for(int i=sum;i>k;i--)
    {
        num[i]=num[i-1];
    }
    num[k]=x;
    sum++;
}
void del(ll x)
{
    int k=lower_bound(num,num+sum,x)-num;
    for(int i=k;i<sum;i++)
    {
        num[i]=num[i+1];
    }
    sum--;
}
int main()
{
    ll n;
    ll o=1;
    while(scanf("%lld",&n)!=EOF)
    {
        while(!q.empty())q.pop();
        for(int i=0;i<n;i++)num[i]=0x3f3f3f3f;
        sum=0;
        printf("Case #%lld:\n",o++);
        for(int i=0;i<n;i++)
        {
            char s[10];
            scanf("%s",s);
            if(s[0]=='i')
            {
                ll x;
                scanf("%lld",&x);
                q.push(x);
                ins(x);
            }
            else if(s[0]=='o')
            {
                ll temp=q.front();
                q.pop();
                del(temp);
            }
            else
            {
                printf("%lld\n",num[sum/2]);
            }
        }
    }
}
