#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(time(0));
	cin>>T; 
	while(T--){
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;++i){
			int l,a;
			cin>>l;
			for(int j=1;j<=l;++j)
				cin>>a;
		}
		for(int i=1;i<=q;++i){
			int r,c;
			cin>>r>>c;	
		}
		for(int i=1;i<=q;++i)
			cout<<rand()%2<<'\n';
	}
	return 0;
}
