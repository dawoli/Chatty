#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll c=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		c=(c<<1ll)+(c<<3ll)+(ch^48ll);
		ch=getchar();
	}
	return c*f;
}
inline void write(ll x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
const ll N=100009;
ll n,a[N][3];
vector<ll> bin[3];
ll sum[3];
void solve(){
	n=read();
	for(ll j=0;j<3;j++){
		sum[j]=0;
		bin[j].clear();
	}
	for(ll i=1;i<=n;i++){
		ll mx=-1,id=-1;
		for(ll j=0;j<3;j++){
			a[i][j]=read();
			if(a[i][j]>mx){
				mx=a[i][j];
				id=j;
			}
		}
		bin[id].emplace_back(i);
		sum[id]+=a[i][id];
	}
	ll lmt=n/2;
	if(bin[0].size()<=lmt&&bin[1].size()<=lmt&&bin[2].size()<=lmt){
		write(sum[0]+sum[1]+sum[2]),puts("");
		return;
	}
	ll id=-1;
	for(ll j=0;j<3;j++){
		if(bin[j].size()>lmt) id=j;
	}
	ll nd=(ll)bin[id].size()-lmt;
	multiset<ll> s;
	for(ll u:bin[id]){
		ll smx=-1;
		for(ll j=0;j<3;j++){
			if(j==id) continue;
			smx=max(a[u][j],smx);
		}
		s.insert(a[u][id]-smx);
	}
	ll ans=sum[0]+sum[1]+sum[2];
	auto it=s.begin();
	for(ll i=1;i<=nd;i++){
		ans-=*it;
		it++;
	}
	write(ans),puts("");
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T=read();
	while(T--){
		solve();
	}
	return 0;
}

