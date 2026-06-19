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
const ll N=509;
const ll MOD=998244353;
ll n,m;
ll x[N],c[N];
ll sum[N],ok[N];
ll p[N];
void solven(){
	bool flag=1;
	for(ll i=1;i<=n;i++){
		if(ok[i]==0){
			flag=0;
			break;
		}
	}
	for(ll i=1;i<=n;i++){
		if(c[i]==0){
			flag=0;
			break;
		}
	}
	if(flag){
		ll ans=1;
		for(ll i=1;i<=n;i++){
			ans=ans*i%MOD;
		}
		cout<<ans<<endl;
	}
	else{
		cout<<"0"<<endl;
	}
}
ll f[(1<<18)][20];
void solve(){
	f[0][0]=1;
	for(ll i=0;i<(1<<n);i++){
		ll now=__builtin_popcount(i)+1;
		for(ll j=1;j<=n;j++){
			if(i&(1ll<<(j-1))) continue;
			ll t=i|(1ll<<(j-1));
			for(ll k=0;k<=now-1;k++){
				if(k<c[j]&&ok[now]){
					f[t][k]=(f[t][k]+f[i][k])%MOD;
				}
				else{
					f[t][k+1]=(f[t][k+1]+f[i][k])%MOD;
				}
			}
		}
	}
	ll ans=0;
	for(ll i=0;i<=n-m;i++){
		ans+=f[(1ll<<n)-1][i];
		ans%=MOD;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	string s; cin>>s;
	s=" "+s;
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+(s[i]-'0');
		ok[i]=s[i]-'0';
	}
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==n){
		solven();
		return 0;
	}
//	if(m==1){
//		solve1();
//		return 0;
//	}
	solve();
	return 0;
}

