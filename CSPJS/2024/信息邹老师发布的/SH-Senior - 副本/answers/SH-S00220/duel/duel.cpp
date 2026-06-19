#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> a, b;
int cnt1[N], cnt2[N];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
	} 
	b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for (int i: a) {
		int t = lower_bound(b.begin(), b.end(), i) - b.begin() + 1;
		cnt1[t]++;
		cnt2[t]++;
	}
	int sum = n;
	for (int i = 1; i < b.size(); ++i) {
		for (int j = i + 1; j <= b.size(); ++j) {
//			printf("> i: %d, j: %d, cnt1_j: %d, cnt2_i: %d, ", i, j, cnt1[j], cnt2[i]);
			if (cnt1[j] - cnt2[i] >= 0) {
				cnt1[j] -= cnt2[i];
				sum -= cnt2[i];
				cnt2[i] = 0;
//				printf("sum: %d\n", sum);
				break;
			} else {
				cnt2[i] -= cnt1[j];
				sum -= cnt1[j];
//				printf("sum: %d\n", sum);
				cnt1[j] = 0;
			}
		}
	}
	printf("%d\n", sum);
	return 0;
} 
