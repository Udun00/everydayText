/*
题目：https://vjudge.net/contest/441568#problem/P
思路：定义dp[i][j]为前i个数以第j个数为标准的最优解，
mi=min(mi,dp[i-1][j]);  dp[i][j]=mi+abs(a[i]-b[j]);
数据有重复要去重
*/
//代码实现
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int dp[2110][2110];//dp[i][j]代表前i个选第j个做标准
int a[2110],b[2110];
int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+t+1);
    int len=unique(b+1,b+t+1)-b-1;
    for(int i=1; i<=t; i++)
    {
        int mi=0x3f3f3f3f;
        for(int j=1; j<=len; j++)
        {
            mi=min(mi,dp[i-1][j]);
            dp[i][j]=mi+abs(a[i]-b[j]);
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=1; i<=len; i++)
    {
        ans=min(ans,dp[t][i]);
    }
    cout<<ans;
}
