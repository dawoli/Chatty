#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[100005], c[100005], k, t, b[100005], x[5], w[200005], bn, ans=0;
string s[20];
void run(int p){
	ll z=__lg(p);
	if(z==k){w[p]=p+1-(1ll<<z); return;}
	run(2*p);
	run(2*p+1);
	if(s[k-z][p-(1ll<<z)]==0){
		if(b[w[2*p]]>=k-z){
			w[p]=w[2*p];
		}
		else w[p]=w[2*p+1];
	}
	else{
		if(b[w[2*p+1]]>=k-z){
			w[p]=w[2*p+1];
		}
		else w[p]=w[2*p];
	}
	return;
}
int main(){
	freopen("arena.in","r",stdin); freopen("arena.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	k=__lg(n);
	if(n>(1ll<<k)){k++;} 
	bn=(1ll<<k);
	for(ll i=1; i<=n; i++) cin>>a[i];
	for(ll i=1; i<=m; i++) cin>>c[i];
	for(ll i=1; i<=k; i++){cin>>s[i];}
	cin>>t;
	for(ll task=1; task<=t; task++){
		ans=0;
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(ll i=1; i<=n; i++){b[i]=a[i]^(x[i%4]);}
		run(1);
		for(int i=1; i<=m; i++){
			ans^=(w[1<<(k-__lg(c[i]))]*i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//直接写大模拟吧 
