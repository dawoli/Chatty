#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+5,M=1e6+5,INF=1e12;
struct city{
	ll to,val;
	bool operator < (const city&x) const{
		return val>x.val;
	}
};
ll n,m,k,ans=INF;
ll c[15],a[15][N];
vector<city> vec[131][N+10];
ll prim(int id,int st,ll use){
	ll res=use;
	priority_queue<city> pq;
	bool vis[N+10]={};
	pq.push({st,0});
	while(!pq.empty()){
		ll now=pq.top().to,nowv=pq.top().val; pq.pop();
		if(vis[now]) continue;
		//cout<<now<<' '<<nowv<<endl;
		vis[now]=1; res+=nowv;
		for(ll i=0;i<vec[id][now].size();i++){
			ll nxt=vec[id][now][i].to,va=vec[id][now][i].val;
			pq.push({nxt,va});
		} 
	}
	return res;
}
void solve2(){
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(ll i=0;i<pow(2,k);i++){
		ll x=0,cnt=0,cpi=i;
		while(cpi){
			cnt++;
			if(i%2==1){
				x+=c[cnt];
				for(ll j=1;j<=n;j++){
					vec[i][j].push_back({n+cnt,a[cnt][j]});
					vec[i][n+cnt].push_back({j,a[cnt][j]});
				}
			}
			cpi/=2;
		}
		ans=min(ans,prim(i,1,x));
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		ll u,v,w; cin>>u>>v>>w;
		for(int j=0;j<=128;j++) vec[j][u].push_back({v,w});
		for(int j=0;j<=128;j++) vec[j][v].push_back({u,w});
	}
	solve2();
	cout<<ans<<endl;
	return 0;
}
