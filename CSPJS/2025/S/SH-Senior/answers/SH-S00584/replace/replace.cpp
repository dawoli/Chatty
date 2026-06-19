#include<bits/stdc++.h>
using namespace std;
int f[505][505],s[505],c[505],cnt[505],sum[505];
char s1[1005][2004],s2[1005][2004],st[5000005],to[50000005],id[200004][2];
map<int,int> mp;
int check(int id,int l1,int l2)
{
	int i,j;
	for(i=1;i+l1-1<=l2;++i)
	{
		for(j=1;j<=l1;++j)
			if(s1[id][j]!=st[i+j-1]||s2[id][j]!=to[i+j-1])
				break;
		if(j>l1)
			return i;
	}
	return -1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,i,j,k,l,id1,id2,ans,t,l1,l2;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;++i)
	{
		if(n<=1000&&q!=1)
			scanf("%s %s",s1[i]+1,s2[i]+1);
		else
		{
			scanf("%s %s",st+1,to+1);
			l=strlen(st+1);
			for(j=1;j<=l;++j)
				if(st[j]=='b')
				{
					id1=j;
					break;
				}
			for(j=1;j<=l;++j)
				if(to[j]=='b')
				{
					id2=j;
					break;
				}
			id[i][0]=id1;
			id[i][1]=id2;
			++mp[id1-id2+n];
		}
	}
	for(i=1;i<=q;++i)
	{
		scanf("%s %s",st+1,to+1);
		if(n<=1000&&q!=1)
		{
			ans=0;
			for(j=1;j<=n;++j)
			{
				l1=strlen(s1[j]+1);
				l2=strlen(st+1);
				t=check(j,l1,l2);
				if(t==-1)
					continue;
				for(k=1;k<t;++k)
					if(st[k]!=to[k])
						break;
				if(k<t)
					continue;
				for(k=t+l1;k<=l2;++k)
					if(st[k]!=to[k])
						break;
				if(k<l2)
					continue;
				++ans;
			}
			printf("%d\n",ans);
		}
		else
		{
			l=strlen(st+1);
			for(j=1;j<=l;++j)
				if(st[j]=='b')
				{
					id1=j;
					break;
				}
			for(j=1;j<=l;++j)
				if(to[j]=='b')
				{
					id2=j;
					break;
				}
			if(mp.count(id1-id2+n))
				printf("%d\n",mp[id1-id2+n]);
			else
				printf("0\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
