#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<ll,unordered_map<ll,unordered_map<ll,bool> > > vis;

const ll biao=1e5+10;
vector<ll> v[biao];
ll a[biao][2];
ll cnt[2*biao];
ll n,k,q,mx;

void dfs(ll node,ll qian,ll qianpeo){
	if(node>=mx+1) return;
	
	if(vis[node][qian][qianpeo]) return;
	vis[node][qian][qianpeo]=1;
	
	//cout<<node<<" "<<qian<<" "<<qianpeo<<endl;
	
	for(ll i=1;i<=n;i++){
		if(qianpeo==i) continue;
		
		for(ll j=0;j<v[i].size();j++){
			if(v[i][j]==qian){
				for(ll o=2;o<=k;o++){
					if(j+o-1>=v[i].size()) break;
					dfs(node+1,v[i][j+o-1],i);
				}
			}
		}
	}
}

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll pro;
	cin>>pro;
	
	while(pro--){
		cin>>n>>k>>q;
		
		for(ll i=1;i<=n;i++){
			ll l;
			cin>>l;
			
			v[i].clear();
			for(ll j=1;j<=l;j++){
				ll x;
				cin>>x;
				v[i].push_back(x);
			}
		}
		
		mx=0;
		for(ll i=1;i<=q;i++) cin>>a[i][0]>>a[i][1],mx=max(mx,a[i][0]);
		
		vis.clear();
		
		for(ll i=1;i<=n;i++) dfs(0,1,0);
		
		for(ll i=1;i<=q;i++){
			bool ans=0;
			for(ll j=1;j<=n;j++){
				if(vis[a[i][0]][a[i][1]][j]){
					ans=1;
					break;
				}
			}
			
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
