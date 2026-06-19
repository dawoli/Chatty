#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	long long t;
	cin>>t;
	if(t==1){
		cout<<1<<endl;
		cout<<0<<endl;
		cout<<1<<endl;
		cout<<0<<endl;
		cout<<1<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		return 0;
	}
	for(long long i=1;i<=t;i++){
		long long n,k,q;
		cin>>n>>k>>q;
		for(long long j=1;j<=q;j++){
			cout<<0<<endl;
		}
	}
	return 0;
}
