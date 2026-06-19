#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N=5e5+10;
ll n,m,L,V;
pair<ll,ll> c[N];
ll pos[N],vis[N];
inline pair<ll,ll> calc(ll d,ll v,ll a){
	if(a==0){
		if(v>V)
			return {d,L};
		else
			return {-1,-1};
	}
	if(a>0){
		if(v>V)
			return {d,L};
		ll tmp=ceil(1.0*(V*V-v*v)/(2*a));
		if(tmp==1.0*(V*V-v*v)/(2*a))
			tmp++;
		if(tmp>L)
			return {-1,-1};
		else
			return {d+tmp,L};
	}
	if(v<V)
		return {-1,-1};
	ll tmp=d+ceil(1.0*(V*V-v*v)/(2*a));
	if(tmp-d==1.0*(V*V-v*v)/(2*a))
		tmp--;
	return {d,min(L,tmp)}; 
} 
struct Fenwick{
	vector<ll> bit;
	Fenwick(ll n):bit(n+10) {}
	inline ll lowbit(ll x){
		return x&(-x);
	}
	inline void add(ll x,ll k){
		x+=2;
		for(ll i=x;i<bit.size();i+=lowbit(i))
			bit[i]+=k;
	}
	inline ll query(ll x){
		x+=2;
		ll ans=0;
		for(ll i=x;i;i-=lowbit(i))
			ans+=bit[i];
		return ans; 
	}
	inline ll query(ll l,ll r){
		return query(r)-query(l-1);
	}
}t(N*10);
inline void clean(){
	for(ll i=1;i<=n;i++)
		c[i]={0,0},vis[i]=0;
	for(ll i=1;i<=m;i++)
		t.add(pos[i],-1);
}
inline void solve(){
	clean();
	cin>>n>>m>>L>>V;
	bool flag=1;
	for(ll i=1;i<=n;i++){
		ll d,v,a;
		cin>>d>>v>>a;
		c[i]=calc(d,v,a);
		if(a<0)
			flag=0;
	}
	for(ll i=1;i<=m;i++){
		cin>>pos[i];
		t.add(pos[i],1);
	}
	ll ans1=0;
	for(ll i=1;i<=n;i++){
		vis[i]=(t.query(c[i].first,c[i].second)>0);
		ans1+=vis[i];
	}
	cout<<ans1<<" ";
	if(flag){
		if(!ans1)
			cout<<m<<endl;
		else
			cout<<m-1<<endl;
	}
	else{
		ll ans2=0;
		for(ll S=1;S<(1<<m);S++){
			ll cnt=__builtin_popcountll(S);
			if(cnt<=ans2)
				continue;
			for(ll i=0;i<m;i++)
				if(S&(1ll<<i))
					t.add(pos[i+1],-1);
			ll tmp=0,flag=1;
			for(ll i=1;i<=n;i++){
				if(vis[i]!=(t.query(c[i].first,c[i].second)>0)){
					flag=0;
					break;
				}
			}
			for(ll i=0;i<m;i++)
				if(S&(1<<i))
					t.add(pos[i+1],1);
			if(flag)
				ans2=cnt;
		}
		cout<<ans2<<endl;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	ll T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}
