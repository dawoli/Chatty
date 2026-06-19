#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll T,n,a[N],ans;
ll que(ll x){
	ll last=-1,res=0;
	for(ll j=0;j<n;j++){
		if((x>>j)&1){
			if(last==-1){
				last=j;
				continue;
			}
			if(a[last]==a[j])res+=a[j];
			last=j;
		}
	}
	return res;
}
void solve1(){
	for(ll i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(ll i=0;i<(1<<n);i++){
		ans=max(ans,que(i)+que(~i));
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		ans=0;
		scanf("%lld",&n);
		if(n<=15){
			solve1();
			continue;
		}
		solve1();
	}
	return 0;
}

