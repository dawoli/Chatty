#include<iostream>
#include<utility>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
vector<ll> S[200005];
vector<pair<ll,ll> > g[200005]; //in 2,3 建图存邻接表
bool vis[200005],poll1ans[200005]; //记录是否存在这个数 
ll R[100005],C[100005];
struct Node {
	ll id,last,dep;
};
queue<Node> bfs;
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ll t;
	cin>>t;
	while(t--) {
		ll n,k,q,suml=0;
		cin>>n>>k>>q;
		for(ll i=1;i<=n;i++) {
			ll l;
			cin>>l;
			suml+=l;
			for(;l--;) {
				ll v;
				cin>>v;
				S[i].push_back(v);
				vis[v]=1;
			}
		}
		bool ispoll1=1;
		for(ll i=1;i<=q;i++) {
			cin>>R[i]>>C[i];
			if(R[i]!=1) ispoll1=0;
		
		}
		if(ispoll1) {
			for(ll i=1;i<=n;i++) {
				ll cnt=0;
				for(ll j=0;j<S[i].size();j++) {
					if(S[i][j]==1) cnt=k;
					else if(cnt) poll1ans[S[i][j]]=1;
					if(cnt) cnt--;
				}
			}
			for(ll i=1;i<=q;i++) {
				cout<<poll1ans[C[i]]<<endl;
			}
			continue;
		}
		else {
			for(ll i=1;i<=n;i++) {
				for(ll j=0;j<S[i].size();j++) {
					for(ll m=1;m<k;m++) {
						if(j+m>=S[i].size()) break;
						g[S[i][j]].push_back(make_pair(S[i][j+m],i));
					}
				}
			}
			for(ll i=1;i<=q;i++) {
				ll r=R[i],c=C[i];
				if(!vis[c]) {
					cout<<0<<endl;
					continue;
				}
				else {
					while(!bfs.empty()) bfs.pop();
					bfs.push({1,0,0});
					bool flag=0;
					while(!bfs.empty()) {
						ll id=bfs.front().id,last=bfs.front().last,dep=bfs.front().dep;
						if(dep>r) break;
						if(dep==r&&id==c) {
							flag=1;
							break;
						}
						for(auto edge:g[id]) if(edge.second!=last) bfs.push({edge.first,edge.second,dep+1});
						bfs.pop();
					}
					cout<<flag<<endl;
					continue;
				}
			}
		}
		for(ll i=1;i<=n;i++) {
			while(!g[i].empty()) g[i].pop_back();
			while(!S[i].empty()) vis[S[i][S[i].size()-1]]=0,S[i].pop_back();
		}
	}
	return 0;
}
