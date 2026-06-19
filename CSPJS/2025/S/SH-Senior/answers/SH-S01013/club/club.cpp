#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
ll T,n,d[N],a[N],b[N],c[N],cnt[4],ans;
vector<ll> data[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		//clear
		n=ans=0;
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(cnt,0,sizeof(cnt));
		data[1].clear(); data[2].clear(); data[3].clear();
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]) {
				cnt[1]++;
				d[i]=min(a[i]-b[i],a[i]-c[i]);
				ans+=a[i];
				data[1].push_back(d[i]);
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				cnt[2]++;
				d[i]=min(b[i]-a[i],b[i]-c[i]);
				ans+=b[i];
				data[2].push_back(d[i]);
			}
			else{
				cnt[3]++;
				d[i]=min(c[i]-a[i],c[i]-b[i]);
				ans+=c[i];
				data[3].push_back(d[i]);
			}
		}
		if(cnt[1]>=(n/2)){
			sort(data[1].begin(),data[1].end());
			ll k=cnt[1]-(n/2);
			for(ll i=0;i<k;i++) ans-=data[1][i];
			cout<<ans<<endl;	
		}
		else if(cnt[2]>=(n/2)){
			sort(data[2].begin(),data[2].end());
			ll k=cnt[2]-(n/2);
			for(ll i=0;i<k;i++) ans-=data[2][i];
			cout<<ans<<endl;	
		}
		else if(cnt[3]>=(n/2)){
			sort(data[3].begin(),data[3].end());
			ll k=cnt[3]-(n/2);
			for(ll i=0;i<k;i++) ans-=data[3][i];
			cout<<ans<<endl;	
		}
		else cout<<ans<<endl;
	}
	return 0;
}
