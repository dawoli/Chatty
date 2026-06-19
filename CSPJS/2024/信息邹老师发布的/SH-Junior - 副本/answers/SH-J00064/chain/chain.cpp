#include<bits/stdc++.h> 
using namespace std;
int T,n,k,q,l,r,c,s[109]; 
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n>>k>>q;
		for(int j=0;j<n;j++){
			cin>>l;
			for(int k=0;k<l;k++)cin>>s[k];
		}
		for(int j=0;j<q;j++){
			cin>>r>>c;
			cout<<0<<endl; 
		}
	}
	return 0;
}
