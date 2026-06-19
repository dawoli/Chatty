#include<bits/stdc++.h>
using namespace std;
int visited[200005],c[200005],s[1005][2000];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,i,n,k,q,l,j,r,cnt=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&k,&q);
		cnt=0;
		for(i=0;i<n;++i)
		{
			scanf("%d",&l);
			for(j=0;j<l;++j)
			{
				scanf("%d",&s[i][j]);
				visited[s[i][j]]++;
			}
		}
		for(i=0;i<q;++i)
		{
			scanf("%d %d",&r,&c[i]);
			if(r==1)
			{
				cnt++;
			}
		}
		if(cnt==q)
		{
			for(i=0;i<q;++i)
			{
				if(visited[c[i]])
					printf("1\n");
				else
					printf("0\n");
			}
		}
		else
		{
			for(i=0;i<q;++i)
			{
				if(visited[c[i]])
					printf("0\n");
			}
		}
	}
	return 0;
}
