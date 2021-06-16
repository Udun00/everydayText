/*
题目：https://vjudge.net/contest/441568#problem/E
思路：kmp+最小最大表示法，设置两个指针i，j和偏移量k，比较s[i+k]和s[j+k]的大小，如果相等k++，如果s[i+k]>s[j+k],i=i+k+1,否则j=j+k+1；
改表示法字符串出现了多少次，转换成最小循环节的问题，如果len%(len-next[len])=0,ans=len/(len-next[len]);否则ans=1;
*/
//代码实现
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int nextt[1000010];
char s[1000010];
int len;
void get_next(char s[])
{
    int i=0,j=0;
    nextt[0]=-1;
    nextt[1]=0;
    for(int i=1; i<len; i++)
    {
        int t=nextt[i];
        int k=i;
        while(s[t]!=s[i])
        {
            k=t;
            t=nextt[t];
            if(t==-1)
                break;
        }
        nextt[i+1]=nextt[k]+1;
    }
}
int getmin(char s[])
{
    int i=0,j=1,k=0;//j是比较指针，k是偏移指针
    while(i<len&&j<len&&k<len)
    {
        int t=s[(i+k)%len]-s[(j+k)%len];
        if(t==0)
        {
            k++;
        }
        else
        {
            if(t>0)//以i开头的字符串不是最小表示，移动i
            {
                i=i+k+1;
            }
            else //以j开头的字符串不是最小表示，移动j
            {
                j=j+k+1;
            }
            if(i==j)
            {
                j++;
            }
            k=0;
        }
    }
    int mi=min(i,j);
    return mi;
}
int getmax(char  s[])
{
    int i=0,j=1,k=0;//j是比较指针，k是偏移指针
    int len=strlen(s);
    while(i<len&&j<len&&k<len)
    {
        int t=s[(i+k)%len]-s[(j+k)%len];
        if(t==0)
        {
            k++;
        }
        else
        {
            if(t>0)//以j开头的字符串不是最大表示，移动j
            {
                j=j+k+1;
            }
            else //以i开头的字符串不是最大表示表示，移动i
            {
                i=i+k+1;
            }
            if(i==j)
            {
                j++;
            }
            k=0;
        }
    }
    int ma=min(i,j);
    return ma;
}

int main()
{
    while(scanf("%s",s)!=EOF)
    {
        len=strlen(s);
        int mmi=0,mma=0;
        mmi=getmin(s);
        mma=getmax(s);
        get_next(s);
        int ans;
        int sum=len-nextt[len];
        if(len%sum==0)ans=len/sum;
        else ans=1;
        printf("%d %d %d %d\n",mmi+1,ans,mma+1,ans);
    }
}
