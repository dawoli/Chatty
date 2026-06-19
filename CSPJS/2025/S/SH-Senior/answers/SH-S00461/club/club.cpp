#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int t, n, sum;
int a[MAXN][3], clubs[3];
void dfs(const int progress, const int current_sum) {
	sum = max(current_sum, sum);
	if (progress >= n) return;
	if (clubs[0] < (n + 1) / 2 ) {
		clubs[0]++;
		dfs(progress + 1, current_sum + a[progress][0]);
		clubs[0]--;
	}
	if (clubs[1] < (n + 1) / 2 ) {
		clubs[1]++;
		dfs(progress + 1, current_sum + a[progress][1]);
		clubs[1]--;
	}
	if (clubs[2] < (n + 1) / 2 ) {
		clubs[2]++;
		dfs(progress + 1, current_sum + a[progress][2]);
		clubs[2]--;
	}
}
struct Member {
	int index;
	int club;
	int value;
	bool operator < (const Member &other) const {
		return value < other.value;
	}
};
struct Member2 {
	int index;
	int club;
	int value;
	bool operator < (const Member2 &other) const {
		return value > other.value;
	}
};
int get_max_avaliable(const int index) {
	int k = -1;
	int prev_max = -1;
	for (int i = 0; i<3; ++i) {
		if (clubs[i] >= n / 2) continue;
		if (a[index][i] >= prev_max) {
			k = i;
		}
	}
	return a[index][k];
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--) {
		int used_member[n];
		sum = 0;
		cin>>n;
		if (n < 23)	{
			for (int i = 0; i < n; ++i) cin >> a[i][0] >> a[i][1] >> a[i][2];
			dfs(0, 0);
		} else {
			bool used_member[MAXN] = {};
			for (int i = 0; i < 3; ++i) clubs[i] = 0;
			priority_queue<Member> pq;
			
			priority_queue<Member2> pq_list[3];
			for (int i = 0; i < n; ++i) {
				cin >> a[i][0] >> a[i][1] >> a[i][2];
				pq.push({i, 0, a[i][0]});
				pq.push({i, 1, a[i][1]});
				pq.push({i, 2, a[i][2]});
			}
			
			while (!pq.empty()) {
				const Member m = pq.top();
				pq.pop();
				if (used_member[m.index]) continue;
				if (clubs[m.club] >= n / 2) {
					const int sum2 = sum - pq_list[m.club].top().value + m.value;
					if (sum2 + get_max_avaliable(pq_list[m.club].top().index) > sum) {
						used_member[pq_list[m.club].top().index] = false;
						pq_list[m.club].pop();
						pq_list[m.club].push({m.index, m.club, m.value});
						sum = sum2;
					}
					continue;
				}
				sum += m.value;
				used_member[m.index]=true;
				pq_list[m.club].push({m.index, m.club, m.value});
				assert(m.club < 3 && m.index < n);
				assert(clubs[m.club] <= n / 2);
				clubs[m.club]++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
