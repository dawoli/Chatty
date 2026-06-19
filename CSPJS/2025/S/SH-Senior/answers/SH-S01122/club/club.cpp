#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int N=210;
int a[100100][4];
int dp[N][N][N];
struct node
{
	int x,y,z,ma,id;
};
node aa[100100];
int cnt[10];
int cmp(node a,node b)
{
	return (a.ma>b.ma);
}
int max(int a,int b)
{
	return (a > b) ? a : b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int ok=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0 || a[i][3]!=0) ok=0; 
		}
		if(n<=200)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=i;j++)
				{
					for(int k=0;j+k<=i;k++)
					{
						int l=i-j-k;
						dp[j][k][l]=0;
						if(j>0) dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[i][1]);
						if(k>0) dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+a[i][2]);
						if(l>0) dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[i][3]);
					}
				}
			}
			int ans=0;
			for(int j=0;j<=n;j++)
			{
				for(int k=0;j+k<=n;k++)
				{
					int l=n-j-k;
					if(j>n/2 || k>n/2 || l>n/2) continue;
					ans=max(ans,dp[j][k][l]); 
				}
			}
			printf("%d\n",ans);
		}
		else if(ok==1)
		{
			for(int i=1;i<=n;i++)
			{
				aa[i].x=a[i][1];
				aa[i].y=a[i][2];
				aa[i].z=a[i][3];
				if(a[i][1]>a[i][2] && a[i][1]>a[i][3])
				{
					aa[i].ma=a[i][1];
					aa[i].id=1;
				}
				else if(a[i][2]>=a[i][1] && a[i][2]>a[i][3])
				{
					aa[i].ma=a[i][2];
					aa[i].id=2;
				}
				else
				{
					aa[i].ma=a[i][3];
					aa[i].id=3;
				}
			}
			sort(aa+1,aa+1+n,cmp);
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(cnt[aa[i].id]==n/2)
				{
					
				}
				else
				{
					cnt[aa[i].id]++;
					ans+=aa[i].ma;
				}
			}
			printf("%d\n",ans);
		}
		else
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				ans+=max(max(a[i][1],a[i][2]),a[i][3]);
			}
			printf("%d\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
