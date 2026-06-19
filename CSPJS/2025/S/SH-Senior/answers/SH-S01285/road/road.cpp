#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll f[N], n, m, k;
struct r{
	ll u, v, w;
}roads[N];
int get(int x){
	if(f[x] == x) return x;
	else f[x] = get(f[x]);
	return f[x];
}
void merge(int a, int b){
	if(get(f[a]) != get(f[b])){
		f[a] = get(f[b]);
	}
}
bool cmp(r a, r b){
	return a.w < b.w;
}
void initialize(){
	for(int i = 0; i <= n; i++) f[i] = i;
}
int solve(){
	long long cost;
	sort(roads, roads + n, cmp);
	for(int i = 0; i < n; i++){
		if(get(roads[i].u) != get(roads[i].v)) cost += roads[i].w;
	}
	return cost;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	initialize();
	for(int i = 0; i < m; i++){
		cin >> roads[i].u >> roads[i].v >> roads[i].w;
	}
	
	for(int i = 0; i < k; i++){
		int temp;
		cin >> temp;
		for(int i = 0; i < n; i++){
			int temp2;
			cin >> temp2;
		}
	}
	cout << solve() - 1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
