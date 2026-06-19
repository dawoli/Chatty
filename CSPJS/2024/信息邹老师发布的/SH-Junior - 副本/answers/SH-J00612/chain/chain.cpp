#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int t,n,k,q,l[1005],x,r,c,li,s[1005][2005];
bool flag;

int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++) {
			cin>>l[i];
			for(int j=1;j<=l[i];j++) {
				cin>>s[i][j];
			}
		}
		for(int i=1;i<=q;i++) {
			cin>>r>>c;
			li=0;
			flag=false;
			//solve(r,c,0);
			if(flag)cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
}

