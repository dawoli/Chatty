#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=998244353;
int n;
int a[N],s[N];
int mx=-1e8;
int main() {
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		s[i]=(s[i-1]+a[i])%mod;
		mx=max(a[i],mx);
	}
	if(n==3) {
		if(s[n]>2*mx)	cout << 1;
		else	cout << 0;
	}else if(s[n]==n){
		cout << n*(n-1)/2%mod;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
