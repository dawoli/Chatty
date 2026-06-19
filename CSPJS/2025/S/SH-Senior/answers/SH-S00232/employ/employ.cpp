#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int KS=510;
long long f[KS];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	f[0]=1;
	for(int i=1; i<=n; i++) {
		f[i]=f[i-1]*i%mod;
	}
	cout<<f[n]<<"\n";
	return 0;
}
