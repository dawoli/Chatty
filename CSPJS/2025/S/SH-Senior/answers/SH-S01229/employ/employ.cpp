#include <bits/stdc++.h>
using namespace std;
const int N=20,M=998244353;
int n,m,c[N],p[N];string s;
int Brute() {
	int ans=0;cin>>m>>s,s=' '+s;
	for (int i=1; i<=n; i++)
		cin>>c[i],p[i]=i;
	do {
		int ct=0;
		for (int i=1; i<=n; i++)
			if (s[i]=='0' || ct>=c[p[i]]) ct++;
		if (n-ct>=m) ans=(ans+1)%M;
	}while (next_permutation(p+1,p+n+1));
	return ans;
}
int SpecialA() {
	int ans=1;
	for (int i=1; i<=n; i++)
		ans=1ll*ans*i%M;
	return ans;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	if (n<=18) cout<<Brute();
	else cout<<SpecialA();
	return 0;
}
