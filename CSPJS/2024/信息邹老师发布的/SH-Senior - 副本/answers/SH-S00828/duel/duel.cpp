#include <bits/stdc++.h> 
using namespace std;
const int MAX = 1e5;
struct PII {
	int v, alive, able; 
};
bool cmp(PII a, PII b) {
	return a.v < b.v;
}
vector<PII> v = {{0, 0}};
unordered_map<int, int> s;
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n; cin >> n;
	int idx = 1;
	for(int i = 1; i <= n; i++) {
		int tmp; cin >> tmp;
		if (!s[tmp]) {
			s[tmp] = idx;
			idx++;
			v.push_back({tmp, 1, 1});
		}
		else {
			v[s[tmp]].alive++, v[s[tmp]].able++;
		}
	}
	sort(v.begin() + 1, v.end(), cmp);
	for (int i = 2; i < v.size(); i++) {
		if (v[i].able >= v[i - 1].alive) {
			v[i].able -= v[i - 1].alive;
			v[i - 1].alive = v[i - 1].able = 0;
		}
		else {
			v[i - 1].alive -= v[i].able;
			v[i].able = v[i - 1].able = 0;
			v[i].alive += v[i - 1].alive;
		} 
	}
	cout << (*(v.end() - 1)).alive; 
	return 0;
}
