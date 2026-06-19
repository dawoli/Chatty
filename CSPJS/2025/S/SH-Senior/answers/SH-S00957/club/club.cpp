#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 1e5 + 10;
int T, n, ans, a[N][3];
vector<int> vec[3];

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T --> 0){
		cin >> n;
		for (int i : {0, 1, 2}){
			vec[i].clear();
		}
		ans = 0;
		for (int i = 1; i <= n; i++){
			int k1 = - 1, k2 = - 1;
			auto cmp = [&](int x, int y){
				if (y == - 1){
					return true;
				}
				return a[i][x] > a[i][y];
			};
			for (int j : {0, 1, 2}){
				cin >> a[i][j];
				if (cmp(j, k1)){
					k2 = k1, k1 = j;
				}else if (cmp(j, k2)){
					k2 = j;
				}
			}
			ans += a[i][k1];
			vec[k1].push_back(a[i][k1] - a[i][k2]);
		}
		for (int j : {0, 1, 2}){
			if (vec[j].size() <= n / 2){
				continue;
			}
			sort(vec[j].begin(), vec[j].end());
			for (int i = 0; i < vec[j].size() - n / 2; i++){
				ans -= vec[j][i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
