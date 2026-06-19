#include <bits/stdc++.h>
using namespace std;
struct Node{int c,g[10005];}a[15];
int n,m,k,price[1000005][2],u[1000005],v[1000005],w[1000005],ans,mn = 1e9,mnid,gg[1005][1005],vis[10005];
vector <pair <int,int> > G[10005];
vector <int> vec;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k,memset(gg,0x3f,sizeof(gg));
	for (int i = 1;i <= m;i++) scanf("%d%d%d",&u[i],&v[i],&w[i]),G[u[i]].push_back({v[i],w[i]}),G[v[i]].push_back({u[i],w[i]}),price[i][0] = G[u[i]][G[u[i]].size() - 1].second,price[i][1] = 1e18;
	for (int i = 1;i <= k;i++){
		scanf("%d",&a[i].c);
		for (int j = 1;j <= n;j++) scanf("%d",&a[i].g[j]),price[i][1] = min(price[i][1],a[i].g[i] + a[i].c);
	}
	for (int i = 1;i <= m;i++){
		w[i] = min(price[i][0],price[i][1]);
		gg[u[i]][v[i]] = min(gg[u[i]][v[i]],w[i]);
		gg[v[i]][u[i]] = min(gg[v[i]][u[i]],w[i]);
		if (w[i] < mn) mn = w[i],mnid = i;
	}
	vec.push_back(u[mnid]),vis[u[mnid]] = 1,vec.push_back(v[mnid]),vis[v[mnid]] = 1,ans += mn;
	while (vec.size() < n){
		int Mn = 1e9,Mnx = 0,Mny = 0;
		for (int i = 0;i < vec.size();i++){
			int Mmn = 1e9,Mmnid = 0;
			for (int j = 1;j <= n;j++){
				if (!vis[j] && gg[vec[i]][j] < Mmn) Mmn = gg[vec[i]][j],Mmnid = j;
			}
			if (Mmn < Mn) Mn = Mmn,Mnx = i,Mny = Mmnid;
		}
		vec.push_back(Mny),ans += Mn,vis[Mny] = 1;
	}
	cout << ans;
	return 0;
}
