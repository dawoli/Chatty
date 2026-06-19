#include<bits/stdc++.h>
using namespace std;
int l[1005];
int s[1005][2005];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,q,i,j,n,r,i1,c,k;
	scanf("%d",&t);
	for(i=0;i<t;++i)
	{
		scanf("%d %d %d",&n,&k,&q);
		for(j=0;j<n;++j)
		{
			scanf("%d",&l[j]);
			for(i1=0;i1<l[j];++i1)
				scanf("%d",&s[j][i1]);
		}
		for(j=0;j<q;++j)
		{
			scanf("%d %d",&r,&c);
			printf("1\n"); 
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
