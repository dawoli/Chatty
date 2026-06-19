#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,m,k,xz,yz,dz;
char c[1005][1005];
set<pair<ll,ll>>key;
pair<ll,ll> con(ll e){
	if (e==2) return make_pair(0,-1);
	if (e==1) return make_pair(1,0);
	if (e==0) return make_pair(0,1);
	if (e==3) return make_pair(-1,0); 
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while (T--){
		key.clear();
		cin>>n>>m>>k>>xz>>yz>>dz;
		for (ll i=1;i<=n;i++){
			for (ll j=1;j<=m;j++){
				cin>>c[i][j];
			}
		}
		while(k>0){
			while (!(xz+con(dz).first>=1 && xz+con(dz).first<=n && yz+con(dz).second>=1 && yz+con(dz).second<=m && c[xz+con(dz).first][yz+con(dz).second]=='.') && k>0){
				//cout<<xz+con(dz).first<<"="<<yz+con(dz).second<<endl;
				dz++;
				dz=dz%4;
				k--;
			}
			key.insert(make_pair(xz,yz));
			if (k>0){
				xz+=con(dz).first;
				yz+=con(dz).second;
				k--;
				key.insert(make_pair(xz,yz));
			}
			
		}
		cout<<key.size()<<endl;
	}
	
	return 0;
}
