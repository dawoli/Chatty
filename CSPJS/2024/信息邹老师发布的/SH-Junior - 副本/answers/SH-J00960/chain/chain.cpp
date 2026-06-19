#include<bits/stdc++.h>
using namespace std;
int S[100005][1000050];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,k,q;
		cin>>n>>k>>q;
		for(int j=0;j<n;j++){
			int l;
			cin>>l;
			for(int k=0;k<l;k++){
				cin>>S[j][k];
			}
		}
		for(int j=0;j<q;j++){
			int r,c;
			cin>>r>>c;
			bool ok=0;
			for(int k=0;k<n;k++){
				for(int z=0;z<l;z++){
					if(S[j][k]) ok=1;
				}
			}
			cout<< ok? 1:0;
		}
	}
} 
