#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,a[100005][10],dp[105][105][105][205],ans,f[100005],flag;
ll dp1[1005][1005][2]; 
ll tmp1,tmp2,tmp3;
ll tt1,tt2;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--) {
		ans=0;
		tmp1=tmp2=tmp3=0;
		flag=0;
		tt1=tt2=0;
		scanf("%lld",&n);
		if(n>200) {
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=3;j++) {
					scanf("%lld",&a[i][j]);
					if(j==1) f[i]=a[i][1];
					if(a[i][2]!=0||a[i][3]!=0) flag=1;
				} 
			}
			if(flag!=1) {
				sort(f+1,f+1+n);
				for(int i=n;i>n/2;i--) ans+=f[i];
				printf("%lld",ans);
			} else {
				for(int i=0;i<=n/2;i++) {
					for(int j=0;j<=n/2;j++) {
						dp1[i][j][(i+j)%2]=0;
					}
				}
				for(int i=0;i<=n/2;i++) {
					for(int j=0;j<=n/2;j++) {
						int sum=i+j;
						if(sum>=1) {
							tt1=i>=1?dp1[i-1][j][(sum-1)%2]+a[sum][1]:0;
							tt2=j>=1?dp1[i][j-1][(sum-1)%2]+a[sum][2]:0;
						}
						dp1[i][j][sum%2]=max(tt1,tt2);
					//	printf("dp=%lld\n",dp1[i][j][sum%2]);
					}
				}
				printf("%lld\n",dp1[n/2][n/2][n%2]);
			}
		} else {
			for(int i=1;i<=n;i++) {
				scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			}
			for(int x=0;x<=n/2;x++) {
				for(int y=0;y<=n/2;y++) {
					for(int z=0;z<=min(n/2,n-x-y);z++) {
						int i=x+y+z;
						dp[x][y][z][i]=0;
					}
				}
			}
			dp[0][0][0][0]=0;
			for(int x=0;x<=n/2;x++) {
				for(int y=0;y<=n/2;y++) {
					for(int z=0;z<=min(n/2,n-x-y);z++) {
						int i=x+y+z;
						if(i>=1) {
							tmp1=x>=1?dp[x-1][y][z][i-1]+a[i][1]:0;
							tmp2=y>=1?dp[x][y-1][z][i-1]+a[i][2]:0;
							tmp3=z>=1?dp[x][y][z-1][i-1]+a[i][3]:0;
						}
						dp[x][y][z][i]=max(max(tmp1,tmp2),tmp3);
						//printf("x=%d y=%d z=%d dp=%d\n",x,y,z,dp[x][y][z][i]);
						if(x+y+z==n) ans=max(ans,dp[x][y][z][n]);
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
} 
/*

*/
