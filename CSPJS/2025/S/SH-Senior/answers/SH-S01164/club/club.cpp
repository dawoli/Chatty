#include<bits/stdc++.h>
using namespace std;
int t;
int a[100005][3];
long long f[50005][50005][2],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,i,j,k,l;
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0x00,sizeof(f));
		ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
		}
		k=0;
		for(l=1;l<=n;++l)
		{
			for(i=0;i<=min(l,n/2);++i)
			{
				for(j=0;j<=min(l-i,n/2);++j)
				{
					if(l-i-j>n/2) continue;
					f[i][j+1][k^1]=max(f[i][j][k]+a[l][1],f[i][j+1][k^1]);
					f[i][j][k^1]=max(f[i][j][k]+a[l][2],f[i][j][k^1]);
					f[i+1][j][k^1]=max(f[i][j][k]+a[l][0],f[i+1][j][k^1]);
				}
			}
			k^=1;
		} 
		for(i=0;i<=n/2;++i)
		{
			
			for(j=0;j<=n/2;++j)
			{
				if(n-i-j>n/2) continue;
				ans=max(ans,f[i][j][k]);
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
