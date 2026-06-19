#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
int fa(int l,int r){
	int mid=(l+r)>>1;
	return lowbit(mid);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int> > g;
	int a[100001],b[1000010],c[100001];
	int dp[19][10010];
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n+1;++j){
			cin>>dp[i][j];
			if(dp[i][j]>g.size()){
				g[b[i]].push_back(dp[i][j]);
				g[a[i]].push_back(dp[j][i]);
			}
		}
	}
	for(int i=1;i<=m;++i){
		cin>>a[i]>>b[i]>>c[i];
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	} 
	
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n+1;++j){
			dp[i][j]=max(dp[i][j],max(dp[i-1][j],a[i]));
		}
	}
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n;++j){
			int cnt=g.size();
			for(int k=1;k<=cnt;++k){
				dp[i][k]=max(dp[i-cnt][k],dp[i][cnt-k]);
			}
		}
	} 
	cout<<dp[1][n]<<endl;
	return 0;
}
