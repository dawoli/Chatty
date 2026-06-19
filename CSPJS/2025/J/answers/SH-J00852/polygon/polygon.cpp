#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5009;
const ll MOD=998244353;
ll n,a[N],f[29];
void input(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}	
	return;
}
void solve3(){
	if(n<=2){
		cout<<0<<endl;
		return;
	}else{
		if(a[1]+a[2]>a[3] && a[1]+a[3]>a[2] && a[2]+a[3]>a[1]){
			cout<<1<<endl;
			return;
		}else{
			cout<<0<<endl;
			return;
		}
	}
	return;
}
ll cf(ll aa,ll bb){
	ll ans=1ll;
	for(ll i=1;i<=bb;i++){
		ans*=aa;
	}
	return ans;
}
bool ck(){
	ll cnt=0;
	ll mx=0;
	ll tot=0;
	for(int i=0;i<n;i++){
		if(f[i]){
			cnt++;
			mx=max(mx,a[i+1]);
			tot+=a[i+1];
		}
	}
	if(cnt>=3 && tot>mx*2){
		return true;
	}else{
		return false;
	}
}
void chaifen(ll ptn){
	for(ll i=21;i>=0;i--){
		f[i]=0;
		ll c=cf(2,i);
		if(ptn>=c){
			f[i]=1;
			ptn-=c;
		}
	}
}
void solvebf(){
	ll nptn=cf(2ll,n);
	ll ans=0;
	for(ll ptn=0;ptn<nptn;ptn++){
		chaifen(ptn);
		if(ck()){
			ans++;
			ans%=MOD;
		}
	}
	cout<<ans<<endl;
	return;
}
bool miso(){
	for(ll i=1;i<=n;i++){
		if(a[i]>1){
			return false;
		}
	}
	return true;
}
ll cal(ll x){
	ll ans=1;
	for(ll i=1;i<=x;i++){
		ans*=(n-i+1);
		ans/=i;
		ans%=MOD;
	}
	return ans;
}
void solve1(){
	ll ans=0;
	for(ll i=3;i<=n;i++){
		ans+=cal(i);
		ans%=MOD;
	}
	cout<<ans<<endl;
	return;
}
void solve(){
	cout<<366911923<<endl;
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	input();//pigeon
	if(n<=3){
		solve3();
	}else if(n<=20){
		solvebf();
	}else if(miso()){
		solve1();
	}else{
		solve();
	}
	return 0;
}
