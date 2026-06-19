#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge{
	ll x,y,w;
};

bool cmp(edge x1,edge x2){
	return x1.w<x2.w;
}

const ll biao=1e6+10,biao2=1e5+10;
edge r[biao],r2[biao],r3[biao];
ll fa[biao2],n,m,k,idx,c[biao2],a[20][biao2],ans,sz[biao2];

ll findf(ll x){
	if(x==fa[x]) return x;
	fa[x]=findf(fa[x]);
	return fa[x];
}

void mergem(ll x,ll y){
	x=findf(x),y=findf(y);
	if(x==y) return;
	if(sz[x]>sz[y]) swap(x,y);
	fa[x]=y,sz[y]+=sz[x];
}

void solve(ll num){
	ll ret=0;
	idx=n-1;
	for(ll i=1;i<n;i++) r2[i]=r3[i];
	for(ll i=0;i<k;i++){
		if(num&(1<<i)){
			ret+=c[i+1];
			for(ll j=1;j<=n;j++) r2[++idx]={n+i+1,j,a[i+1][j]};
		}
	}
	sort(r2+1,r2+idx+1,cmp);
	for(ll i=1;i<=n+k;i++) fa[i]=i,sz[i]=1;
	ll cnt=0;
//	cout<<num<<":\n";
	for(ll i=1;i<=idx;i++){
		ll x=r2[i].x,y=r2[i].y;
//		cout<<x<<" "<<y<<" "<<r2[i].w<<'\n';
		x=findf(x),y=findf(y);
		if(x==y) continue;
		mergem(x,y);
		ret+=r2[i].w,cnt++;
	}
//	cout<<num<<" "<<ret<<'\n';
	ans=min(ans,ret);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++) cin>>r[i].x>>r[i].y>>r[i].w;
	sort(r+1,r+m+1,cmp);
	
	for(ll i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	for(ll i=1;i<=m;i++){
		ll x=r[i].x,y=r[i].y;
		x=findf(x),y=findf(y);
		if(x==y) continue;
		mergem(x,y),r3[++idx]=r[i];
	}
//	cout<<idx<<'\n';
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++) cin>>a[i][j];
	}
	
	ans=1e18;
	for(ll i=0;i<(1<<k);i++) solve(i);
	cout<<ans;
	
	return 0;
}
