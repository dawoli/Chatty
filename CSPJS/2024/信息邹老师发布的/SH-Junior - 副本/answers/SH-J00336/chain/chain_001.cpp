#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=2e5+10;
int T;
int n,k,q;
vector<vector<int>> s;
int vis[N][110];
inline void solve(){
	s.clear();
	cin>>n>>k>>q;
	for(ll i=1;i<=n;i++){
		ll l;
		cin>>l;
		vector<int> vec;
		for(ll j=1;j<=l;j++){
			int x;
			cin>>x;
			vec.push_back(x);
		}
		s.push_back(vec);
	}
	for(auto vec:s)
		for(ll i=0;i<=vec.size();i++){
			if(vec[i]==1){
				for(ll j=1;j<=k-1;j++){
					if(i+j>=vec.size())
						break;
					vis[vec[i+j]][1]=1;
				}
			}
		}
	while(q--){
		ll r,c;
		cin>>r>>c;
		cout<<vis[c][r]<<endl;
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>T;
	while(T--)
		solve();
	return 0;
}
