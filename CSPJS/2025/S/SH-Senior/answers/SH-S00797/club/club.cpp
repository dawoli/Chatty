#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9;
ll n,a[N][3],hd[N],nE,S,T;
struct edge{ll v,w,c,nxt;} e[N*8];
void add(ll u,ll v,ll w,ll c){
	e[++nE]=(edge){v,w,c,hd[u]};
	hd[u]=nE;
	e[++nE]=(edge){u,0,-c,hd[v]};
	hd[v]=nE;
}
ll dst[N],f[N],lst[N];
bool in[N];
queue<ll> q;
bool SPFA(){
	fill(dst+1,dst+n+6,1e18);
	fill(in+1,in+n+5,0);
	fill(f+1,f+n+6,0);
	fill(lst+1,lst+n+6,0);
	while(q.size()) q.pop();
	q.push(S);
	f[S]=1e18;
	dst[S]=0;
	in[S]=1;
	while(q.size()){
		ll u=q.front(); q.pop();
		in[u]=0;
		for(ll i=hd[u];i;i=e[i].nxt) if(e[i].w){
			ll v=e[i].v,w=e[i].w,c=e[i].c;
			if(!in[v]&&dst[v]>dst[u]+c){
				f[v]=min(f[u],w);
				dst[v]=dst[u]+c;
				lst[v]=i;
				q.push(v);
			}
		}
	}
	return dst[T]<=1e17;
}
ll EdmondKarp(){
	ll maxFlow=0,minCost=0;
	while(SPFA()){
		//cout<<f[T]<<endl;
		maxFlow+=f[T],minCost+=f[T]*dst[T];
		for(ll i=T;i!=S;i=e[lst[i]^1].v){
			e[lst[i]].w-=f[T];
			e[lst[i]^1].w+=f[T];
			//cout<<lst[i]<<endl;
			//system("pause");
		}
	}
	return minCost;
}
ll x[N];
void solve(){
	nE=1;
	for(ll i=1;i<=n+5;i++) hd[i]=0;
	cin>>n;
	bool flag=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		add(i,n+1,1,-a[i][0]);
		add(i,n+2,1,-a[i][1]);
		add(i,n+3,1,-a[i][2]);
		if(a[i][1]||a[i][2]) flag=0;
		x[i]=a[i][0];
	}
	if(flag){
		sort(x+1,x+n+1);
		ll ans=0;
		for(ll i=1;i<=n/2;i++) ans+=x[i];
		cout<<ans<<endl;
		return;
	}
	S=n+4,T=n+5;
	for(ll i=1;i<=n;i++) add(S,i,1,0);
	add(n+1,T,n/2,0);
	add(n+2,T,n/2,0);
	add(n+3,T,n/2,0);
	//for(ll i=1;i<=n+5;i++)
	//	for(ll j=hd[i];j;j=e[j].nxt)
	//		cout<<i<<" "<<e[j].v<<" "<<e[j].w<<" "<<e[j].c<<endl;
	cout<<-EdmondKarp()<<endl; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T=1;
	cin>>T;
	while(T--) solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
