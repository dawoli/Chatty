#include<bits/stdc++.h>
using namespace std;
const int N=10019;
int a[N][N];
bool f[N];
int n,m,k;
long long ans=0;
void dfs(int p,long long ans1,int cnt){
	if(cnt==n){
		ans=max(ans,ans1);
		return;
	}
	for(int i=1;i<=n+k;i++){
		if(f[i]==0&&a[p][i]>0){
			f[i]==1;
			int oju=(i<=n);
			dfs(i,ans1+a[p][i],cnt+oju);
			f[i]==0;
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			a[i][j]=-1;
	}
	cin>>n,m,k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int ai;
			cin>>ai;
			int hs=n+i;
			a[j][hs]=ai+c;
			a[hs][j]=ai;
		}
	}
	f[0]=1;
	dfs(0,0,1);
	cout<<ans<<endl;
	return 0;
}
