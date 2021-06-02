/*
题目：https://vjudge.net/contest/441568#problem/B
思路：用kmp算发求出字符串的next数组，在从前面和后面匹配相同字段，在从中间和前面匹配相同字段，且中间字段不能去前面的字段重合
*/
//代码实现
#include<stdio.h>
#include<string.h>
int next[1000010];
char s[1000010];
void get_next(char s[1000010])
{
    next[0]=-1;
    next[1]=0;
    for(int i=1;s[i]!='\0';i++)
    {
        int k=i;
        int t=next[i];
        while(s[t]!=s[i])
        {
            k=t;
            t=next[t];
            if(t==-1)
            {
                break;
            }
        }
        next[i+1]=next[k]+1;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        get_next(s);
        int len=strlen(s);
        //for(int i=0;i<len;i++)printf("%d ",next[i]);
        int ans=0;
        for(int i=next[len];i;i=next[i])//从后面找与前面相同的字段
        {
            for(int j=i+i;j<=len-i;j++)//从中间找与前面相同的字段
            {
                if(next[j]>=i)//从中间截取的字段与前面没有重合
                {
                  ans=ans>i?ans:i;//更新
                }
            }
        }
        printf("%d\n",ans);
    }
}
