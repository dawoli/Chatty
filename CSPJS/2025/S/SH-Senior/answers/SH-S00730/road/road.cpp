#include <bits/stdc++.h>
using namespace std;
long long n,m,k,tot = 0,fa[10010];
struct edge{long long u,v,w;}e[3000010];
bool cmp(edge a,edge b){return a.w < b.w;}
int getf(int x){
	if (x == fa[x]) return fa[x];
	else return fa[x] = getf(fa[x]);
}
bool check(){
	for (int i = 1;i < n;i++){
		if (getf(i) != getf(i+1)) return 0;
	}
	return 1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i++) fa[i] = i;
	for (int i = 1;i <= m;i++){
		long long u,v,w;
		cin >> u >> v >> w;
		e[tot++] = (edge){u,v,w};
		e[tot++] = (edge){v,u,w};
	}
	for (int i = 1;i <= k;i++){
		long long x;
		cin >> x;
		for (int j = 1;j <= n;j++){
			long long w;
			cin >> w;
			e[tot++] = (edge){i+n,j,x+w};
			e[tot++] = (edge){j,i+n,x+w};
		}
	}
	sort(e,e+tot,cmp);
	long long ans = 0;
	for (int len = n - 1;len <= n + k - 1;len++){
		long long tmp = 0,cnt = 0;
		for (int i = 0;i < tot && cnt < len;i++){
			long long u = e[i].u,v = e[i].v,w = e[i].w;
			if (getf(u) != getf(v)){
				fa[getf(u)] = getf(v);
				tmp += w;
				cnt++;
			}
		}
		ans = max(ans,tmp);
	}
	cout << ans;
}
