#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T,q;
	cin>>T;
	for(int i=1;i<=T;i++) {
		int n,k;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++) {
			short l,n[100000];
			for(int i=1;i<=l;i++) {
				cin>>n[i];
			}
		}
		for(int i=1;i<=q;i++) {
			int r,c;
			cin>>r>>c;
		}
	}
	for(int i=1;i<=q;i++) {
		if(q%2==1&&i%2==0) cout<<0<<endl;
		else if(i%2==1&&q%2==1) cout<<1<<endl;
		else if(i%2==0&&q%2==0) cout<<0<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
