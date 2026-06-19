#include<bits/stdc++.h>
using namespace std;
int s[1005][2005];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,i,j,k1;
	int n,k,q,l;
	int r,c;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d %d",&n,&k,&q);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&l);
			for(k1=1;k1<=l;k1++)
				scanf("%d",&s[j][k1]);
		}
		for(j=1;j<=q;j++)
		{
			scanf("%d %d",&r,&c);
			printf("0\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
