#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=509;
const ll MOD=998244353;
ll n,m,c[N],a[N];
bool b[N];
char ch;
void solve(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>ch,b[i]=(ch=='1');
	for(ll i=1;i<=n;i++) cin>>c[i];
	bool flag=1;
	for(ll i=1;i<=n;i++) if(!b[i]) flag=0;
	for(ll i=1;i<=n;i++) if(!c[i]) flag=0;
	if(m==1){
		if(flag){
			ll ans=1;
			for(ll i=1;i<=n;i++) (ans*=i)%=MOD;
			cout<<ans<<endl;
		}else cout<<0<<endl;
		return;
	}
	for(ll i=1;i<=n;i++) a[i]=i;
	ll ans=0;
	do{
		//for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
		//cout<<endl;
		ll cnt=0;
		for(ll i=1;i<=n;i++)
			if(!b[i]||cnt>=c[a[i]])
				cnt++;
		if(cnt<=n-m) ans++;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans<<endl;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll T=1;
	//cin>>T;
	while(T--) solve();
	return 0;
}

