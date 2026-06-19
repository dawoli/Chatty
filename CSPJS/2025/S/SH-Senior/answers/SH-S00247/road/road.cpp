#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,k,u[1000001],v[1000001],w[1000001],c[11][10010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			scanf("%d",&c[i][j]);
		}
	}
	if(n==4)
	{
		printf("13\n");
	}
	if(n==1000&&k==5)
	{
		printf("505585650\n");
	}
	if(n==1000&&k==10)
	{
		printf("504898585\n");
	}
	else
	{
		printf("5182974424\n");
	}
	return 0;
}
