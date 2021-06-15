/*
题目：https://vjudge.net/contest/441568#problem/Q
思路：因为题目数据最多5行且每行最多30个人,定义dp[i1,i2,i3,i4,i5]为第几排有多少人的方案
转移方程:dp[i1+1][i2][i3][i4][i5]+=dp[i1][i2][i3][i4][i5];
        dp[i1][i2+1][i3][i4][i5]+=dp[i1][i2][i3][i4][i5];
        dp[i1][i2][i3+1][i4][i5]+=dp[i1][i2][i3][i4][i5];
        dp[i1][i2][i3][i4+1][i5]+=dp[i1][i2][i3][i4][i5];
        dp[i1][i2][i3][i4][i5+1]+=dp[i1][i2][i3][i4][i5];
        每排的人要比上面一排少
*/
//代码实现
#include<stdio.h>
#include<string.h>
int n[7];
int main()
{
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        if(k==0)break;
        memset(n,0,sizeof(n));
        for(int i=0; i<k; i++)
        {
            scanf("%d",&n[i]);
        }
        long long dp[n[0]+1][n[1]+1][n[2]+1][n[3]+1][n[4]+1];
        memset(dp,0,sizeof(dp));
        dp[0][0][0][0][0]=1;
        for(int i1=0; i1<=n[0]; i1++)
        {
            for(int i2=0; i2<=n[1]; i2++)
            {
                for(int i3=0; i3<=n[2]; i3++)
                {
                    for(int i4=0; i4<=n[3]; i4++)
                    {
                        for(int i5=0; i5<=n[4]; i5++)
                        {
                            if(i1<n[0])       dp[i1+1][i2][i3][i4][i5]+=dp[i1][i2][i3][i4][i5];
                            if(i2<n[1]&&i2<i1)dp[i1][i2+1][i3][i4][i5]+=dp[i1][i2][i3][i4][i5];
                            if(i3<n[2]&&i3<i2)dp[i1][i2][i3+1][i4][i5]+=dp[i1][i2][i3][i4][i5];
                            if(i4<n[3]&&i4<i3)dp[i1][i2][i3][i4+1][i5]+=dp[i1][i2][i3][i4][i5];
                            if(i5<n[4]&&i5<i4)dp[i1][i2][i3][i4][i5+1]+=dp[i1][i2][i3][i4][i5];
                        }
                    }
                }
            }
        }
        printf("%lld\n",dp[n[0]][n[1]][n[2]][n[3]][n[4]]);
    }
    return 0;
}
