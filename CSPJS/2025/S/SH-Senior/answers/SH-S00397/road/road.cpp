#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define up(i,a,b) for (ll i=(a);i<=(b);++i)
#define down(i,a,b) for (ll i=(a);i>=(b);--i)
const ll NV=2e4+10;
const ll NE=3e6+10;
const ll INF=1e16;
struct Edge{
	ll u,v,len;
	bool operator <(const Edge &b) const{
		return len<b.len;
	}
} e[NE];
ll nV,nE;
void addEdge(ll u,ll v,ll l) {
	e[++nE]=(Edge){u,v,l};
}
ll nRd,mRd,kRd;
ll fa[NV];
ll fath(ll u) {
	if (fa[u]==u) return u;
	return fa[u]=fath(fa[u]);
}
bool vld[NV]; //第i个点是否被改造 
ll otpt=INF;
ll Kruscal(ll State) {
	ll cnt=nRd-1;
	up(i,1,nV) {
		fa[i]=i;
	}
	up(i,nRd+1,nRd+kRd) {
		vld[i]=(State%2);
		vld[i+kRd]=vld[i];
		State/=2;
		cnt+=2*vld[i];
	}
	ll ans=0;
	up(iE,1,nE) {
		ll u=e[iE].u,v=e[iE].v,l=e[iE].len;
		if (!vld[u] || !vld[v]) continue;
		ll fu=fath(u),fv=fath(v);
		if (fu==fv) continue;
		fa[fu]=fv;
		ans+=l;
		if (ans>=otpt) return otpt;
		--cnt;
		if (cnt==0) break;
	}
	return ans;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>nRd>>mRd>>kRd;
	up(i,1,nRd) {
		vld[i]=true;
	}
	up(i,1,mRd) {
		ll u,v,w;
		cin>>u>>v>>w;
		addEdge(u,v,w);
		addEdge(v,u,w);
	}
	nV=nRd+2*kRd;
	bool flagA=true;
	up(i,nRd+1,nRd+kRd) {
		ll cst;
		cin>>cst;
		if (cst) flagA=false;
		addEdge(i,i+kRd,cst);
		addEdge(i+kRd,i,cst);
		bool fl=false;
		up(j,1,nRd) {
			cin>>cst;
			if (cst==0) fl=true;
			addEdge(i+kRd,j,cst);
			addEdge(j,i+kRd,cst);
		}
		if (!fl) flagA=false;
	}
	sort(e+1,e+nE+1);
	ll maxState=(1<<kRd)-1;
	if (flagA) {
		otpt=Kruscal(maxState);
	} else {
		up(State,0,maxState) {
			otpt=Kruscal(State);
		}
	}
	cout<<otpt<<'\n';
	return 0;
}

