#include<bits/stdc++.h>
using namespace std;
typedef struct dis
{
	int d,v,a;
}DIS,*PDIS;
DIS car[100005];
int p[100005];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T,n,m,L,V;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		int j,k;
		int ans1=0,ans2=0;
		scanf("%d %d %d %d",&n,&m,&L,&V);
		for(j=1;j<=n;j++)
		{
			scanf("%d %d %d",&car[i].d,&car[i].v,&car[i].a);
		}
		for(j=1;j<=m;j++)
		{
			scanf("%d",&p[j]);
		}
		for(j=1;j<=n;j++)
		{
			
		}
		printf("%d %d\n",ans1,ans2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
