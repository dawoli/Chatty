#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, m, L, vmax, d[N], v[N], a[N], ansa, ansb, csd, ansc;
bool fugai[N];
vector <int> chao;
struct node{
	int pos;
}p[N];
bool cmp(node a, node b) {
	return a.pos < b.pos;
}
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while (t --) {
		ansa = 0, ansb = 0, ansc = 0;
		memset(fugai, 0, sizeof(fugai));
		cin >> n >> m >> L >> vmax;
		for (int i = 1; i <= n; i ++) cin >> d[i] >> v[i] >> a[i];
		for (int i = 1; i <= m; i ++) {
			cin >> p[i].pos;
			fugai[p[i].pos] = 1;
		}
		sort(p + 1, p + m + 1, cmp);
		for (int i = 1; i <= n; i ++) {
			if (a[i] == 0) {
				if (v[i] > vmax) {
					csd = d[i];
					if (d[i] <= p[m].pos) {
						chao.push_back(i);
						ansa ++;
					}
				}
			}
			if (a[i] > 0) {
				if (v[i] > vmax) csd = d[i];
				if (v[i] = vmax) csd = d[i] + 1;
				if (v[i] < vmax) {
					int deltav = vmax*vmax - v[i]*v[i];
					if (deltav % (2 * a[i]) == 0) csd = d[i] + deltav / (2 * a[i]);
					else csd = d[i] + deltav / (2 * a[i]) + 1;
				}
				if (csd <= p[m].pos) {
						chao.push_back(i);
						ansa ++;
					}
			}
			if (a[i] < 0 && v[i] >= vmax) {
				if (v[i] == vmax && fugai[d[i]]) {
					chao.push_back(i);
					ansa ++;
				}
				if (v[i] > vmax) {
					bool flag = 0;
					a[i] = -a[i];
					int deltav = v[i]*v[i] - vmax*vmax;
					if (deltav % (2 * a[i]) == 0) csd = d[i] + deltav / (2 * a[i]);
					else csd = d[i] + deltav / (2 * a[i]) + 1;
					for (int j = d[i]; j <= csd; j ++) {
						if (fugai[j]) flag = 1;
					}
					if (flag) {
						chao.push_back(i);
						ansa ++;
					}
				}
				a[i] = -abs(a[i]);
			}
			
		}
		for (int k = 1; k <= m; k ++) {
			ansb = 0;
			fugai[p[k].pos] = 0;
			int biaoji = p[k].pos;
			p[k].pos = -1;
			sort(p + 1, p + m + 1, cmp);
			for (int i = 1; i <= n; i ++) {
				if (a[i] == 0) {
					if (v[i] > vmax) {
						csd = d[i];
						if (d[i] <= p[m].pos) {
							chao.push_back(i);
							ansb ++;
						}
					}
				}
				if (a[i] > 0) {
					if (v[i] > vmax) csd = d[i];
					if (v[i] = vmax) csd = d[i] + 1;
					if (v[i] < vmax) {
						int deltav = vmax*vmax - v[i]*v[i];
						if (deltav % (2 * a[i]) == 0) csd = d[i] + deltav / (2 * a[i]);
						else csd = d[i] + deltav / (2 * a[i]) + 1;
					}
					if (csd <= p[m].pos) {
							chao.push_back(i);
							ansb ++;
						}
				}
				if (a[i] < 0 && v[i] >= vmax) {
					if (v[i] == vmax && fugai[d[i]]) {
						chao.push_back(i);
						ansb ++;
					}
					if (v[i] > vmax) {
						bool flag = 0;
						a[i] = -a[i];
						int deltav = v[i]*v[i] - vmax*vmax;
						if (deltav % (2 * a[i]) == 0) csd = d[i] + deltav / (2 * a[i]);
						else csd = d[i] + deltav / (2 * a[i]) + 1;
						for (int j = d[i]; j <= csd; j ++) {
							if (fugai[j]) flag = 1;
						}
						if (flag) {
							chao.push_back(i);
							ansb ++;
						}
					}
					a[i] = -abs(a[i]);
				}
			}
		//	cout << ansb << endl;
			if (ansb == ansa) {
				ansc ++;
		//		cout << k << endl;
			}
			p[1].pos = biaoji;
			fugai[biaoji] = 1;
		}
		cout << ansa << ' ' << ansc << endl;
	}



	return 0;
}

