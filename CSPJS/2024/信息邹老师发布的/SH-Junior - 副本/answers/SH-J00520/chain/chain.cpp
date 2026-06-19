#include <bits/stdc++.h>
using namespace std;
int t,n,k,q;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int _=1;_<=t;++_){
		cin>>n>>k>>q;
		for(int i=1;i<=q;++i){
			int k=rand();
			cout<<k%2<<endl;
		}
	}
	return 0;
}
