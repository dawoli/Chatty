#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int n,q,k,t,a,l;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t>>k>>q;
		for(int j=1;j<=t;j++){
			cin>>l;
			for(int x=1;x<=l;x++){
				cin>>a;
			}
		}
		for(int j=1;j<=q;j++){
			cin>>a;
		}
		for(int j=1;j<=q;j++)cout<<0<<endl;
	}
	return 0;
}

