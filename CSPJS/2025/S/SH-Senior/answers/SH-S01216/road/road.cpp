#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k;
const ll M = 5e6+9;
const ll N = 5e4+9;
struct Edge{
	ll u, v, len, type;
}edge[M];
ll fa[N];
ll c[20];
ll a[20][N];
bool operator < (const Edge &A, const Edge &B){
	return A.len < B.len;
}
ll get(ll x){
	if(fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}
void merge(ll x, ll y){
	fa[get(x)] = get(y);
}
ll sum = 0, ans = 1e18;
void print(Edge e){
	cout<<"{"<<e.u<<", "<<e.v<<", "<<e.len<<", "<<e.type<<"}";
}
void kruskal(ll state){
	ll edge_cnt = 0;
	ll point_cnt = n; 
	//cout<<"state = "<<state<<"\n";
	sum = 0;
	for(ll i = 1;i<=n+k;i++){
		fa[i] = i;
	}
	for(ll i = 1;i<=k;i++){
		if((1<<(i-1))&state){
			sum+=c[i];
			point_cnt++;
		}
		
	}
	for(ll i = 1;i<=m;i++){
		//print(edge[i]); cout<<"\n";
		if(!(edge[i].type==0 || ((1<<(edge[i].type-1))&state))) continue;
		//cout<<"pass\n";
		ll u = edge[i].u, v= edge[i].v;
		//cout<<"{"<<u<<", "<<v<<", "<<edge[i].len<<"}\n";
		ll get_u = get(u), get_v = get(v);
		if(get_u != get_v){
			//cout<<"merge("<<u<<", "<<v<<")\n";
			merge(u, v);
			sum+=edge[i].len;
			edge_cnt++;
			if(edge_cnt == point_cnt - 1){
				break;
			}
		}
	}
	//cout<<"sum = "<<sum<<"\n";
	ans = min(ans, sum);
	//cout<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin >> n >> m >> k; 
	for(ll i = 1;i<=m;i++){
		cin >> edge[i].u >> edge[i].v >> edge[i].len;
		edge[i].type = 0;
	}
	
	//kruskal();
	for(ll i = 1;i<=k;i++){
		cin >> c[i];
		for(ll j = 1;j<=n;j++){
			cin >> a[i][j];
			m++;
			edge[m].u = n+i;
			edge[m].v = j;
			edge[m].len = a[i][j];
			edge[m].type = i;
		} 
	}
	sort(edge+1, edge+1+m);
	if(k==0){
		kruskal(0);
		cout<<ans<<"\n";
		return 0;
	}
	for(ll i = 0;i<(1<<k);i++){
		kruskal(i);
	} 
	cout<<ans<<"\n";
	return 0;
} 
/*
5 8 0
1 3 6
1 2 3
2 4 5
4 5 7
1 5 6
1 4 10
2 5 12
2 3 4

*/
