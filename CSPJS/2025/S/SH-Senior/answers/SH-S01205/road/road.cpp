#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int u,v,c,town;
	bool operator > (const edge x) const{
		return c > x.c;
	}
};
const int N = 2e5+5,K = 15;
int n,m,k;
int c[K],cost[K][N],fa[N];
vector<edge> edges;
bool cmp(edge x,edge y){
	return x.c < y.c;
}
int fnd(int a){
//	cout << 1;
	if(fa[a] == a) return a;
	fa[a] = fnd(fa[fa[a]]);
	return fa[a];
}
void mkpir(int a,int b){
	int faa = fnd(a),fab = fnd(b);
	fa[faa] = fab;
	return;
}
priority_queue<edge,vector<edge>,greater<edge>> pq;
void newton(int x){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < i;j++){
			pq.push({i,j,cost[x][i]+cost[x][j],0});
		}
	}
}
int kruskal(){
	int ans = 0,cnt = 0;
	for(auto j:edges) pq.push(j);
	for(int i = 1;i <= n;i++) fa[i] = i;
	while(cnt < n - 1){
		auto head = pq.top();pq.pop();
		if(fnd(head.u) != fnd(head.v)){
//			cout << head.u << head.v;
//			cout << fnd(head.u) << fnd(head.v);
			mkpir(head.u,head.v);
//			cout << fnd(head.u) << fnd(head.v);
			cnt++;
			ans += head.c;
			if(head.town){
				newton(head.town);
			}
//			return 0;
		}
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);//Don't forget freopen(stdin)!
	freopen("road.out","w",stdout);//Don't forget freopen(stdout)!
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int u,v,c;
		cin >> u >> v >> c;
		pq.push({u,v,c,0});
	}
	
	for(int q = 1;q <= k;q++){
		cin >> c[q];
		for(int i = 1;i <= n;i++){
			cin >> cost[q][i];
			for(int j = 1;j < i;j++)
				edges.push_back({i,j,cost[q][i]+c[q]+cost[q][j],q});
		}
	}
//	sort(edges.begin(),edges.end());
	cout << kruskal();
	return 0;
}

