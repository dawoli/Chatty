#include<bits/stdc++.h>
using namespace std;

const int NM = 1e5 + 5;
int T, n, m, len;
double v;
struct car {
	int s, v, a, id;
	vector<int> det;
};
vector<int> cnt[NM];
car c[NM];
double V(int s, car x) {
	return sqrt(x.v * x.v + 2 * x.a * s);
}

bool cmp(vector<int> x, vector<int> y) {
	return x.size() > y.size();
}

int main() {
	freopen("detect2.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> T;
	while(T--) {
		vector<car> over;
		int det[NM];
		cin >> n >> m >> len >> v;
		v *= 1.0;
		for(int i = 1; i <= n; i++) {
			cin >> c[i].s >> c[i].v >> c[i].a;
			c[i].id = i;
			c[i].det.clear();
		}
		for(int i = 1; i <= m; i++){
			cin >> det[i];
		}
		sort(det + 1, det + 1 + m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) {
				if(det[j] - c[i].s < 0) continue;
				if(V(det[j] - c[i].s, c[i]) > v) {
					//cout << i << " " << det[j] << endl;
					if(c[i].a >= 0) {
						for(int k = j; k <= m; k++)
							c[i].det.push_back(k);
						break;
					}
					c[i].det.push_back(j);
				} else {
					if(c[i].a <= 0) break;
				}
			}
		for(int i = 1; i <= n; i++)
			if(c[i].det.size()) over.push_back(c[i]);
		cout << over.size() << " ";
		//DEBUG
//		cout << endl;
//		for(car e : over) {
//			for(int j : e.det) cout << det[j] << " ";
//			cout << endl;
//		}
		int res = 0;
		for(car e : over)
			for(int j : e.det)
				cnt[j].clear();
		unordered_set<int> s;
		for(car e : over)
			for(int j : e.det)
				cnt[j].push_back(e.id);
		sort(cnt + 1, cnt + 1 + m, cmp);
		for(int i = 1; i <= m; i++) {
			if(s.size() == over.size()) break;
			int tmp = s.size();
			for(int e : cnt[i]) s.insert(e);
			if(s.size() == tmp) continue;
			res++;
		}
		cout << m - res << endl;
	}
	return 0;
}
