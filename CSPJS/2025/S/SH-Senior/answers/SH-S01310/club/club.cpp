#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Student = vector<ll>;
struct State { 
	Student s; ll dv; 
	bool operator<(const State other) const {
		return dv > other.dv;
	}
};
ll balance(const vector<Student>& a, int N) {
	set<Student> removed;
	priority_queue<State> pq;
	size_t idx = 0;
	for (auto s : a) {
		sort(s.begin(), s.end());
		s.push_back(idx); // Ensure identity
		pq.push({s, s[2] - s[0]});
		pq.push({s, s[2] - s[1]});
		idx++;
	} 
	auto sz = a.size(); size_t cnt = 0;
	ll tot_d = 0;
	while (sz - cnt > N / 2) {
		auto f = pq.top();
		pq.pop();
		if (removed.count(f.s)) continue;
		tot_d += f.dv; cnt++; removed.insert(f.s);
	}	
	return tot_d;
}
void loop() {
	int N; cin >> N;
	vector<Student> s(N, vector<ll>(3));
	for (auto &r : s) for (auto &x : r) cin >> x;
	vector<Student> A, B, C;
	ll tot = 0; size_t cnt[] = {0, 0, 0};
	for (auto &v : s) {
		if (v[0] >= v[1] && v[0] >= v[2])
			A.push_back(v), tot += v[0];
		else if (v[1] >= v[2] && v[1] >= v[0])
			B.push_back(v), tot += v[1];
		else if (v[2] >= v[1] && v[2] >= v[0])
			C.push_back(v), tot += v[2];
	}
	if (A.size() > N / 2) tot -= balance(A, N);
	else if (B.size() > N / 2) tot -= balance(B, N);
	else if (C.size() > N / 2) tot -= balance(C, N);
	cout << tot << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; cin >> T;
	while (T--) loop();
	return 0;
} 
