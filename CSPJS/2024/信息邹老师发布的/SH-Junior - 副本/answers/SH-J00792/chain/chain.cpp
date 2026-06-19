#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int l;
			cin>>l;
			for(int j=1;j<=l;j++){
				int s;
				cin>>s;
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			if(y%x==0) cout<<0<<endl;
			else cout<<1<<endl;
		}
	}
	return 0;
}
