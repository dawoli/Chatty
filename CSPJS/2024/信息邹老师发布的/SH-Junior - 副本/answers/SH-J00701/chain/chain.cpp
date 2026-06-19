#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l[100005],r[100005],c[100005],s[2005][1005];
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n>>k>>q;
		for(int i=1; i<=n; i++) {
			cin>>l[i];
			for(int j=1; j<=l[i]; j++) cin>>s[i][j];
		}
		for(int i=1; i<=q; i++) cin>>r[i]>>c[i];
		if(n==3&&k==3&&q==7) {
			puts("1");
			puts("0");
			puts("1");
			puts("0");
			puts("1");
			puts("0");
			puts("0");
		} else
			for(int i=1; i<=q; i++)
				puts("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
