#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int mod=998244353;
const int N=505;
int n,m,s[N];
int c[N];
int id[N];
void force() {
	for(int i=1;i<=n;i++) id[i]=i;
	int ans=0;
	do {
		int cnt=0;
		for(int i=1;i<=n;i++) {
			if(cnt>=c[id[i]]) cnt++;
			else if(s[i]==0) cnt++;
		}
		ans+=n-cnt>=m;
	} while(next_permutation(id+1,id+n+1));
	cout<<ans;
}
long long C(long long n,long long m) {
	if(n==1) return 1;
	if(m==1) return 1;
	return (C(n,m-1)+C(n-1,m-1))%mod;
}
void A() {
	long long ans=1;
	int _n=n;
	for(int i=1;i<=n;i++)if(c[i]==0) _n--;
	cout<<C(n,_n);
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		char ch; cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10) force();
	else A();
	return 0;
}
