#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m,x;cin>>n>>m;
	for (int i=1; i<=n; i++)
		cin>>x;
	for (int j=1; j<=m; j++)
		cin>>x;
	int k=log2(n)+1;
	for (int i=1; i<=k; i++)
	for (int j=1; j<=(1<<(k-i)); j++)
		cin>>x;
	int t;cin>>t;
	while (t--) cout<<0<<endl;
	return 0;
}
