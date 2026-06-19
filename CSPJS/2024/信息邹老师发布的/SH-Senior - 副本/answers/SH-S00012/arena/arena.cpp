#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5,L=log(N)/log(2)+5;

int n,m,a[N],c[N],t,x[5],newa[N];
string s[L];
int maxn[N];

signed main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	} 
	for(int i=1;i<=m;i++) {
		cin>>c[i];
	}
	int len=log(n)/log(2)+1;
	for(int i=1;i<=len;i++) {
		cin>>s[i];
	}
	cin>>t;
	while(t--) {
		memset(maxn,0,sizeof(maxn));
		for(int i=0;i<=3;i++) cin>>x[i];
		for(int i=1;i<=n;i++) {
			newa[i]=a[i]^x[i%4];
			maxn[i]=max(maxn[i-1],newa[i]);
		}
		int ans=2;
		for(int i=2;i<=m;i++) {
			ans^=i*2;
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
