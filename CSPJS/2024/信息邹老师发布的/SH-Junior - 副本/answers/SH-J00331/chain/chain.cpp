#include <bits/stdc++.h>
using namespace std;

int T;

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);

	cin>>T;
	while(T--){
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int l,s[200005][200005];
			cin>>l;
			for(int j=1;j<=l;j++) cin>>s[i][j];
		}
		int q;
		for(int i=1;i<=q;i++){
			int r[100005],c[100005];
			cin>>r[i]>>c[i];
		}
	}
	return 0;
}
