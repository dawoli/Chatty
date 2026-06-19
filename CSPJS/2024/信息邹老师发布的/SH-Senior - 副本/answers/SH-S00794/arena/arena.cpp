#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10009;
ll n,m,c[N],na[N],x[4],a[N];
ll calc(ll x){
	ll k=0;
	while((1<<k)<x) k++; 
	return k;
}
char d[18][N];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>na[i];
	for(ll i=1;i<=m;i++) cin>>c[i];
	ll k=calc(n);
	for(ll i=1;i<=k;i++){
		for(ll j=1;j<=(1<<(k-i));j++) cin>>d[i][j];
	}
	int t; cin>>t;
	cin>>x[0]>>x[1]>>x[2]>>x[3];
	for(ll i=1;i<=n;i++) a[i]=(na[i]^x[i%4]);
	ll res=0;
	for(ll i=1;i<=m;i++){
		ll now=calc(c[i]);
		vector<pair<ll,ll> > query; 
		query.push_back(make_pair(1e18,-1e18));
		for(ll j=1;j<=(1<<now);j++){
			if(j<=c[i]) query.push_back(make_pair(a[j],a[j]));
			else query.push_back(make_pair(0,(1ll<<31)-1));
		}
		for(ll i=1;i<=now;i++){
			for(ll j=1;j<=(1<<(now-i));j++){
				if(d[i][j]=='0'){
					for(ll k=(j-1)*(1<<i)+1;k<=(j-1)*(1<<i)+(1<<(i-1));k++){
						if(query[k].second>=query[k].first&&query[k].first>=i){
							for(ll k=(j-1)*(1<<i)+(1<<(i-1))+1;k<=j*(1<<i);k++) query[k]=make_pair(1e18,-1e18);
						}
						else if(query[k].second>=query[k].first&&query[k].second<i) query[k]=make_pair(1e18,-1e18);
						else{
							query[k].first=max(query[k].first,i);
						}
					} 
					
				}
				if(d[i][j]=='1'){
					for(ll k=(j-1)*(1<<i)+(1<<(i-1))+1;k<=j*(1<<i);k++){
						if(query[k].second>=query[k].first&&query[k].first>=i){
							for(ll k=(j-1)*(1<<i)+1;k<=(j-1)*(1<<i)+(1<<(i-1));k++) query[k]=make_pair(1e18,-1e18);
						}
						else if(query[k].second>=query[k].first&&query[k].second<i) query[k]=make_pair(1e18,-1e18);
						else{
							query[k].first=max(query[k].first,i);
						}
					} 
				}
			}
		}
		ll cnt=0;
		for(ll i=1;i<query.size();i++){
			if(query[i].first<=query[i].second){
				cnt+=i;
			}
		}
//		cout<<i<<" "<<cnt<<endl;
		res^=(i*cnt); 
	}
	cout<<res<<endl;
	return 0;
}
