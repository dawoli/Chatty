#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 509;
const ll MOD = 998244353;

ll n, m;
char s[N];
ll c[N];

bool s_1(){
	for(ll i=1; i<=n; i++)
		if(s[i]!='1') return 0;
	return 1;
}
ll jc(ll x){
	ll res=1;
	for(ll i=1; i<=x; i++)
		res = (res*x)%MOD;
	return res;
}
ll id[N];

void solve(){
	cout<<jc(n);
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin>>n>>m;
	for(ll i=1; i<=n; i++) cin>>s[i];
	for(ll i=1; i<=n; i++) cin>>c[i];
	
	if(s_1()){
		ll cnt=0;
		for(ll i=1; i<=n; i++)
			if(c[i]>0) cnt++;
		if(cnt<m) cout<<0;
		else solve();
	}
	else{
		ll ans=0;
		for(ll i=1; i<=n; i++) id[i] = i;
		do{
			ll cnt=0, cnt2=0;
			for(ll i=1; i<=n; i++){
				if(cnt>=c[id[i]]) cnt++;
				else if(s[i]=='0') cnt++;
				else cnt2++;
			}
			if(cnt2>=m) ans++;
		}while(next_permutation(id+1, id+n+1));
		cout<<ans;
	}
	
	return 0;
}
