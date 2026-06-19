#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int T;
int n, m, l, V;
int d, v, a;
int t;
int maxx;
int sum, summ;
int A, B, C;
int ans1, ans2;
int p[N], b[30];
double dis;
double qd[N], zd[N];
int main(){
	freopen ("detect.in", "r", stdin);
	freopen ("detect.out", "w", stdout);
	cin >> T;
	for (int k = 1; k <= T; k++){
		ans1 = 0;
		ans2 = 0;
		A = 0;
		B = 0;
		C = 0;
		memset (qd, 0, sizeof(qd));
		memset (zd, 0, sizeof(zd));
		memset (b, 0, sizeof(b));
		cin >> n >> m >> l >> V;
		for (int i = 1; i <= n; i++){
			cin >> d >> v >> a;
			if (a != 0) A = 1;
			if (a <= 0) B = 1;
			if (a >= 0) C = 1;
			if (a == 0){
				if (v > V){
					qd[i] = d - 1;
					zd[i] = l + 1;
				}
				else{
					qd[i] = l + 1;
					zd[i] = l + 1;
				}
			}
			else{
				dis = (V * V - v * v) / (2.0 * a);
				if (a > 0){
					if (v > V){
						qd[i] = d - 1;
						zd[i] = l + 1;
					}
					else{
						qd[i] = d + dis;
						zd[i] = l + 1;
					}
				}
				else{
					if (v <= V){
						qd[i] = l + 1;
						zd[i] = l + 1;
					}
					else{
						qd[i] = d - 1;
						zd[i] = d + dis;
					}
				}
			}
			//cout << dis << endl;
		}
		for (int i = 1; i <= m; i++){
			cin >> p[i];
		}
		if (!A || !B){
			ans2 = m;
			for (int i = 1; i <= n; i++){
				if (p[m] > qd[i]){
					ans2 = m - 1;
					ans1++;
				}
			}
		}
		else{
			for (int i = 1; i <= n; i++){
				t = 0;
				for (int j = 1; j <= m; j++){
					if (p[j] > qd[i] && p[j] < zd[i]){
						if (t == 0){
							ans1++;
							t = 1;
						}
					}
				}
			}
			while (b[0] != 1){
				sum = 0;
				for (int i = 1; i <= n; i++){
					t = 0;
					for (int j = 1; j <= m; j++){
						if (b[j] == 0 && p[j] > qd[i] && p[j] < zd[i]){
							if (t == 0){
								sum++;
								t = 1;
							}
						}
					}
				}
				//cout << sum << endl;
				if (sum == ans1){
					summ = 0;
					for (int i = 1; i <= m; i++){
						if (b[i] == 1) summ++;
					}
					ans2 = max(ans2, summ);
				}
				b[m]++;
				for (int i = m; i >= 1; i--){
					if (b[i] >= 2){
						b[i] = 0;
						b[i - 1]++;
					}
				}
			}
		}
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}
