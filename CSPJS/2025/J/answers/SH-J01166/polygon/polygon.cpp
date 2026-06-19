#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N=5e3+10;
const int mod=998244353;
int a[N];
bool special_a=true;
ll ans, f[N], inv_f[N];

ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res = res*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return res;
}

void get_f(int n){
	f[0]=1;
	for(int i=1;i<=n;i++) f[i]=f[i-1]*i%mod;
	inv_f[n] = qpow(f[n], mod-2);
	for(int i=n-1;i>=0;i--) inv_f[i] = inv_f[i+1] * (i+1) % mod;
}

ll C(ll n,ll m){
	if(m<0 || m>n) return 0;
	else return f[n] * inv_f[m] %mod * inv_f[n-m] %mod;
}

void dfs(int loc,int choose, int sum, int aim){
	if(loc == aim+1) return;
	if(sum > a[aim] && choose>=2){
		int res=1;
		for(int i=loc;i<aim;i++) res = res*2%mod;
		ans = (ans+res)%mod;
		return;
	} 
	dfs(loc+1, choose+1, sum+a[loc], aim);
	dfs(loc+1, choose, sum, aim);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) special_a=false;
	}
	
	if(special_a){
		get_f(n);
		for(int i=3;i<=n;i++){
			ans = (ans + C(n,i))%mod;
		}
		cout<<ans<<'\n';
	}
	else{
		sort(a+1, a+n+1);
		for(int i=3;i<=n;i++){
			dfs(1, 0, 0, i);
		}
	
		cout<<ans<<'\n';
	}
	
	return 0;
}
