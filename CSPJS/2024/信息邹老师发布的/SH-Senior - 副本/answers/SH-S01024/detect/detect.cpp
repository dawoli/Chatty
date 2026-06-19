#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, m, l, v, vis[100005][5], p[100005], ans;
vector<int>det[100005];
bool c[100005];
signed main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >>t;
	while (t--){
		cin >> n >> m >> l >> v;
		bool flag = 1;
		for (int i = 1; i <= n; i++){
			int d, s, a;
			cin >> d >> s >> a;
			vis[i][1] = vis[i][2] = -1;
			flag &= (a >= 0);
			if (a == 0){
				if (s > v){
					vis[i][1] = d;
					vis[i][2] = l;
				}
			}
			else if (a > 0){
				int dis = (v * v - s * s) / (2 * a);
				if (dis >= 0){
					if (d + dis + 1 <= l){
						vis[i][1] = d + dis + 1;
						vis[i][2] = l;
					}
				}
				else{
					vis[i][1] = d;
					vis[i][2] = l;
				}
			}
			else{
				int dis = (v * v - s * s) / (2 * a);
				if (dis >= 0){
					vis[i][1] = d;
					if ((v * v - s * s) % (2 * a) == 0){
						vis[i][2] = min(d + dis - 1, l);
					}
					else{
						vis[i][2] = min(d + dis, l);
					}
				}
			}
			//cout << vis[i][1] <<" " <<vis[i][2] <<endl;
		}
		for (int i = 1; i <= m; i++){
			cin >> p[i];
		}
		sort(p+1, p+m+1);
		if (flag){
			ans = 0;
			for (int i = 1; i <= n; i++){
				if (vis[i][1] <= p[m] && vis[i][1] != -1){
					ans++;
				}
			}
			if (ans == 0){
				cout << "0 " << m <<endl;
			}
			else{
				cout << ans << " " << m - 1 << endl;
			}
			continue;
		}
		for (int i = 1; i <= m; i++){
			det[i].clear();
		}
		ans = 0;
		for (int i = 1; i <= n; i++){
			bool flag = 0;
			for (int j = 1; j <= m; j++){
				if (vis[i][1] <= p[j] && vis[i][2] >= p[j]){
					flag = 1;
					det[j].push_back(i);
				}
			}
			if (flag){
				ans++;
			}
		}
		cout << ans << " ";
		for (int i = 1; i <= m; i++){
			for (int j = 0; j < det[i].size(); j++){
				//cout <<det[i][j] <<" ";
			}
			//cout <<endl;
		}
		int out = 0;
		for (int i = 0; i < (1 << m); i++){
			for (int j = 1; j <= n; j++){
				c[j] = 0;
			}
			int sum = 0;
			//cout << "start " << i <<endl;
			for (int j = 0; j < m; j++){
				if (i >> j & 1){
					//cout << j <<" ";
					sum++;
					for (int u = 0; u < det[j + 1].size(); u++){
						c[det[j + 1][u]] = 1;
					}
				}
			}
			//cout <<endl;
			int cnt = 0;
			for (int j = 1; j <= n; j++){
				if (c[j]){
					cnt++;
				}
			}
			//cout <<cnt <<endl;
			if (cnt == ans){
				//cout << "ok" <<endl;
				out = max(out, m - sum);
			}
		}
		cout << out << endl;
	}
	return 0;
}
