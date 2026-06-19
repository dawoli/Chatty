#include<bits/stdc++.h>
using namespace std;

int T;

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		int n,k,q;
		cin>>n>>k>>q;
		bool ans;
		ans=0;
		while(q--){
			if(q==0){cout<<0<<endl;continue;}
			ans=!ans;
			cout<<ans<<endl;
		}
	}
	return 0;
}
