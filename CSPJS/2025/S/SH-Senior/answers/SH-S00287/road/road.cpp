#include <bits/stdc++.h>
using namespace std;

struct road{
	int16_t u, v;
	int64_t w;
};

bool cmp(road &a, road &b){
	return a.w < b.w;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int16_t n; int32_t m; int8_t k;
	cin >> n >> m >> k;
	vector<road> r(m);
	vector<int64_t> c(k);
	vector<vector<int64_t>> a(k, vector<int64_t>(n));
	for(int32_t i = 0; i < m; ++i) cin >> r[i].u >> r[i].v >> r[i].w;
	for(int8_t i = 0; i < k; ++i){
		cin >> c[i];
		for(int16_t j = 0; j < n; ++j) cin >> a[i][j];
	}
	sort(r.begin(), r.end(), cmp);
	
	vector<bool> ct(n, false);
	int64_t cst = 0;
	for(int32_t i = 0; i < r.size(); ){
		if(ct[r[i].u] && ct[r[i].v]) r.erase(r.begin() + i);
		else{
			cst += r[i].w;
			++i;
		}
	}
	
	cout << cst << endl;
	return 0;
}
