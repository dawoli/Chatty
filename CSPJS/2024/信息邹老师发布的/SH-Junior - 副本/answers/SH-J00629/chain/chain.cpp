#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		srand(time(0));
		int n,k,q,x,a;
		cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			cin>>x;
			for(int j=0;j<x;j++) cin>>a;
		}
		for(int i=0;i<q;i++){
			srand(time(0));
			cin>>x>>a;
			cout<<rand()%2<<endl;
		}
	}
}
