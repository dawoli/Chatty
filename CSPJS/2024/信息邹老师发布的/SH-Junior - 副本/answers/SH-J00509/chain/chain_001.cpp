#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+9;
ll n,k,q;
vector<ll> num[N];
vector<ll> pos_1,pos_c; 
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++) num[i].clear();
		for(int i=1;i<=n;i++){
			ll l;cin>>l;
			while(l--){
				ll x;cin>>x;
				num[i].push_back(x);
			} 
		}
		while(q--){
			ll r,c;
			cin>>r>>c;
			bool sucess=false;
			for(int i=1;i<=n&&(!sucess);i++){
				pos_1.clear();
				pos_c.clear(); 
				for(int j=0;j<num[i].size();j++){
					if(num[i][j]==1) pos_1.push_back(j);
					if(num[i][j]==c) pos_c.push_back(j);
				}
				for(int j=0;j<pos_1.size();j++){
					ll lb=upper_bound(pos_c.begin(),pos_c.end(),pos_1[j])-pos_c.begin();
					if(lb==pos_c.size()) continue;
					if(pos_c[lb]-pos_1[j]+1<=k) {
						sucess=1;
						break;
					}
				} 
			}
			if(sucess) cout<<"1\n";
			else cout<<"0\n";
		}
	}
	return 0;
} 
