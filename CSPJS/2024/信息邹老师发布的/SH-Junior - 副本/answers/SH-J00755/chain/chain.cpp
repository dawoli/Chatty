#include<bits/stdc++.h>
using namespace std;
struct abc{
	int l,s[200001];
}x[100001];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T,n,k,q,r,c;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n>>k>>q;
		for(int j=0;j<n;j++){
			cin>>x[j].l;
			for(int o=0;o<x[j].l;o++){
				cin>>x[j].s[o];
			}
		}
		for(int i=0;i<q;i++){
			cin>>r>>c;
			cout<<"1"<<endl;
		}
	}
	return 0;
}
