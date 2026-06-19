#include <cstdio>
#include <cstring>
const int N=5001000;
int nxt[N];
void prepare(char t[])
{
	int len=strlen(t);
	nxt[0]=0;nxt[1]=0;
	int j=0;
	for(int i=1;i<len;i++)
	{
		while(j && t[j]!=t[i]) j=nxt[j];
		if(t[j]==t[i])
		{
			nxt[i+1]=j+1;j++;
		}
		else nxt[i+1]=0;
	}
	/*
	for(int i=1;i<=len;i++)
	{
		printf("%d ",nxt[i]);
	}*/
}
void KMP(char s[],char t[],int id)
{
	prepare(t);
	int lens=strlen(s);
	int lent=strlen(t);
	int j=0;
	for(int i=1;i<lens;i++)
	{
		while(j && t[j]!=s[i]) j=nxt[j];
		if(t[j]==s[i])
		{
			j++;
			if(j==lent)
			{
				pos[id][++pos[id][0]]=i;
			}
		}
	}
}
int main()
{
//	prepare("abacbab");
	int n,q;
	scanf("%d%d\n",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%s",s1[i],s2[i]);
	}
	while(q--)
	{
		scanf("%s%s",t1,t2);
		int len1=strlen(t1);
		int len2=strlen(t2);
		if(len1!=len2)
		{
			printf("0\n");
			continue;
		}
		int start=len1-1;
		for(int i=0;i<len1;i++)
		{
			if(t1[i]!=t2[i])
			{
				start=i;break;
			}
		}
		int end=0;
		for(int i=len1-1;i>=0;i--)
		{
			if(t1[i]!=t2[i])
			{
				end=i;break;
			}
		}
		for(int i=start;i<=end;i++)
		{
			t1[i-start]=t1[i];
		}
		t1[end-start+1]='\0';
		for(int i=start;i<=end;i++)
		{
			t2[i-start]=t2[i];
		}
		t2[end-start+1]='\0';
		for(int i=1;i<=n;i++)
		{
			KMP(s1[i],t1,1);
			KMP(s2[i],t2,2);
			int pos1=1,pos2=1;
			while(pos1<=pos[1][0] && )
		}
		for(int i=0;i<len1;i++)
		{
			t1[i]='\0';
		}
		for(int i=0;i<len2;i++)
		{
			t2[i]='\0';
		}
	}
	return 0;
}
