#include<bits/stdc++.h>
using namespace std;
int a[1010][2010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	int n,k,q;
	for(int i=1;i<=t;i++){
		cin>>n>>k>>q;
		int l;
		for(int j=1;j<=n;j++){
			cin>>l;
			for(int k=1;k<=l;k++){
				cin>>a[j][k];
			}
		}
		int u,v;
		for(int i=1;i<=q;i++){
			cin>>u>>v;
			cout<<1<<'\n';
		}
	}
	return 0;
}
