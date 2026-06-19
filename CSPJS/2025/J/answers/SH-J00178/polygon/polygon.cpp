#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
const ll N=5009;
ll n,a[N],ans;
void solve(){
	for(ll flag=0;flag<=(1<<n)-1;flag++){
		ll ms=0,ss=0;
		for(int i=1;i<=n;i++)
			if(flag&(1<<(i-1)))ms=max(ms,a[i]),ss+=a[i];
		if(ss>ms*2)ans+=1,ans%=MOD;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	if(n<=2)cout<<0;
	else if(n==3)cout<<((a[1]+a[2]+a[3])>2*max(max(a[1],a[2]),a[3]));
	else if(*max_element(a+1,a+1+n)==1)cout<<n-2; //45
	else solve();
	return 0;
}
