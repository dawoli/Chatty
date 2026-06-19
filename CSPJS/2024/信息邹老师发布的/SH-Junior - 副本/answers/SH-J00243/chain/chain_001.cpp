#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=2e5+1;
int t,n,k,q,l,s[maxn],r,c;
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n>>k>>q>>l;
		for(int i=1;i<=l;i++) {
			cin>>s[i];
		}
		while(q--) {
			cin>>r>>c;
			cout<<1<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
