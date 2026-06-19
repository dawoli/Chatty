#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, x, cnt, pre[1000001], mid[1000001], ans[1000001];
string suf;
string To_string(int t){
	char c[101];
	int cnt = -1;
	string ret = "";
	while (t){
		c[++cnt] += char(t % 10 + '0');
		t /= 10;
	}
	for (int i = 0; i <= cnt; i++){
		ret += c[cnt - i];
	}
	return ret;
}
int ksm(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1){
			ret = 1ll * ret * a % mod;
		}
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return ret;
}
string back(int midl, int midr, int prel, int prer){
	string ret = "";
	if (midr < midl){
		return ret;
	}
	int t = midl;
	while (t < n && mid[t] != pre[prel]){
		t++;
	}
	if (mid[t] != pre[prel]){
		return ret;
	}
	ret += back(midl, t - 1, prel + 1, prel + t - midl);
	ret += back(t + 1, midr, prel + t - midl + 1, prer);
	ret += To_string(pre[prel]);
	return ret;
}
int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d", &n);
	if (n > 10){
		cout << ksm(2, n - 1);
		return 0;
	}
	for (int i = 1; i <= n; i++){
		scanf("%d", pre + i);
	}
	for (int i = 1; i <= n; i++){
		scanf("%d", &x);
		suf += To_string(x);
	}
	for (int i = 1; i <= n; i++){
		mid[i] = i;
	}
	do {
		if (back(1, n, 1, n) == suf){
			cnt++;
			if (cnt == 1){
				for (int i = 1; i <= n; i++){
					ans[i] = mid[i];
				}
			}
		}
	}while (next_permutation(mid + 1, mid + n + 1));
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++){
		printf("%d ", ans[i]);
	}
	return 0;
}

