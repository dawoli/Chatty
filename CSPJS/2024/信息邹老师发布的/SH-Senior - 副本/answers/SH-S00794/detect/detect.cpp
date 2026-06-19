#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000309;
ll n,m,Len,V,d[N],v[N],a[N],L[N],R[N],cnt[N];
bool calc(ll st,ll v0,ll delt,ll ed,ll f){
	return f*f<v0*v0+2*delt*(ed-st);
}
ll maxst[N],dp[N],p[N];
struct Segment{
	ll l,r,minn;
}tr[4*N];
void build(ll u,ll l,ll r){
	tr[u].l=l; tr[u].r=r;
	if(l==r){
		tr[u].minn=dp[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	tr[u].minn=min(tr[u*2].minn,tr[u*2+1].minn);
}
void modify(ll u,ll pos,ll w){
	if(tr[u].l==tr[u].r){
		tr[u].minn=w;
		return;
	}
	ll mid=(tr[u].l+tr[u].r)>>1;
	if(pos<=mid) modify(u*2,pos,w);
	else modify(u*2+1,pos,w);
	tr[u].minn=min(tr[u*2].minn,tr[u*2+1].minn);
}
ll query(ll u,ll l,ll r){
	if(tr[u].l>r||tr[u].r<l) return 1e9;
	if(l<=tr[u].l&&tr[u].r<=r) return tr[u].minn;
	return min(query(u*2,l,r),query(u*2+1,l,r));
}
void solve(){
	cin>>n>>m>>Len>>V;
	for(ll i=0;i<=Len+20;i++) cnt[i]=0;
	for(ll i=1;i<=n;i++){
		cin>>d[i]>>v[i]>>a[i];
		if(a[i]==0){
			if(v[i]>V) L[i]=d[i],R[i]=Len;
			else L[i]=Len+1,R[i]=Len+1;
		}
		if(a[i]>0){
			ll l=d[i],r=Len,ans=1e9;
			while(r>=l){
				ll mid=(l+r)>>1;
				if(calc(d[i],v[i],a[i],mid,V)) r=mid-1,ans=mid;
				else l=mid+1;
			}
			if(ans==1e9) L[i]=Len+1,R[i]=Len+1;
			else L[i]=ans,R[i]=Len;
		}
		if(a[i]<0){
			if(v[i]<=V) L[i]=Len+1,R[i]=Len+1;
			ll l=d[i],r=Len,ans=1e9;
			while(r>=l){
				ll mid=(l+r)>>1;
				if(calc(d[i],v[i],a[i],mid,V)) l=mid+1,ans=mid;
				else r=mid-1;
			}
			if(ans==1e9) L[i]=Len+1,R[i]=Len+1;
			else L[i]=d[i],R[i]=ans;
		}
	}
	for(ll i=1;i<=m;i++){
		cin>>p[i];
		cnt[p[i]]++;
	}
	for(ll i=1;i<=Len;i++) cnt[i]+=cnt[i-1];
	for(ll i=0;i<=Len;i++) maxst[i]=0;
	ll cntt=0;
	for(ll i=1;i<=n;i++){
		if(cnt[R[i]]>cnt[L[i]-1]){
			maxst[R[i]]=max(maxst[R[i]],L[i]);
			cntt++;
		}
	}
	cout<<cntt<<" ";
	for(ll now=1;now<=Len;now++){
		maxst[now]=max(maxst[now],maxst[now-1]); 
	}
	dp[0]=0;
	for(ll i=1;i<=m+1;i++) dp[i]=1e9;
	build(1,0,m+1);
	p[m+1]=Len+1;
	for(ll i=1;i<=m+1;i++){
		ll l=0,r=i-1,ans=i-1;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(p[mid]>=maxst[p[i]-1]) r=mid-1,ans=mid;
			else l=mid+1;
		}
		dp[i]=query(1,ans,i-1)+1;
		modify(1,i,dp[i]);
	}
	cout<<m+1-dp[m+1]<<"\n";
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--) solve(); 
	return 0;
}
