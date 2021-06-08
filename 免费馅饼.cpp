/*
题目：https://vjudge.net/contest/441568#problem/R
思路：和转换一下，就和数字三角形一样，从上往下走找最大值，状态转移方程dp[i][j]=max(dp[i-1][j-1],dp[i-1][j+1],dp[i-1][j])+a[i][j],定义dp[i][j]为第i秒j号位置的最大获得的最大钞票数
*/
//代码实现
#include<stdio.h>
#include<string.h>
long long int dp[100050][20];
long long int a[100050][20];
long long int max(long long int a,long long int b,long long int c)
{
    if(a>b)
    {
        return a>c?a:c;
    }
    else
    {
        return b>c?b:c;
    }
}
int main()
{
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        if(m==0)break;
        long long int t=0;
        long long int x,y;
        while(m--)
        {
            scanf("%lld%lld",&x,&y);
            a[y][x]++;
            if(t<y)
            {
                t=y;
            }
        }
        dp[1][4]=a[1][4];
        dp[1][5]=a[1][5];
        dp[1][6]=a[1][6];
        long long int ans=max(a[1][4],a[1][5],a[1][6]);
        for(int i=2;i<=t;i++)
        {
            for(int j=0;j<11;j++)
            {
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j+1],dp[i-1][j])+a[i][j];
                ans=ans>dp[i][j]?ans:dp[i][j];
            }
        }
        printf("%lld\n",ans);
    }
}
