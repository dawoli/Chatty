#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,a[1009][2009],tot[1009];
int main(){
	freopen("chain.in","r",stdin);
  	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>tot[i];
			for(int j=1;j<=tot[i];j++) cin>>a[i][j];
		}
		while(q--){
			int r,c;
			cin>>r>>c;
				bool ok=0;
				for(int i=1;i<=n;i++){
					for(int j=1;j<=tot[i];j++){
						if(a[i][j]==1){
							for(int tt=j+1;tt<=tot[i]&&tt<=j+k-1;t++) if(a[i][tt]==c){
								ok=1;
								break;
							}
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
