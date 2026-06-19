#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0;
int u[1000001]={0},v[1000001]={0},w[1000001]={0};
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		ans+=w[i];
	}
	printf("%d\n",ans);
	return 0;
}
