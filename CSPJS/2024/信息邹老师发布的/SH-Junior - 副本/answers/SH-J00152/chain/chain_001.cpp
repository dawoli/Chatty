#include<bits/stdc++.h>
using namespace std;
int n,k,q,a[1005][2005],t,l[1005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>a[i][j];
			}
		}
		while(q--){
			int r,c;
			cin>>r>>c;
			bool flag=false;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=l[i];j++){
					if(a[i][j]==c){
						flag=true;
						break;
					}
				}
				if(flag) break;
			}
			if(flag) cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
} 
