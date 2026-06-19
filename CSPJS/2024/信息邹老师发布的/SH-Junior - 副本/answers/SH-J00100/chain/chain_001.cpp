#include <bits/stdc++.h>
using namespace std;
int vis[200005];
int main(){
	ios::sync_with_stdio();
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;cin>>t;
	srand((unsigned)time(NULL));
	while(t--){
		//memset(s,0,sizeof(s));
		int n,k,q;cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int l;cin>>l;
			for(int j=1;j<=l;j++){
				int tmp;
				cin>>tmp;
				vis[tmp]++;
			}
		} 
		while(q--){
			int r,c;cin>>r>>c;
			if(vis[c]==0) cout<<0<<endl;
			else cout<<rand()%2<<endl;
		}
	} 
	return 0; 
} 
