#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5+10;
const int INF=0x3f3f3f3f;

int T,n,ljy=0;
int a[MAXN]={};
int dp[MAXN][2]={};
bool v[MAXN]={};//true R-------------false B

int calc() {
	int ret=0;
	for(int i=1;i<=n;i++) {
		for(int j=i-1;j>=0;j--) {
			if(v[i]==v[j]) {
				if(a[i]==a[j]) {
					ret=ret+a[i];
				} 
				break;
			}
		}
	}
	return ret;
}

void dfs(int x) {
	if(x==n+1) {
		int tmp=calc();
		ljy=max(ljy,tmp);
		return ;
	}
	v[x]=true;
	dfs(x+1);
	v[x]=false;
	dfs(x+1);
}

int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n; ljy=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			v[i]=false;
			dp[n][0]=INF; dp[n][1]=INF;
		}
		if(n<=10) {
			dfs(1);
			cout<<ljy<<endl;
			continue;
		}
		else {
			dp[1][1]=0; dp[1][0]=0;
			for(register int i=2;i<=n;i++) {
				for(register int j=i-1;j>=1;j--) {
					if(a[j]==a[i]) {
						dp[i][0]=min(dp[i][0],dp[j][0]+a[i]);
						for(register int l=j+1;l<=i-1;l++) {
							dp[i][0]=min(dp[i][0],dp[l][1]+a[i]);
						}
						dp[i][0]=dp[i][0];
						
						dp[i][1]=min(dp[i][0],dp[j][1]+a[i]);
						for(register int l=j+1;l<=i-1;l++) {
							dp[i][1]=min(dp[i][1],dp[l][0]+a[i]);
						}
						dp[i][1]=dp[i][1];
					}
				}
			}
			ljy=max(dp[n][1],dp[n][0]);
			cout<<ljy<<endl; 
		}
	}
	return 0;
}
