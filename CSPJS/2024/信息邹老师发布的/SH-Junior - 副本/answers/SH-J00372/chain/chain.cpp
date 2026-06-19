#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,c,r;
vector<int> v[5][100001];
vector<pair<int,int> > bz[5][6];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int zs;
			cin>>zs;
			while(zs--){
				int ys;
				cin>>ys;
				v[t][i].push_back(ys);
			}
		}
		while(q--){
			cin>>r>>c;
			bool ok=0;
			bz[t][0].push_back(make_pair(0,1));
			for(int i=1;i<=r;i++){
				for(int j=0;j<bz[t][i-1].size();j++){
					for(int l=1;l<=n;l++){
						if(l==bz[t][i-1][j].first) continue;
						for(int m=0;m<v[t][l].size();m++){
							if(v[t][l][m]!=bz[t][i-1][j].second) continue;
							for(int o=1;o<k&&m+o<v[t][l].size();o++){
								if(i==r&&v[t][l][m+o]==c){
									ok=1;
									break;
								}
								bz[t][i].push_back(make_pair(l,v[t][l][m+o]));
							}
							if(ok) break;
						}
						if(ok) break;
					}
					if(ok) break;
				}
				if(ok) break;
			}
			if(ok) cout<<1<<endl;
			else cout<<0<<endl; 
		}
	}
	return 0;
}
