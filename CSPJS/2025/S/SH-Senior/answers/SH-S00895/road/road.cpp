#include<bits/stdc++.h>
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define down(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll INF=1e15;
const ull BASE=240441620163;
void file(){
	 freopen("road.in","r",stdin);
	 freopen("road.out","w",stdout);
}
//本人最后一个赛季，祭~
//感谢八年来OI带来的欢乐，以及不一样的人生经历~ 
const ll M=2000009;
struct Edge{
	int u,v;
	ll w;
	int spj;
}e[M],ec[M];
int n,nE,k;
ll c[109];
int nV,nEc=0,vst[M];
bool cmp(const Edge&a,const Edge&b){
	return a.w<b.w;
}
void input(){
	scanf("%d%d%d",&n,&nE,&k);
	rep(i,1,nE){
		int u,v; ll w; scanf("%d%d%lld",&u,&v,&w);
		e[i]=(Edge){u,v,w,0};
	}
	nV=n;
	rep(i,1,k){
		nV++; cin>>c[i];
		rep(j,1,n){
			ll w; cin>>w;
			e[++nE]=(Edge){j,n+i,w,i};
		}
	}
}
ll reform[109];
int id[M];
ll ans=INF;
ll find(ll x){
	return x==id[x]?x:id[x]=find(id[x]);
}
void dfs(ll now){
	if(now==k+1){
		ll res=0;
		rep(i,1,k)if(reform[i])res+=c[i];
		rep(i,1,nV)id[i]=i;
		rep(i,1,nE){
			ll u=e[i].u,v=e[i].v,w=e[i].w;
			if(e[i].spj!=0&&reform[e[i].spj]==0)continue;
			ll fu=find(u),fv=find(v);
			if(fu==fv)continue;
			id[fu]=fv; res+=w;
		}
		ans=min(ans,res);
		return;
	}
	reform[now]=1;
	dfs(now+1);
	reform[now]=0;
	dfs(now+1);
}
void solveBF(){
	sort(e+1,e+1+nE,cmp);
	dfs(1);
	printf("%lld\n",ans);
}
void solve(){
	sort(e+1,e+1+nE,cmp);
	rep(i,1,nV)id[i]=i;
	int nEp=0;
	rep(i,1,nE){
		if(e[i].spj!=0){
			e[++nEp]=(Edge){e[i].u,e[i].v,e[i].w,e[i].spj};
			continue;
		}
		int u=e[i].u,v=e[i].v;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		id[fu]=fv; 
		e[++nEp]=(Edge){e[i].u,e[i].v,e[i].w,e[i].spj};
	}
	nE=nEp;
	rep(iPt,0,(1LL<<k)-1){
		ll res=0;
		rep(i,1,k)if((iPt>>(i-1))&1)res+=c[i];
		rep(i,1,nV)id[i]=i;
		rep(i,1,nE){
			ll u=e[i].u,v=e[i].v,w=e[i].w;
			if(e[i].spj!=0&&((iPt>>(e[i].spj-1))&1)==0)continue;
			ll fu=find(u),fv=find(v);
			if(fu==fv)continue;
			id[fu]=fv; res+=w;
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
}
int main(){
	file();
	input();
	if(k<=5)
		solveBF();
	else
		solve();
	return 0;
}


