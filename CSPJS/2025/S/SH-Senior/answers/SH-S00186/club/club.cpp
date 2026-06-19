#include<bits/stdc++.h>
using namespace std;
int a[100005][5],f[1005][1005],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n,i,j;
	while(T--)
	{
		ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			for(j=1;j<=3;++j);
				scanf("%d",&a[j][i]);
		sort(a[1]+1,a[1]+n+1);
		for(i=n;i>=1;--i)
		{
			ans+=a[1][n];
		} 
		printf("%d\n0\n0",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
 } 
