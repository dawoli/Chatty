#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 998244353;
int n,m,t;
string s;
int c[520];//耐心为i的人数 
ll ans;

ll f(ll a){//阶乘
	if(!a)return 1;
	ll r = a*f(a-1);
	return r%MOD;
}


int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int delta = 0;
	cin>>s;
	for(int ix=0;ix<n;ix++){
		cin>>t;
		t = max(0,t-delta);
		if(!t)delta++;
		else cout<<t<<' '<<delta<<'\n';
		c[t]++;
	};
	ans = f(n-delta);
	cout<<ans<<'\n';
	return 0;
}
