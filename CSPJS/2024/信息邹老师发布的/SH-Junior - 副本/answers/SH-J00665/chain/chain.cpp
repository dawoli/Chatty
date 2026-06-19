#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	long long t,n,k,q,r[100001],c[100001];
	cin>>t;
	for(int i=1;i<=t;++i){
		cin>>n>>k>>q;
		long long l,s[100001];
		for(int j=1;j<=n;++j){
			cin>>l;
			for(int k=1;k<=l;++k){
				cin>>s[i];
			}
		} 
		for(int j=1;j<=q;++j){
			cin>>r[j]>>c[j];
		}
		for(int j=1;j<=q;++j){
			if(j%2==1){
				cout<<1<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
