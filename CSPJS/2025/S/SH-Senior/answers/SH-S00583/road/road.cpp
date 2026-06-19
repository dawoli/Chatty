#include <bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>> q[100001];
int val[100001],vis[100001],n,m,k;
long long ans=0x3f3f3f3f3f3f3f3f;
void dfs(int u,long long sum,int cnt){
	//cout << u << ' ' << sum << '\n';
	if(cnt==4){
		ans=min(ans,sum);
		return;
	}
	for(auto &it:q[u]){
		if(vis[it.first]==1) continue;
		vis[it.first]=1;
		if(it.first>n){
			dfs(it.first,sum+val[it.first]+it.second,cnt);
			vis[it.first]=0;
		}else{
			dfs(it.first,sum+it.second,cnt+1);
			vis[it.first]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		q[u].push_back({v,w});
		q[v].push_back({u,w});
	}
	for(int i = 1;i <= k;i++){
		int w;
		cin >> w;
		val[n+i]=w;
		for(int j = 1;j <= n;j++){
			cin >> w;
			q[n+i].push_back({j,w});
			q[j].push_back({n+i,w});
		}
	}
	vis[1]=1;
	dfs(1,0,1);
	cout << ans;
	return 0;
}
