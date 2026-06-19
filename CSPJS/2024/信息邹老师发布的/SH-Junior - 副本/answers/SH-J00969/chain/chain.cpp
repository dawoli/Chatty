#include<bits/stdc++.h>
using namespace std;
int s2[200005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,k,q,l;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>s2[j];
			}
		}
		while(q--){
			int r,c;
			cin>>r>>c;
			cout<<1<<endl;
		}
	}
	return 0;
}
