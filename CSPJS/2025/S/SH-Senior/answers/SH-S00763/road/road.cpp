#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(ll i=a;i<=b;i++)
#define rrep(i, a, b) for(ll i=a;i>=b;i--)
const ll M=1e6+9, N=1e4+9;
ll n, m, k; 
struct edge{
	ll u, v, w;
	bool operator <(const edge &b){
		return w<b.w;
	}
}e[M];
ll c[19];
ll a[19][N];
ll bcj[N];
void prec(){
	rep(i, 1, n+k)bcj[i]=i;
} 
ll findl(ll u){
	if(bcj[u]==u)return u;
	return bcj[u]=findl(bcj[u]);
}
bool conn(ll u, ll v){
	return (findl(u)==findl(v));
}
void con(ll u, ll v){
	bcj[findl(u)]=findl(v);
}
vector <edge> curedge;
//struct edgeS{
//	ll i, c;
//	bool operator <(const edgeS &b){
//		return c<b.c;
//	}
//};
vector <edge> S[19];
ll res=1e16;
void dfs(ll u, vector <edge> cur, ll excost, ll allcost){
	if(allcost>=res)return;
	if(u==k){
		if(allcost==12){
			cout << excost << endl;
		}
		res=min(res, allcost);
		return;
	}
	//excost是建造乡村的代价， cur是当前的生成树
	dfs(u+1, cur, excost, allcost);//不建造u+1
	//建造u+1
	prec();
	ll i=0, j=0;
	ll ans=excost+c[u+1];
	vector<edge> tmp;tmp.clear();
	while(i<cur.size()||j<S[u+1].size()){
		edge tmpE;
		if(i==cur.size()){
			tmpE=S[u+1][j];j++;
		}else if(j==S[u+1].size()){
			tmpE=cur[i];i++;
		}else if(cur[i].w<S[u+1][j].w){
			tmpE=cur[i];i++;
		}else{
			tmpE=S[u+1][j];j++;
		}
		if(conn(tmpE.u, tmpE.v))continue;
		con(tmpE.u, tmpE.v);ans+=tmpE.w;
		tmp.emplace_back(tmpE);
	} 
	dfs(u+1, tmp, excost+c[u+1], ans);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	rep(i, 1, m){
		ll u, v, w;cin >> u >> v >> w;
		e[i]=(edge){u, v, w};
	}
	prec();
	sort(e+1, e+m+1);
	ll sum=0;
	rep(i, 1, m){
		if(conn(e[i].u, e[i].v))continue;
		con(e[i].u, e[i].v);
		curedge.emplace_back(e[i]);sum+=e[i].w;
	}
	rep(i, 1, k){
		cin >> c[i];
		rep(j, 1, n){
			cin >> a[i][j];
//			S[i][j]=(edgeS){j, a[i][j]};
			S[i].emplace_back((edge){n+i, j, a[i][j]});
		}
		sort(S[i].begin(), S[i].end());
	} 
//	cout << sum << endl;
	dfs(0, curedge, 0, sum);
	cout << res << endl;
	return 0;
}
