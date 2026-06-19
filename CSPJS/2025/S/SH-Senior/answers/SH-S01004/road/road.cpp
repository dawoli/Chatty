#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
using i64 = unsigned long long;
class dsu{
	private:
		vector<int> fa;
		int n;
	public:
		dsu(int n):n(n){
			fa = vector<int>(n + 1);
			for(int i = 1; i <= n; i++){
				fa[i] = i;
			}
		}
		int find(int x){
			if(fa[x] == x) return x;
			return fa[x] = find(fa[x]);
		}
		void add(int x , int y){
			x = find(x) , y = find(y);
			if(x == y) return ;
			if(x > y) swap(x , y);
			fa[y] = x;
			return ;
		}
};
int n , m , k;
vector<vector<int>> edge;
vector<int> c;
vector<int> sta;
unsigned long long ans = -1;
i64 kruskal(int x){
	dsu d(n + k);
	i64 ret = 0;
	int sum = 0;
	for(auto &e : edge){
		int w = e[0] , u = e[1] , v = e[2] , id = e[3];
		if(!sta[id]) continue;
		if(d.find(u) == d.find(v)) continue;
//		cout << u << ' ' << v << ' ' << w << endl;
		d.add(u,v);
		ret += w;
		sum++;
		if(sum == x) break;
	}
	return ret;
}
vector<vector<int>> kruskal1(){
	vector<vector<int>> ret;
	dsu d(n);
	for(auto &e : edge){
		int w = e[0] , u = e[1] , v = e[2] , id = e[3];
		if(d.find(u) == d.find(v)) continue;
		d.add(u,v);
		ret.push_back(e);
	}
	return ret;
}
void dfs(int x){
	if(x > k){
		i64 sum = 0;
		int cnt = 0;
		for(int i = 1; i <= k; i++){
			cnt += sta[i];
			sum += sta[i] * c[i];
		}
		sum += kruskal(n + cnt - 1);
		ans = min(ans , sum);
//		cout << ans << endl;
	}
	else{
		sta[x] = 0;
		dfs(x + 1);
		sta[x] = 1;
		dfs(x + 1);
	}
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m >> k;
    sta = c = vector<int>(k + 1);
    for(int i = 1; i <= m; i++){
    	int u , v , w;
    	cin >> u >> v >> w;
    	edge.push_back({w,u,v,0});
	}
	sort(edge.begin(),edge.end());
	edge = kruskal1();
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			int w;
			cin >> w;
			edge.push_back({w,j,i+n,i});
		}
	}
	sort(edge.begin(),edge.end());
	sta[0] = 1;
	dfs(1);
	cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
}
