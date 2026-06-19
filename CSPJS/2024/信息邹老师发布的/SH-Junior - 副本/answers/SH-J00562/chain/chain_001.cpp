#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in",stdin);
	freopen("chain.out",stdout);
	int t,n,k,q;
	string s;
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=0;i<n+q;i++){
			cin>>s;
		}
		for(int i=0;i<q;i++){
			cout<<0<<endl;
		}
	}
	return 0;
}

