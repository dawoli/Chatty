#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int T,n;
int a[200001];
int l[200001];
int b[200001];
int c[200001];
int d[1000001];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	for(int j=0;j<T;j++)
	{
		memset(l,-1,sizeof(l));
		int ans=0,cnt=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<n;i++) b[i]=a[i];
		sort(b,b+n);
		c[cnt++]=b[0];
		for(int i=1;i<n;i++) if(b[i]!=b[i-1]) c[cnt++]=b[i];
		for(int i=0;i<cnt;i++) d[c[i]]=i;
		l[d[a[0]]]=0;
		for(int i=2;i<n;i++)
		{
			int idx=0;
			for(int k=0;k<cnt;k++)
			{
				if(k!=d[a[i]]) idx=max(idx,l[k]);
				else if(l[k]!=-1) idx=max(idx,l[k]+a[i]);
			}
			l[d[a[i-1]]]=idx;
			if(a[i]==a[i-1])
			{
				for(int k=0;k<cnt;k++)
				{
					if(l[k]==-1||k==d[a[i]]) continue;
					l[k]=l[k]+a[i];
				}
			}
		}
		for(int i=0;i<cnt;i++) ans=max(ans,l[i]);
		printf("%d\n",ans);
	}
	return 0;
}
