#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1009;
const ll MOD=998244353;
ll n,m,s[N],c[N],f[N];
string ss;
void input(){
	cin>>n>>m;
	cin>>ss;
	for(ll i=1;i<=n;i++){
		if(ss[i-1]=='1'){
			s[i]=1;
		}else{
			s[i]=0;
		}
	}
	for(ll j=1;j<=n;j++){
		cin>>c[j];
	}
	return;
}
void solve2(){
	ll ans=1;
	for(ll i=1;i<=n;i++){
		ans*=i;
		ans%=MOD;
	}
	cout<<ans<<endl;
	return;
}
void solveea(){
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		if(c[i]!=0){
			cnt++;
		}
	}
	if(cnt>=m){
		solve2();
	}else{
		cout<<0<<endl;
	}
	return;
}
bool alle(){
	for(ll i=1;i<=n;i++){
		if(s[i]==0){
			return false;
		}
	}
	return true;
}
void cf(ll kkk){
	for(ll i=20;i>=0;i--){
		f[i]=0;
		if(kkk>=(1<<i)){
			f[i]=1;
			kkk-=(1<<i);
		}
	}
	return;
}
bool check(ll cntt){
	ll cnt=0;
	ll cnt2=0;
	ll failcnt=0;
	for(ll i=1;i<=n;i++){
		if(f[i]==1){
			cnt2++;
		}
		if(f[i]==1 && failcnt<c[i]){
			cnt++;
		}else{
			failcnt++;
		}
	}
	if(cnt2==cntt && cnt>=m){
		return true;
	}else{
		return false;
	}
}
void solvebf(){
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		if(s[i]==1){
			cnt++;
		}
	}
	ll nptn=(1<<n);
	ll ans=0;
	for(ll ptn=0;ptn<nptn;ptn++){
		cf(ptn);
		if(check(cnt)){
			ans++;
		}
	}
	cout<<ans%MOD<<endl;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	input();
	if(alle()){
		solveea();
	}else if(n<=18){
		solvebf();
	}else{
		cout<<0<<endl;
	}
	return 0;
}
