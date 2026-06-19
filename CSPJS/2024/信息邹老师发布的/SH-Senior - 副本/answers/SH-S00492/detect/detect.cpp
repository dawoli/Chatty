#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100009;
ll d[N],v[N],a[N],p[N],cnt[N];
set<ll> car[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ll T;
	cin>>T;
	set<ll>::iterator it;
	while(T--){
		ll n,m,L,vsp,c=0;
		cin>>n>>m>>L>>vsp;
		for(ll i=1;i<=n;i++)
			cin>>d[i]>>v[i]>>a[i];
		for(ll i=1;i<=m;i++)
			cin>>p[i];
		for(ll i=1;i<=n;i++){
			bool b=0;
			if(a[i]==0){
				if(v[i]<=vsp)
					continue;
				for(ll j=m;j>=1;j--){
					if(p[j]>=d[i]){
						car[j].insert(i);
						b=1;
					}
					else{
						break;
					}
				}
				if(b)
					c++;
			} 
			else if(a[i]<0){
				if(v[i]<=vsp)
					continue;
				a[i]=-a[i];
				ll dv=v[i]*v[i]-vsp*vsp;
				ll dx=dv/(2*a[i]);
				if(dv%(2*a[i])==0)
					dx++;
				dx+=d[i];
				for(ll j=1;j<=m;j++){
					if(p[j]>=d[i]&&p[j]<=dx){
						car[j].insert(i);
						b=1;
					}
					if(p[j]>dx)
						break;
				} 
				if(b)
					c++;
			}
			else{
				if(v[i]>vsp){
					for(ll j=m;j>=1;j--){
						if(p[j]>=d[i])
							car[j].insert(i),b=1;
						else
							break;
					}
					if(b)
						c++;
					continue;
				}
				ll dv=vsp*vsp-v[i]*v[i];
				ll dx=dv/(2*a[i]);
				dx++;
				dx+=d[i];
				for(ll j=m;j>=1;j--){
					if(p[j]>=dx)
						car[j].insert(i),b=1;
					else
						break;
				}
				if(b)
					c++;
				continue;
			}
		}
		cout<<c<<" ";
		for(ll j=1;j<=m;j++)
			cnt[j]=car[j].size();
		ll sum=0,ans=0;
		while(sum<c){
			ll id=max_element(cnt+1,cnt+m+1)-cnt;
			sum+=cnt[id];
			ans++;
			for(it=car[id].begin();it!=car[id].end();it++){
				ll veh=(*it);
				for(ll j=1;j<=m;j++){
					if(j==id)
						continue;
					if(car[j].count(veh)!=0){
						car[j].erase(veh);
						cnt[j]--;
					}
				}
			}
			car[id].clear();
			cnt[id]=0;
		}
		cout<<m-ans<<endl;
		for(ll i=1;i<=m;i++){
			car[i].clear();
			cnt[i]=0;
		}
	}
	return 0;
}
