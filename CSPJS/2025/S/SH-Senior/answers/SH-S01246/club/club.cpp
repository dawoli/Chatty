#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll biao=1e6+10;
ll a[biao][3],n,cnt[3],c[biao],b[biao][3],num[biao];

bool cmp(ll x1,ll x2){
	return x1>x2;
}

void solve(){
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	cnt[0]=cnt[1]=cnt[2]=0;
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll mx=0,loc=0;
		for(ll j=0;j<3;j++) if(a[i][j]>mx) mx=a[i][j],loc=j;
		c[i]=loc,ans+=mx;
		ll mx1=0;
		for(ll j=0;j<3;j++){
			if(j==loc) continue;
			mx1=max(mx1,a[i][j]);
		}
		b[++cnt[loc]][loc]=mx1-a[i][loc];
	}
	if(max(cnt[0],max(cnt[1],cnt[2]))<=n/2){
		cout<<ans<<'\n';
		return;
	}
//	cout<<ans<<'\n';
	ll aim=0;
	for(ll j=0;j<3;j++) if(cnt[j]>n/2) aim=j;
	for(ll i=1;i<=cnt[aim];i++) num[i]=b[i][aim];
	sort(num+1,num+cnt[aim]+1);
	while(cnt[aim]>n/2) ans+=num[cnt[aim]],cnt[aim]--;
	cout<<ans<<'\n';
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--) solve();
	
	return 0;
}
