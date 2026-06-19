#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum;
int w[20000][20000],a[20][20000];
bool b[20];
int dfs(int step)
{
	printf("%d\n",step); 
	if(step<k)
	{
		int t1;
		t1=dfs(step+1);
		b[step]=true;
		int t2=dfs(step+1);
		b[step]=false;
		return min(t1,t2+a[step][0]);
	}
	int mw[20][20000];
	for(int i=0;i<20000;i++)
		for(int j=0;j<20000;j++)
			mw[i][j]=w[i][j];
	for(int t=0;t<k;t++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(b[t]&&(a[t][i]+a[t][j]<mw[i][j]||mw[i][j]==0))
					mw[i][j]=a[t][i]+a[t][j];
	int sum=0;
	bool bo[n]={true},done=true;
	while(done)
	{
		for(int i=0;i<n;i++)
			if(bo[i]==true)
			{
				int mi[2];
				mi[0]=0;
				for(int j=1;j<n;j++)
					if(bo[j]==false&&mw[i][j]!=0&&(mi[0]==0||mi[0]>mw[i][j]))
					{
						mi[0]=mw[i][j];
						mi[1]=j;
					}
				if(mi[0])
				{
					bo[mi[1]]=true;
					sum+=mi[0];
				}
			}
		done=false;
		for(int i=0;i<n;i++)
			if(bo[i]==false)
				done=true;
	}
	return sum;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		scanf("%d",&w[x][y]);
		w[y][x]=w[x][y];
	}
	for(int i=0;i<k;i++)
	{
		scanf("%d",&a[i][n]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	printf("%d",dfs(0));
	return 0;
}
