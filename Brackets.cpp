/*
题目：https://vjudge.net/contest/441568#problem/N
思路：简单的区间dp,定义dp[i][j]为区间（i,j）之间最大的括号匹配数，如果不匹配，dp[i][j]=dp[i+1][j],如果在区间（i+1,j）找到一个k与第i个括号匹配，则dp[i][j]=max(dp[i][j],dp[i+1][k-1]+dp[k][j]+2)
*/
//代码实现
#include<string.h>
#include<stdio.h>
char s[110];
int dp[110][110];
int max(int x,int y)
{
    return x>y?x:y;
}
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        if(strcmp(s,"end")==0)
            break;
        int len=strlen(s);
        memset(dp,0,sizeof(dp));
        for(int i=len-2;i>=0;i--)
        {
            for(int j=i+1;j<len;j++)
            {
                dp[i][j]=dp[i+1][j];
                for(int k=i+1;k<=j;k++)
                {
                    if((s[i]=='('&&s[k]==')')||(s[i]=='['&&s[k]==']'))
                    {
                        dp[i][j]=max(dp[i][j],dp[i+1][k-1]+dp[k][j]+2);
                    }
                }
            }
        }
        printf("%d\n",dp[0][len-1]);
    }
}
