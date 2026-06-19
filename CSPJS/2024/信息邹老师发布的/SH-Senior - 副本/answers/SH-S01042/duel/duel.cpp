#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n, cnt[N];
vector<int> v;

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	int maxv = 0;
	for(int i=1, c; i<=n; i++) cin >> c, cnt[c]++, maxv = max(maxv, c);
	for(int i=1; i<=maxv; i++) if(cnt[i] != 0) v.push_back(cnt[i]);
	if(v.size() == 1) cout << 0;
	else {
		int ans = 0, s = 0;
		for(int i=0; i<v.size(); i++) ans += min(v[i], s), s -= min(v[i], s), s += v[i];
		cout << n - ans;
	}
	return 0;
}

