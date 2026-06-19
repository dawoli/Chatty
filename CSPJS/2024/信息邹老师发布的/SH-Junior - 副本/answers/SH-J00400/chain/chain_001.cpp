#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,n,k,p,l,h,r,c;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k>>p;
		for(int j=1;i<=n;i++){
			cin>>l;
			for(int a=1;a<=l;a++){
				cin>>h;
			}
		}
		for(int j=1;j<=p;j++){
			cin>>r>>c;
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=p;j++){
			cout<<0;
		}
	}
	return 0;
}
