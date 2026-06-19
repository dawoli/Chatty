#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, a[5005];
inline bool cmp(vector<int> x, vector<int> y){
	if (x.size() != y.size())
		return x.size() < y.size();
	int m = x.size();
	for (int i = 0; i < m; i++)
		if (x[i] != y[i])
			return x[i] < y[i];
	return 1;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	int maxa = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		maxa = max(maxa, a[i]);
	}
	if (maxa == 1){
		cout << n - 2 << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	vector<vector<int> > polygon;
	for (int i = 1; i <= (1 << n); i++){
		vector<int> xuan;
		int x = i, p = 1;
		while (x){
			if (x & 1)
				xuan.push_back(p);
			p++;
			x >>= 1;
		}
		if (xuan.size() < 3) continue;
		int sum_l = 0, max_l = 0;
		for (int i = 0; i < xuan.size(); i++){
			sum_l += a[xuan[i]];
			max_l = max(max_l, a[xuan[i]]);	
		}
		if (sum_l > max_l * 2)
			polygon.push_back(xuan);
	}
	sort(polygon.begin(), polygon.end(), cmp);
	polygon.erase(unique(polygon.begin(), polygon.end()), polygon.end());
	cout << polygon.size() % MOD << endl;
	return 0;
} 


