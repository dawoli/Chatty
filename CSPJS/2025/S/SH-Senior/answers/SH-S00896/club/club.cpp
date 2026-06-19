#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int myd[100005][4];

long long solution = -1;
void dfs(int pos, long long val, int mem1, int mem2, int mem3) {
	if (pos == n + 1) {
		solution = max(solution, val);
		return;
	}
	if (mem1 < n / 2) dfs(pos + 1, val + myd[pos][1], mem1 + 1, mem2, mem3);
	if (mem2 < n / 2) dfs(pos + 1, val + myd[pos][2], mem1, mem2 + 1, mem3);
	if (mem3 < n / 2) dfs(pos + 1, val + myd[pos][3], mem1, mem2, mem3 + 1);
}
void solveBF() {
	dfs(1, 0, 0, 0, 0);
	printf("%lld\n", solution);
	solution = -1;
}

void solveBF3() {
	vector<int> v = {};
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		v.push_back(myd[i][1]);
	}
	sort(v.begin(), v.end());
	for (int i = n - 1; i >= n / 2; i--) {
		ans+=v[i];
	}
	printf("%lld\n", ans);
}

struct tri{
	int a, b, c;
	pair<int, int> max;
	pair<int, int> low;
	int use;
}mems[100005];
bool cmp1(pair<int, int> a, pair <int, int> b) {
	return a.first > b.first;
}
bool cmp2(tri p, tri q) {
	return p.low.first < q.low.first;
}
void solve() {
	for (int i = 1; i <= n; i++) {
		vector<pair<int, int> > v;
		mems[i].a = myd[i][1];
		mems[i].b = myd[i][2];
		mems[i].c = myd[i][3];
		v.push_back({mems[i].a, 1});
		v.push_back({mems[i].b, 2});
		v.push_back({mems[i].c, 3});
		sort(v.begin(), v.end(), cmp1);
		mems[i].max = v[0];
		mems[i].low = {v[0].first - v[1].first, v[1].second};
	}
	long long res = 0;
	int use[4] = {0, 0, 0, 0};
	for (int i = 1; i <= n; i++) {
		mems[i].use = mems[i].max.second;
		use[mems[i].use]++;
	}
	sort(mems + 1, mems + 1 + n, cmp2);
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= n; j++) {
			if (mems[j].use == i && use[i] > n / 2) {
				mems[j].use = mems[j].low.second;
				use[i]--, use[mems[j].use]++;
			}
		}
		
	}
	for (int j = 1; j <= n; j++) {
		switch(mems[j].use) {
			case 1:
				res += mems[j].a;
				break;
			case 2:
				res += mems[j].b;
				break;
			case 3:
				res += mems[j].c;
				break;
			default:
				break;
		}
	}
	printf("%lld\n", res);
}

int main() {
	freopen("club.in", "r", stdin); 
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--) {
		scanf("%d", &n);
		bool flag = 1, flag2 = 1;
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", &myd[i][1], &myd[i][2], &myd[i][3]);
			if (myd[i][3] != 0) flag = 0;
			if (myd[i][2] != 0) flag2 = 0; 
		}
		if (n <= 10) solveBF();
		else if (flag2) solveBF3();
		else solve();
	}
	return 0;
} 
