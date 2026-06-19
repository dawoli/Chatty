#include <bits/stdc++.h>

using namespace std;

struct Seg {
	int l, r;
	bool operator<(const Seg &seg) {
		if(l == seg.l) {
			return r < seg.r;
		}
		return l < seg.l;
	}
};

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int N, K;
	cin >> N >> K;
	vector<int> A(N + 1);
	for(int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	if(N > 100000 && K <= 1) {
		int One = 0, Zero = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i]) {
				One++;
			}
			else {
				Zero++;
			}
		}
		if(K) {
			cout << One << '\n';
		}
		else {
			cout << Zero << '\n';
		}
		return 0;
	}
	vector<int> pre(N + 1);
	for(int i = 1; i <= N; i++) {
		pre[i] = pre[i - 1] ^ A[i];
	}
	
	vector<Seg> seq; int cnt = 0;
	for(int len = 1; len <= N; len++) {
		for(int i = 1; i + len - 1 <= N; i++) {
			int sum = pre[i + len - 1] ^ pre[i - 1];
			if(sum == K) {
				seq.push_back(Seg{i, i + len - 1});
				cnt++;
			}
		}
	}
	sort(seq.begin(), seq.end());
	vector<int> dp(cnt, 1);
	for(int i = 0; i < cnt; i++) {
		for(int j = 0; j < i; j++) {
			if(seq[j].r < seq[i].l) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	cout << dp[cnt - 1] << '\n';

//	for(int x : dp) {
//		printf("{%d} ", x);
//	} printf("\n");
//	for(Seg x : seq) {
//		printf("{%d, %d} ", x.l, x.r);
//	}
	return 0;
}
