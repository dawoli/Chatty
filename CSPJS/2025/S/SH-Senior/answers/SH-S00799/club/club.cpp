#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9;
ll T;
ll n,a[N][3],ch[N],c[N];
void solve(){
	scanf("%lld",&n);
	ll ans=0,cnt[3]={0,0,0};
	for(ll i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			cnt[0]++;
			ch[i]=0;
			ans+=a[i][0];
		}
		else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
			cnt[1]++;
			ch[i]=1;
			ans+=a[i][1];
		}
		else{
			cnt[2]++;
			ch[i]=2;
			ans+=a[i][2];
		}
	}
	ll del=-1;
	for(ll i=0;i<3;i++) if(cnt[i]>(n/2)) del=i;
	if(del==-1){
		printf("%lld\n",ans);
		return;
	}
	for(ll i=1;i<=n;i++){
		c[i]=1e16;
		if(ch[i]!=del) continue;
		for(ll k=0;k<3;k++)if(k!=del) c[i]=min(c[i],a[i][del]-a[i][k]);
	}
	sort(c+1,c+n+1);
	ll cntdel=cnt[del]-(n/2);
	for(ll i=1;i<=cntdel;i++) ans-=c[i];
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--) solve();
	return 0;
}
