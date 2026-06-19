#include <iostream>
#include <algorithm>
#include <vector>

int n, ans;
int a[100005][3], d[100005], w[100005];
std::vector <int> plan[3];


inline bool cmp(int x, int y) {
	return d[x] < d[y];
}

void adjust2(int from, int to) {
	for (int i : plan[from]) d[i] = a[i][from] - a[i][to];
	std::sort(plan[from].begin(), plan[from].end(), cmp);
	for (int i = 0; plan[from].size() - i > n / 2; i++)
		ans -= d[plan[from][i]];
}

void adjust1(int id) {
	for (int i : plan[id]) {
		d[i] = std::min(a[i][id] - a[i][(id + 1) % 3], a[i][id] - a[i][(id + 2) % 3]);
		if (a[i][id] - a[i][(id + 1) % 3] == d[i]) w[i] = 1;
		else w[i] = 2;
	}
	std::sort(plan[id].begin(), plan[id].end(), cmp);
	for (int i = 0; plan[id].size() - i > n / 2; i++)
		ans -= d[plan[id][i]], plan[(id + w[plan[id][i]]) % 3].push_back(plan[id][i]);

	if (plan[(id + 1) % 3].size() > n / 2) adjust2((id + 1) % 3, (id + 2) % 3);
	else if (plan[(id + 2) % 3].size() > n / 2) adjust2((id + 2) % 3, (id + 1) % 3);
}

void solve() {
	ans = 0; plan[0].clear(), plan[1].clear(), plan[2].clear();
	std::cin>>n;
	for (int i = 1; i <= n; i++) {
		std::cin>>a[i][0]>>a[i][1]>>a[i][2];
		int max = std::max(a[i][0], std::max(a[i][1], a[i][2])); ans += max;
		if (max == a[i][0]) plan[0].push_back(i);
		else if (max == a[i][1]) plan[1].push_back(i);
		else plan[2].push_back(i);
	}


	if (plan[0].size() > n / 2) adjust1(0);
	else if (plan[1].size() > n / 2) adjust1(1);
	else if (plan[2].size() > n / 2) adjust1(2);
	std::cout<<ans<<"\n";
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; std::cin>>t;
	while (t-->0) solve();
}