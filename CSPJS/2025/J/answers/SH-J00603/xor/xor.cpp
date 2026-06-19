#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, k, a[N], axor[N], m, ans;
struct qujian{
	int l, r;
	bool operator<(const qujian& other) const {
		if (r == other.r) return l < other.l;
		return r < other.r;
	}
} q[N];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		axor[i] = axor[i - 1] ^ a[i];
		for (int j = 0; j < i; j++){
			if ((axor[j] ^ axor[i]) == k)
			q[++m] = {j + 1, i};
		}
	}
	sort(q + 1, q + m + 1);
	for (int i = 1; i <= m; i++){
		int cnt = 1, lastl = q[i].l, lastr = q[i].r;
		for (int j = i + 1; j <= m; j++){
			if (q[j].l > lastr){
				cnt++;
				lastl = q[j].l, lastr = q[j].r;
			}
		}
		ans = max(cnt, ans);
	}
	cout << ans;
	return 0;
} 
