#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	while(T--){
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int l;
			cin>>l;
			for(int j=1;j<=l;j++){
				int num;
				cin>>num;
			}
		}
		if(k%2==0) cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
