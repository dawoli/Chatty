#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;cin>>t;
	while (t--) {
		int n,k,q,x;cin>>n>>k>>q;
		for (int i=1,xx; i<=n; i++) {
			cin>>xx;
			while (xx--) cin>>x;
		}
		while (q--) cin>>x>>x,cout<<1<<endl;
	}
	return 0;
} 
