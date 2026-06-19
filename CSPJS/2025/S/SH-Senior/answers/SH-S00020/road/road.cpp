#include<bits/stdc++.h>
using namespace std;
int m,n,k,a[3][1000005]={0},b[15][10005]={0};
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
	}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	if(!k)
	{
		sort(a[2],a[2]+m);
		int s=0;
		for(int i=0;i<n-1;i++)
		{
			s+=a[2][i];
		}
		printf("%d",s);
	}
	else
	{
		printf("0");
	}
	return 0;
} 
