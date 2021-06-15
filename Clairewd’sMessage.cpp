/*
题目：https://vjudge.net/contest/441568#problem/D
思路：题目相当于给出了一个转变字符串和信息字符串，利用信息前缀和后缀kmp匹配，找到最长的匹配长度，未匹配的字符串转变回去放在信息字符串后面，输出信息字符串
*/
//代码实现
#include<stdio.h>
#include<string.h>
int next[1000010];
char s[1000010];
char t[30];
void get_next()
{
    next[0]=0;
    int i=0,j=0;
    int len=strlen(s);
    for(int i=1;i<len;i++)
    {
        j=next[i-1];
        while(j>0&&s[i]!=s[j])
        {
            j=next[j-1];
        }
        if(s[i]==s[j])
        {
            next[i]=j+1;
        }
        else
            next[i]=0;
    }
}
int kmp()
{
    get_next();
    int len=strlen(s);
    int j=0;
    for(int i=(len+1)/2;i<len;i++)
    {
        while(j>0&&t[s[i]-'a']!=s[j])
        {
            j=next[j-1];
        }
        if(t[s[i]-'a']==s[j])
        {
            j++;
        }
    }
    return j;
}
int main()
{
    int y;
    scanf("%d",&y);
    while(y--)
    {
        scanf("%s",t);
        getchar();
        scanf("%s",s);
        int len=strlen(s);
        int sum=kmp();
        int c=len;
        for(int i=sum;i<len-sum;i++)
        {
            s[c++]=strchr(t,s[i])-t+'a';//转回去，strchr函数，在t字符串找到第一次出现s[i]的位置
        }
        s[c]='\0';
        printf("%s\n",s);
    }
}
