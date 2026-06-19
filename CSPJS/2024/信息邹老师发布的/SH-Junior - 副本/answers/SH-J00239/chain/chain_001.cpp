#include<bits/stdc++.h>
using namespace std;
int n,k,q,t,x,eee;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	for(int ii=0;ii<t;ii++){
		cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			cin>>x;
			for(int j=0;j<x;j++){
				cin>>eee;
			}
		}
		for(int i=0;i<q;i++){
			cin>>eee;
			cin>>eee;
			cout<<eee%2<<endl;
		}
	}
	return 0;
} 
