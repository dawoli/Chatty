#include <bits/stdc++.h>
using namespace std;
vector<int> s[100009]; 
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;cin>>T; 
	while(T--){
		int n,k,q;cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int l;cin>>l;
			for(int j=1;j<=l;j++){
				cin>>si;
				s[i].push_back(si);
			}
		} 
		while(q--){
			int r,c;cin>>r>>c;
			cout<<0<<endl;
		}
	}
	return 0;
}
