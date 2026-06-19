#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=100005;
ll n,a[N][4],b[N],cnt[4],d[4][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		cin>>n;
		cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
		ll ans=0;
		for(ll i=1;i<=n;++i){
			b[i]=1;
			for(ll j=1;j<=3;++j){
				cin>>a[i][j];
				if(a[i][j]>a[i][b[i]]){
					b[i]=j;
				}
			}
			cnt[b[i]]++;
			ans+=a[i][b[i]];
			ll Num=0;
			for(ll j=1;j<=3;++j)if(j!=b[i]){
				Num=max(Num,a[i][j]);
			}
			d[b[i]][cnt[b[i]]]=a[i][b[i]]-Num;
		}
		for(ll j=1;j<=3;++j){
			if(cnt[j]>n/2){
				sort(d[j]+1,d[j]+1+cnt[j]);
				for(ll k=1;k<=cnt[j]-n/2;++k){
					ans-=d[j][k];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
