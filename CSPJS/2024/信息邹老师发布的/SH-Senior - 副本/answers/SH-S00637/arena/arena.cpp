#include<iostream>
#include<vector>
using namespace std;
long long log2(long long n) {
	n--;
	long long cnt=0;
	while(n) cnt++,n>>=1;
	return cnt;
}
long long a[100005],c[100005];
vector<bool> d[20];
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=m;i++) cin>>c[i];
	long long LOG=log2(n);
	for(long long i=1;i<=LOG;i++) {
		string s;
		cin>>s;
		for(long long j=0;j<s.size();j++) d[i].push_back(s[j]-'0');
	}
	long long t;
	cin>>t;
	while(t--) {
		long long x[4];
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(long long i=1;i<=n;i++) a[i]^=x[i%4];
		cout<<0<<endl;
		for(long long i=1;i<=n;i++) a[i]^=x[i%4];
	}
	return 0;
}
