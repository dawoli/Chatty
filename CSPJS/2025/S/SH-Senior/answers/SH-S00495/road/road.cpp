#include<bits/stdc++.h>
using namespace std;
#define int long long
int c[15],a[15][10005]; 
struct N{
	int u,v,w;
}E[1000005];
bool cmp(N x,N y){
	return x.w < y.w;
}
int fa[10020];
int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0;i < m;i++){
		cin >> E[i].u >> E[i].v >> E[i].w;
	}
	for(int i = 0;i < k;i++){
		cin >> c[i];
		for(int j = 0;j < n;j++){
			cin >> a[i][j];
		}
	}
	int ans = 2147483647;
	for(int bit = 0;bit < 1 << (k+1);bit++){
		for(int i = 0;i < n+k;i++) fa[i] = i;
		int sum = 0;
		vector<N> t;
		for(int i = 0;i < k;i++){
			if(bit & (1 << i)) {
				sum += c[i];
				for(int uu = 0;uu < n;uu++){
					for(int vv = 0;vv < n;vv++){
						if(uu != vv){
							t.push_back({uu,vv,a[i][uu]+a[i][vv]});
						}
					}
				}
			}
		}
		for(int i = 0;i < m;i++){
			t.push_back(E[i]);
		}
		sort(t.begin(),t.end(),cmp);
		int c = 0;
		for(int i = 0;i < t.size();i++){
			N e = t[i];
			int uu = find(e.u),vv = find(e.v);
			if(uu != vv){
				fa[vv] = uu;
				sum += e.w;
				c++;
			}
			if(c == n-1) break;
		}
		if(sum < ans) ans = sum;
	}
	cout << ans;
}
