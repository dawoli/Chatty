#include <bits/stdc++.h>
#define MOD 998244353
int N,M,p[509],tq[509][509],dp[2][509][509],v[509];
char s[509];
signed main(void) {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&N,&M);
	scanf("%s",s+1);
	for(int i=1;i<=N;i++) {
		int x;scanf("%d",&x);
		v[x]++;
	}
	p[0]=1;
	for(int i=1;i<=N;i++) {
		p[i]=1ll*p[i-1]*i%MOD;
	}
	int op=0;
	dp[op][0][0]=1;
	int num=0,ans=0;
	for(int i=0;i<=N;i++) {
		memset(dp[op^1],0,sizeof(dp[op^1]));
		for(int aa=1;aa<=v[i];aa++) {
			memset(tq,0,sizeof(tq));
			for(int j=0;j<=N;j++) {
				for(int l=0;l<=N;l++) {
					tq[j][l]=(tq[j][l]+dp[op][j][l])%MOD;
					tq[j][l+1]=(tq[j][l+1]+1ll*(j-l)*dp[op][j][l])%MOD;
				}
			}	
			num++;
			for(int j=0;j<=N;j++) {
				for(int l=0;l<=N;l++) {
					dp[op][j][l]=tq[j][l];
				}
			}
		}
		for(int j=0;j<N;j++) {
			if(s[j+1]=='1') {
				for(int k=0;k<=N;k++) {
					dp[op][j+1][k]=(dp[op][j+1][k]+dp[op][j][k])%MOD;
				}
				for(int k=0;k<=N;k++) {
					dp[op^1][j+1][k+1]=(dp[op^1][j+1][k+1]+1ll*(num-k)*dp[op][j][k])%MOD;
				}				
			} else {
				for(int k=0;k<=N;k++) {
					dp[op^1][j+1][k+1]=(dp[op^1][j+1][k+1]+1ll*(num-k)*dp[op][j][k])%MOD;
				}				
				for(int k=0;k<=N;k++) {
					dp[op^1][j+1][k]=(dp[op^1][j+1][k]+dp[op][j][k])%MOD;
				}
			}
		}
		if(i<=N-M) {
			ans=(ans+1ll*dp[op][N][num]*p[N-num])%MOD;
		}
		op^=1;
	}
	printf("%d",ans);
}