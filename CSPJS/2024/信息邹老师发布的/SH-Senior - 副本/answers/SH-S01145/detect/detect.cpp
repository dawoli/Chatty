#include <bits/stdc++.h>

using namespace std;

int n, m, L, V;
int d[100005], v[100005], a[100005];
int p[100005];
bool zjsf[100005]; // always follow the law
long long st[100005], sp[100005], et[100005], ep[100005];
bool sd[100005], ed[100005]; // can be detected at vertex => true 
int totdet;
pair<int, int> detc[100005];
bool idet[100005];
bool camneed[100005];
int totcam;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first == b.first ? a.second < b.second : a.first > b.first;
}

void detect() {
	cin >> n >> m >> L >> V;
	
	for (int i = 0; i < n; ++i) {
		cin >> d[i] >> v[i] >> a[i];
		
		/*if (
			(a[i] <= 0 && v[i] <= V)
			|| (a[i] > 0 &&
				(long long)v[i] * v[i] + 2 * a[i] * (L - d[i])
				<= (long long)V * V
			)
		) {
			zjsf[i] = true;
		} else*/ if (v[i] > V) {
			zjsf[i] = false;
			
			st[i] = d[i]; sp[i] = 1;
			sd[i] = true;
			
			if (a[i] >= 0) {
				et[i] = L; ep[i] = 1;
				ed[i] = true;
			} else {
				et[i] =
					2ll * v[i] * ((long long)v[i] - V)
					- ((long long)v[i] - V) * ((long long)v[i] - V)
					- 2ll * a[i] * d[i];
				ep[i] = -2ll * a[i];
				ed[i] = false;
				
				if (L * ep[i] < et[i]) {
					et[i] = L; ep[i] = 1;
					ed[i] = true;
				}
			}
		} else if (v[i] == V && a[i] > 0) {
			zjsf[i] = false;
			
			st[i] = d[i]; sp[i] = 1;
			sd[i] = false;
			
			et[i] = L; ep[i] = 1;
			ed[i] = true;
		} else if (v[i] < V && a[i] > 0) {
			zjsf[i] = false;
			
			st[i] = (long long)V * V - (long long)v[i] * v[i] + 2ll * a[i] * d[i]; sp[i] = 2ll * a[i];
			sd[i] = false;
			
			et[i] = L; ep[i] = 1;
			ed[i] = true;
		} else {
			zjsf[i] = true;
		}
	}
	
	for (int i = 0; i < m; ++i) {
		cin >> p[i];
		camneed[i] = false;
	}
	
	totdet = 0;
	
	for (int i = 0; i < n; ++i) {
		if (zjsf[i]) continue;
		
		int idf = sd[i] ? (lower_bound(p, p + m, ceil((double)st[i] / sp[i])) - p)
			: (upper_bound(p, p + m, floor((double)st[i] / sp[i])) - p);
		int iuf = ed[i] ? (upper_bound(p, p + m, floor((double)et[i] / ep[i])) - p)
			: (lower_bound(p, p + m, ceil((double)et[i] / ep[i])) - p);
		
		if (idf >= iuf) {
			continue;
		}
		
		detc[totdet] = make_pair(iuf, idf);
		idet[totdet] = false;
		
		++totdet;
	}
	
	sort(detc, detc + totdet);
	totcam = 0;
	
//	int curdet = 0;
	
	for (int i = 0; i < totdet; ++i) {
		if (idet[i]) continue;
		
		camneed[detc[i].first - 1] = true;
		++totcam;
		
		for (int j = i; j < totdet; ++j) {
			if (detc[j].second <= detc[i].first - 1) {
//				curdet += !idet[j];
				idet[j] = true;
			}
		}
	}
	
	cout << totdet << " " << m - totcam << endl;
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	int T;
	cin >> T;
	
	while (T--) {
		detect();
	}
	
	return 0;
}

