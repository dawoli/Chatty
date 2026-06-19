#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long ll;

const int N = 510, MOD = 998244353;

int sum[N], cnt[N], date[N], c[N];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, cnt0 = 0;
	cin>>n>>m;
	string s;
	cin>>s;
	ll mul1 = 1, mul2 = 1;
	for (int i = 1; i <= n; i ++) {
		cin>>c[i];
		if (!c[i])cnt0++;
	}
	if (n-cnt0<m) {
		cout<<0;
		return 0;
	}
	for (int i = 1; i <= n-cnt0; i ++) {
		mul1=mul1*i%MOD;
	}
	for (int i = 1; i <= cnt0; i ++) {
		mul1 = mul1*i%MOD;
	}
	cout<<mul1;
	return 0;
}
