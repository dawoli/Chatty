#include<bits/stdc++.h>
using namespace std;

int n,m,k,ans=0;
int r[1000000][3];
int c[10][10001];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&r[i][0],&r[i][1],&r[i][2]);
		ans+=r[i][2];
	}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			scanf("%d",&c[i][j]);
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
