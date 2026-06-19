#include<bits/stdc++.h>
using namespace std;
int vis[200005]; 
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,n,k,q,a,l;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d %d %d",&n,&k,&q);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&l);
			for(int i=1;i<=l;i++)
			{
				scanf("%d",&a);
				vis[a]=1;
			}
		}
		for(int i=1;i<=q;i++)
		{
			scanf("1 %d",&a);
			printf("%d\n",vis[a]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
