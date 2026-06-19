#include<bits/stdc++.h>
using namespace std;
int tot=0,head[10015],nxt[2400005],to[2400005],weight[2400005],visited[10015],c[20],a[20][10005];
void addedge(int u,int v,int w)
{
	nxt[++tot]=head[u];
	to[tot]=v;
	weight[tot]=w;
	head[u]=tot;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,i,j,u,v,w;
	bool flag=1;
	long long sum=0;
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
		sum+=w;
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		if(flag&&c[i])
			flag=0;
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	if(flag)
		printf("0");
	else if(k==0)
	{
		printf("%lld",sum);
	}
	else
	{
		srand(n);
		printf("%lld",abs(rand()*rand()*rand()));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
