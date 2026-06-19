#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double ERR=0.00000001;
ll T;
ll n,m,L,V;
ll d[100009],v[100009],a[100009],p[100009];
ll myceil(ll x,ll y){
	ll res=ceil(x*1.0/y)+1;
	while((res-1)*y>x) res--;
	return res;
}
ll myfloor(ll x,ll y){
	ll res=x*1.0/y+1;
	while(res*y>=x) res--;
	return res;
}
bool ifa0(){
	for(ll i=1;i<=n;i++) if(a[i]!=0) return 0;
	return 1;
}
void solvea0(){
	ll dpos=p[m];
	ll ans=0,cnt=0;
	for(ll i=1;i<=n;i++){
		if(v[i]<=V) continue;
		if(d[i]>dpos) continue;
		ans=1;
		cnt++;
	}
	ans=m-ans;
	printf("%lld %lld\n",cnt,ans);
}
bool ifapos(){
	for(ll i=1;i<=n;i++) if(a[i]<=0) return 0;
	return 1;
}
void solveapos(){
	ll dpos=p[m];
	ll cnt=0,ans=0;
	for(ll i=1;i<=n;i++){
		ll exdpos;
		if(v[i]>V) exdpos=d[i];
		else exdpos=d[i]+myceil((V*V-v[i]*v[i]),2*a[i]);
		if(exdpos>dpos) continue;
		cnt++;
		ans=1;
	}
	ans=m-ans;
	printf("%lld %lld\n",cnt,ans);
}
struct Info{
	ll id,val,tag;
}c[200009];
bool cmp(Info a,Info b){
	return a.id<b.id||a.id==b.id&&a.tag>b.tag;
}
bool vst[100009];
void solve(){
	ll cntexd=0;
	for(ll i=1;i<=n;i++){
		ll l,r;
		if(a[i]>0){
			ll pos;
			if(v[i]>V) pos=d[i];
			else pos=d[i]+myceil((V*V-v[i]*v[i])*1.0,2*a[i]);
			if(pos>p[m]) continue;
			l=lower_bound(p+1,p+m+1,pos)-p;
			r=m;
		}
		else if(a[i]==0){
			if(v[i]<=V) continue;
			if(d[i]>p[m]) continue;
			l=lower_bound(p+1,p+m+1,d[i])-p;
			r=m;
		}
		else if(a[i]<0){
			if(v[i]<=V) continue;
			if(d[i]>p[m]) continue;
			l=lower_bound(p+1,p+m+1,d[i])-p;
			ll pos=d[i]+myfloor(-(V*V-v[i]*v[i])*1.0,-2*a[i]);
			r=lower_bound(p+1,p+m+1,pos)-p;
			while(p[r]>pos) r--;
			if(l>r) continue;
		}
		cntexd++;
		c[2*cntexd-1]=(Info){l,i,1};
		c[2*cntexd]=(Info){r,i,-1};
	}
	sort(c+1,c+2*cntexd+1,cmp);
	ll ans=0;
	ll cnt=0;
	vector<ll> nowin;
	memset(vst,0,sizeof(vst));
	for(ll i=1;i<=2*cntexd;i++){
		if(c[i].tag==-1){
			if(vst[c[i].val]) continue;
			ans++;
			for(ll i=0;i<cnt;i++) vst[nowin[i]]=1;
			cnt=0;
			nowin.clear();
		}
		else{
			cnt++;
			nowin.push_back(c[i].val);
		}
	}
	ans=m-ans;
	printf("%lld %lld\n",cntexd,ans);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
		for(ll i=1;i<=n;i++) scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
		for(ll i=1;i<=m;i++) scanf("%lld",&p[i]);
		if(ifa0()) solvea0();
		else if(ifapos()) solveapos();
		else solve();
	}
	return 0;
}
