#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n,k,q;
		cin>>n>>k>>q;vector<int> g[n];
		for(int i=0;i<n;i++){
			int j;cin>>j;
			for(int k=0;k<j;k++){
				int l;cin>>l;
				g[i].push_back(l);
			}
		}
		while(q--){
			int a,b;cin>>a>>b;
			bool flag=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<g[i].size();j++){
					if(g[i][j]==b){
						cout<<1<<endl;
						flag=1;break;
					}	
				} 
				if(flag) break;
			}
			if(!flag) cout<<0<<endl;
		}
	}
}
//Y#C*GF@24 
