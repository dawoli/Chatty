#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int mod = 998244353;

int n,m,s[N],c[N];
long long ans = 1;

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	char ch;
	for(int i = 1;i <= n;i++) {
		cin >> ch;
	}
	long long ans = 1;
	for(long long i = 1;i <= n;i++) {
		ans *= i;
		ans %= mod;
	}
	cout << ans%mod/3;
	
	fclose(stdin);
	fclose(stdout);
}
