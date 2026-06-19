#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,l[1005],q,mx;
vector<int> a[1005];
vector<int> f[105][200005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>m;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>x;mx=max(mx,x);
				a[i].push_back(x);
			}
		}
		while(m--){
			cin>>q>>x;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=l[i];j++){
					if(a[i][j]==1) f[0][1].push_back(i);
				}
			}
			for(int i=1;i<=q;i++){
				for(int j=1;j<=n;j++){
					for(int r=1;r<=l[j];r++){
						for(int p=r-1;p>0 && (r-p)<k;p--){
							if(f[i-1][a[j][p]].size()>1 || f[i-1][a[j][p]].size()==1 &&f[i-1][a[j][p]][0]!=j)
							f[i][a[j][r]].push_back(j);
						}
					}
				}
			}
			if(f[q][x].size()>0) cout<<1;
			else cout<<0;
			cout<<endl;
		}
	}
	return 0;
}
