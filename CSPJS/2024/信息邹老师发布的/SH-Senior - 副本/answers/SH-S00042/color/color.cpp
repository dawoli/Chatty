#include<bits/stdc++.h>
#define N 200005
#define INF 1e13
typedef long long ll;
using namespace std;
ll T,n,a[N];
void n15(){
	ll clr[16],ans=-INF,t;
	fill(clr,clr+16,0);
	while(1){
		bool End=true;
		for(ll i=1;i<=n;i++) if(clr[i]==0) End=false;
		if(End) break;
		t=0;
		for(ll i=1;i<=n;i++)
			for(ll j=i-1;j>=1;j--) if(clr[i]==clr[j]){
				if(a[i]==a[j]) t+=a[i];
				break;
			}
		ans=max(ans,t);
		ll ad=n;
		clr[ad]++;
		while(clr[ad]==2) clr[ad--]=0,clr[ad]++;
	}
	cout<<ans<<endl;
}
void solve(){
	ll ans=0,mx=0;
	for(ll i=1;i<=n;i++){
		;
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>a[i];
		if(n<=15) n15();
	}
	return 0;
}
