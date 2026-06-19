#include<bits/stdc++.h>
using namespace std;
#define MAXN 1003
#define MAXM 2006
char s1[MAXN][MAXM],s2[MAXN][MAXM],t1[MAXM],t2[MAXM];
int n,q;
void solve1()
{
	int len=strlen(t1),lens;
	int i,j,k;
	long ans=0;
	if(len!=strlen(t2))
	{
		printf("0\n");
		return;
	}
	for(i=0;i<len;i++)
	{
		for(j=1;j<=n;j++)
		{
			//printf("cmp: s1_%d - t1_%d\n",j,i);
			lens=strlen(s1[j]);
			for(k=0;k<lens;k++)
			{
				if(t1[i+k]!=s1[j][k]) break;
			}
			if(k<lens)
			{
			//	printf("s1_%d - t1 fail at s1_%d_%d\n",j,j,k);
				continue;
			}
			for(k=0;k<lens;k++)
			{
				if(t2[i+k]!=s2[j][k]) break;
			}
			if(k<lens)
			{
			//	printf("s2_%d - t2 fail at s2_%d_%d\n",j,j,k);
				continue;
			}
			for(k=i+lens;k<len;k++)
			{
				if(t1[k]!=t2[k]) break;
			}
			if(k<len)
			{
			//	printf("t1 - t2 fail at t1_%d\n",k);
				continue;
			}
			//printf("s1_%d - t1 succeed at t1_%d\n",j,i);
			ans++;
		}
		if(t1[i]!=t2[i])
		{
			//printf("t1 - t2 fail at t1_%d\n",i);
			break;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	int i;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%s %s",s1[i],s2[i]);
	}
	for(i=1;i<=q;i++)
	{
		scanf("%s %s",t1,t2);
		solve1();
	}
	return 0; 
}
