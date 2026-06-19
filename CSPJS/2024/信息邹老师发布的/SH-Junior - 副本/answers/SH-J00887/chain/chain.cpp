#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while (t--){
		int n,k,q;
		cin>>n>>k>>q;
		vector<int> ls[n];
		set<int> ld;
		for (int i=0;i<n;i++){
			int l;
			cin>>l;
			for (int j=0;j<l;j++){
				int a;
				cin>>a;
				ls[i].push_back(a);
				ld.insert(a);
			}
		}
		while (q--){
			int r,c;
			cin>>r>>c;
			int ans=0;
			if(r==1){
				for (int i=0;i<n;i++){
					for (int j=0;j<ls[i].size()-1;j++){
						if (ls[i][j]==1){							
							for(int o=1;o<k&&j+o<ls[i].size();o++){
								if (ls[i][j+o]==c){
									ans=1; 
								} 
							}
						}
					}
				}
			}
			else{
				if (k>=1e5){
					int len=ld.size();
					ld.insert(c);
					if (len==ld.size()){
						ans=1;
					}
					else{
						ld.erase(c); 
					} 
				}
			}
			cout<<ans<<endl; 
		}
	}
	return 0;
} 
