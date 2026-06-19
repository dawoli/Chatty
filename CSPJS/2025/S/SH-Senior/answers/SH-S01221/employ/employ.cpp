#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long c[510];
const long long MOD=998244353;
long long sum=1;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	if(m==n) {
		for(int i=1; i<=m; i++) {
			sum=(sum*i)%MOD;
		}
		cout<<sum;
		return 0;
	}
	int len=s.size(),cnt=0;
	for(int i=0; i<len; i++) {
		if(s[i]=='1') {
			cnt++;
		}
	}
	for(int i=cnt; i>=1; i--) {
		sum=(sum*n)%MOD;
		n--;
	}
	cout<<sum;
	return 0;
}
