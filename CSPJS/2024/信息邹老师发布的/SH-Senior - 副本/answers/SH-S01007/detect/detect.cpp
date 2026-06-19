#include<bits/stdc++.h>
#include<fstream>
std::ifstream fin("detect.in");
std::ofstream fout("detect.out");

bool check[100005];
long double pos[100005];
long double pos_nd[100005];
long double p[100005];
std::vector<std::pair<int,int> > save;
int st[100005];

void init() {
	save.clear();
}

void solve() {
	init();
	int n, m, l;
	long double v_al;
	fin >> n >> m >> l >> v_al;
	for (int i = 1; i <= n; ++i) {
		int d;
		long double v, a;
		fin >> d >> v >> a;
		pos_nd[i] = l+1;
		pos[i] = l+1;
		if (a == 0) {
			if (v > v_al) {
				pos[i] = d-1;
			}
		}
		else if (v > v_al) {
			pos[i] = d-1;
			if (a < 0) {
				long double dif  =2;
				long double xxx = l+1;
				pos_nd[i] = std::min(d+(v + (v_al-v)/dif) * (v_al-v) / a, xxx);
			}
		}
		else if (a < 0) {
		}
		else {
			long double dif  =2;
			long double tem = (v + (v_al-v)/dif) * (v_al-v) / a;
			long double xxx = l+1;
			if (tem < 0) {
				pos[i] = xxx;
			}
			else pos[i] = std::min(d+tem,xxx);
		}
	}
	for (int i = 1; i <= m; ++i) {
		fin >> p[i];
	}
	std::sort(p+1, p+m+1);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (pos[i] >= p[m] || pos_nd[i] <= p[1]) continue;
		int l = 0, r = m;
		while (l < r-1) {
			int mid = (l+r)/2;
			if (p[mid] > pos[i]) r = mid;
			else l = mid;
		}
		int l1 = 0, r1 = m+1;
		while (l1 < r1-1) {
			int mid = (l1+r1)/2;
			if (p[mid] < pos_nd[i]) l1 = mid;
			else r1 = mid;
		}
		if (r <= l1) {
			save.push_back({l1,i});
			st[i] = r;
			ans++;
		}
	}
	fout << ans <<" ";
	ans  =0;
	std::sort(save.begin(), save.end());
	int lst = -1;
	for (auto v : save) {
		if (lst < st[v.second]) {
			lst = v.first;
			ans++;
		}
	}
	fout << m-ans <<"\n";
}

int main() {
	std::setprecision(20);
	int t;
	fin >> t;
	while (t --> 0) {
		solve();
	}
}
