#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll T,n,a[N][5],cnt[5],p[N],b[N],tot,sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		tot=sum=0; memset(cnt,0,sizeof cnt);
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++) cin>>a[i][j];
		}
		for(ll i=1;i<=n;i++){
			ll maxn=max(a[i][1],max(a[i][2],a[i][3]));
			if(maxn==a[i][1]) cnt[1]++,p[i]=1;
			else if(maxn==a[i][2]) cnt[2]++,p[i]=2;
			else cnt[3]++,p[i]=3;
			sum+=maxn;
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
			cout<<sum<<"\n";
		}
		else if(cnt[1]>n/2){
			for(ll i=1;i<=n;i++){
				if(p[i]==1){
					b[++tot]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
				}
			}
			sort(b+1,b+tot+1);
			for(ll i=1;i<=cnt[1]-n/2;i++){
				sum-=b[i];
			}
			cout<<sum<<'\n';
		}
		else if(cnt[2]>n/2){
			for(ll i=1;i<=n;i++){
				if(p[i]==2){
					b[++tot]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
				}
			}
			sort(b+1,b+tot+1);
			for(ll i=1;i<=cnt[2]-n/2;i++){
				sum-=b[i];
			}
			cout<<sum<<'\n';
		}
		else{
			for(ll i=1;i<=n;i++){
				if(p[i]==3){
					b[++tot]=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
				}
			}
			sort(b+1,b+tot+1);
			for(ll i=1;i<=cnt[3]-n/2;i++){
				sum-=b[i];
			}
			cout<<sum<<'\n';
		}
	}
	return 0;
}
