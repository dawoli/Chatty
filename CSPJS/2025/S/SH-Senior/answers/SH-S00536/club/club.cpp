#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
struct Node{
	ll a,b,c;
}f[N];
ll diff[N];
ll T,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(ll i=1;i<=n;i++)
			cin>>f[i].a>>f[i].b>>f[i].c;
		ll ans=0,cntA=0,cntB=0,cntC=0;
		for(ll i=1;i<=n;i++){
			ll mx=max(max(f[i].a,f[i].b),f[i].c);
			ans+=mx;
			if(f[i].a==mx) cntA++;
			else if(f[i].b==mx) cntB++;
			else if(f[i].c==mx) cntC++;
		}
		if(cntA<=n/2&&cntB<=n/2&&cntC<=n/2) cout<<ans<<endl;
		else if(cntA>n/2){
			ll k=cntA-n/2,t=0;
			for(ll i=1;i<=n;i++){
				ll mx=max(max(f[i].a,f[i].b),f[i].c);
				if(f[i].a==mx) diff[++t]=min(f[i].a-f[i].b,f[i].a-f[i].c);
			}
			sort(diff+1,diff+1+t);
			for(ll i=1;i<=k;i++)
				ans-=diff[i];
			cout<<ans<<endl;
		}
		else if(cntB>n/2){
			ll k=cntB-n/2,t=0;
			for(ll i=1;i<=n;i++){
				ll mx=max(max(f[i].a,f[i].b),f[i].c);
				if(f[i].b==mx) diff[++t]=min(f[i].b-f[i].a,f[i].b-f[i].c);
			}
			sort(diff+1,diff+1+t);
			for(ll i=1;i<=k;i++)
				ans-=diff[i];
			cout<<ans<<endl;
		}
		else if(cntC>n/2){
			ll k=cntC-n/2,t=0;
			for(ll i=1;i<=n;i++){
				ll mx=max(max(f[i].a,f[i].b),f[i].c);
				if(f[i].c==mx) diff[++t]=min(f[i].c-f[i].a,f[i].c-f[i].b);
			}
			sort(diff+1,diff+1+t);
			for(ll i=1;i<=k;i++)
				ans-=diff[i];
			cout<<ans<<endl;
		}
	}
	return 0;
}
