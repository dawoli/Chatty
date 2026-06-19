#include <bits/stdc++.h>
#define N 100005

using namespace std;

int n, cnt, kill, a;
map<int, int> m;
vector<int> monster;
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a;
		m[a] ++;
		monster.push_back(a);
	}
	sort(monster.begin(), monster.end());
	for (int i=1; i<monster.size(); ++i) {
		if (monster[i] == monster[i - 1]) continue;
		kill += m[monster[i - 1]];
		cnt += min(m[monster[i]], kill);
		kill -= min(m[monster[i]], kill);
	}
	cout << n - cnt << endl;
	return 0;
}
