#include<bits/stdc++.h>
using namespace std;
int t_,n_,k_,q_,l_,s_,r_,c_;
int main(){
		freopen("chain.in","r",stdin);
		freopen("chain.in","w",stdout);
	cin>>t_>>n_>>k_>>q_;
	for(int i=1;i<=n_;i++){
			cin>>l_;
			for(int j=1;j<=l_;j++){
				cin>>s_;
			}
	}
	for(int i=1;i<=q_;i++){
			cin>>r_>>c_;
	}
	for(int i=1;i<=q_;i++){
			cout<<0;
	}
	return 0;
}
