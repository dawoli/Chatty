#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int l=1;l<=T;l++){
		int n,k,q,a[200009];
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int m,b;
			cin>>m>>b;
			for(int j=2;j<=k;j++) {
				cin>>b;
				a[b]=1;
			}
			for(int j=k+1;j<=m;j++) cin>>b;
		}
		for(int i=1;i<=q;i++){
			int r,c;
			cin>>r>>c;
			if(a[c]==1) cout<<"1"<<endl;
			else cout<<"0"<<endl;
		}
	}
	return 0; 
}
