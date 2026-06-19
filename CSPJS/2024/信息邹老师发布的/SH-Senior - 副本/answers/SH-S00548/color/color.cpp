#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200005,INF=1e9+9;
ll T,n,a[N],r[N],b[N];
ll ans=0,cnt=0;
void dfs(ll ia,ll ir,ll ib){
	if(ia>n){
		cnt=0;
		for(ll i=2;i<ir;++i){
			if(r[i]==r[i-1])cnt+=r[i];
		}
		for(ll i=2;i<ib;++i){
			if(b[i]==b[i-1])cnt+=b[i];
		}
		if(cnt>ans)ans=cnt;
		return;
	}
	r[ir]=a[ia];
	dfs(ia+1,ir+1,ib);
	b[ib]=a[ia];
	dfs(ia+1,ir,ib+1);
}
void solve1(){
	ans=0;
	dfs(1,1,1);
	cout<<ans<<endl;
}
ll f[102][102][102];
void solve2(){
	for(ll i=0;i<=101;++i){
		for(ll j=0;j<=101;++j){
			for(ll k=0;k<=101;++k){
				f[i][j][k]=-INF;
			}
		}
	}
	ll ans=0;
	f[0][0][0]=0;
	for(ll i=1;i<=n;++i){
		for(ll ir=0;ir<=100;++ir){
			f[i][ir][a[i]]=f[i-1][ir][a[i]]+a[i];
		}
		for(ll ib=0;ib<=100;++ib){
			f[i][a[i]][ib]=f[i-1][a[i]][ib]+a[i];
		}
		for(ll ir=0;ir<=100;++ir){
			for(ll ib=0;ib<=100;++ib){
				f[i][a[i]][ib]=max(f[i][a[i]][ib],f[i-1][ir][ib]);
				f[i][ir][a[i]]=max(f[i][ir][a[i]],f[i-1][ir][ib]);
			}
		}
	}
	for(ll ir=1;ir<=100;++ir){
		for(ll ib=1;ib<=100;++ib){
			ans=max(ans,f[n][ir][ib]);
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(ll i=1;i<=n;++i){
			cin>>a[i];
		}
		if(n<=15){
			solve1();
		}
		else if(n<=100){
			solve2();
		}
		else{
			n=n-1;
		}
	}
	return 0;
}
