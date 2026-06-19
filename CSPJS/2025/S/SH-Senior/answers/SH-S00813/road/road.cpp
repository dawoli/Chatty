#include<bits/stdc++.h>
#define rep(i,a,b)	for(ll i=(a);i<=(b);i++)
#define per(i,a,b)	for(ll i=(a);i>=(b);i--)
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll maxn=10009;
const ll maxm=1000009;
const ll maxk=19;
const ll inf=1e15;
ll n,m,k,nE;
struct Edge{
	ll u,v,w;
	bool operator<(const Edge&x){
		return w<x.w;
	}
}E[maxm],E2[maxm];
ll f[maxn];
ll find(ll x){return (x==f[x]?x:f[x]=find(f[x]));}
void merge(ll u,ll v){
	f[find(u)]=find(v);
}
ll c[maxk],a[maxk][maxn];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	rep(i,1,m){
		ll u,v,w;
		cin>>u>>v>>w;
		E[i]={u,v,w};
	}
	sort(E+1,E+1+m);
	rep(i,1,n)	f[i]=i;
	ll cnt=0;
	rep(i,1,m){
		ll x=find(E[i].u),y=find(E[i].v);
		if(x==y)	continue;
		merge(x,y);
		cnt++,E[cnt]=E[i];
		if(cnt>=n-1)	break;
	}
	m=n-1;
	E[n]={0,0,inf};
	rep(i,1,k){
		cin>>c[i];
		rep(u,1,n){
			cin>>a[i][u];
			E2[++nE]={n+i,u,a[i][u]};
		}
	}
	sort(E2+1,E2+1+nE);
	E2[nE+1]={0,0,inf};
	ll ans=inf;
	rep(p,0,(1<<k)-1){
		ll sum=0,cnt=0,now1=1,now2=1;
		rep(i,0,k-1)
			if((1<<i)&p)
				cnt++,sum+=c[i+1];
		rep(i,1,n+k)	f[i]=i;
		rep(id,1,n+cnt-1){
			Edge edge;
			while(1){
//				cout<<id<<' '<<now1<<' '<<now2<<'\n';
				while(now2<=nE&&!(1<<(E2[now2].u-n-1)&p))
					now2++;
				if(now2>nE||E[now1].w<E2[now2].w)
					edge=E[now1],now1++;
				else edge=E2[now2],now2++;
				if(find(edge.u)!=find(edge.v))	break;
			}
			merge(edge.u,edge.v);
			sum+=edge.w;
		}
		ans=min(ans,sum);
	}
	cout<<ans<<'\n';
	return 0;
}
