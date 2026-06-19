#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int ans, n, a[N], cnt[N], chucun, cha;
priority_queue <int> q;
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	memset(cnt, 0, sizeof(cnt));
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (cnt[a[i]] == 0) q.push(-a[i]);
		cnt[a[i]] ++;
	}
	int zhixing = q.size();
	for (int i = 1; i < zhixing; i ++) {
		int flaga = -q.top();
		q.pop();
		
		int flagb = -q.top();
		if (cnt[flaga] <= cnt[flagb]) {
			ans += cnt[flaga];
			cha = cnt[flagb] - cnt[flaga];
			ans += min(chucun, cha);
			chucun -= cha;
			if (chucun < 0) chucun = 0;
		}
		else {
			cha = cnt[flaga] - cnt[flagb];
			chucun += cha;
			ans += cnt[flagb];
		}
	}
	cout << n - ans;



	return 0;
}

