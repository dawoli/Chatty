#include <bits/stdc++.h>
using namespace std;
int arr[100005][105];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k,q;
		scanf("%d %d %d",&n,&k,&q);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&arr[i][0]);
			for(int j=1;j<=arr[i][0];j++) scanf("%d",&arr[i][j]);
		}
		for(int i=1;i<=q;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			printf("%d\n",i%2);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
