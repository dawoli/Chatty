#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9;
ll n,a[N][3],Cost[N],cnt;
vector<ll> Per[3];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				scanf("%lld",&a[i][j]);
		for(int i=0;i<3;i++) Per[i].clear();
		ll ans=0;
		for(int i=1;i<=n;i++){
			ll mx=0;
			for(int j=0;j<3;j++)
				mx=max(mx,a[i][j]);
			for(int j=0;j<3;j++)
				if(a[i][j]==mx){
					Per[j].push_back(i);
					break;
				}
			ans+=mx;
		}
		cnt=0;
		for(int i=0;i<3;i++)
			if(Per[i].size()>n/2){
				for(int j=0;j<Per[i].size();j++){
					ll p=Per[i][j],mn=1e18;
					for(int k=0;k<3;k++)
						if(k!=i)
							mn=min(mn,a[p][i]-a[p][k]);
					cnt++;Cost[cnt]=mn;
				}
				sort(Cost+1,Cost+1+cnt);
				for(int j=1;j<=Per[i].size()-(n/2);j++)
					ans-=Cost[j];
			}
		cout<<ans<<endl;
	}
	return 0;
}

