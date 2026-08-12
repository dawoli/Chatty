#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n + 1), pos_a(n + 1);
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
		pos_a[a[i]] = i;
	}

	vector<char> is_max(n + 1, 0);
	vector<int> max_pos(n + 1, 0);
	int max_val = 0;
	for (int i = n; i >= 1; --i){
		if (a[i] > max_val){
			max_val = a[i];
			is_max[a[i]] = 1;
			max_pos[a[i]] = i;
		}
	}

	vector<int> suf_cnt(n + 2, 0);
	for (int i = n; i >= 1; --i){
		suf_cnt[i] = suf_cnt[i + 1] + (is_max[a[i]] ? 1 : 0);
	}

	long long ans = 0;
	bool idr = false;

	auto add_set = [&](int m, int pos, int L){
		int size = 0;
		bool has_mm1 = false;
		if (pos > 1){
			size += 1;
			has_mm1 = true;
		}
		int cnt = (L <= n) ? suf_cnt[L] : 0;
		if (has_mm1 && is_max[m - 1] && max_pos[m - 1] >= L){
			size += cnt - 1;
		}
		else
		{
			size += cnt;
		}
		ans += size;
		if (pos >= 3){
			idr = true;
		}
	};

	int pos = pos_a[n];
	int L = pos + 1;
	add_set(n, pos, L);

	for (int m = n - 1; m >= 2; --m){
		if (pos_a[m] >= L){
			pos = pos + pos_a[m] - L;
			L = pos_a[m] + 1;
		}
		else
		{
			pos = pos - 1;
		}
		add_set(m, pos, L);
	}

	if (idr){
		ans += 1;
	}
	cout << ans <<  '\n';

	return 0;
}
for (int i = 1; i <= n; i++)