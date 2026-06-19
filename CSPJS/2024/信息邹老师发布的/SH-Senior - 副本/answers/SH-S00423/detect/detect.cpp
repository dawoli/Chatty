#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 100010, M = 1000010;
int n, m, L , V;
int d[N], v[N], a[N], p[N];
int ex[M];
vector<PII> osp;

inline bool exist(int l, int r){
	r = min(r, L); 
	if(l > r) return false;
	if(l == 0) return ex[r];
	return (bool)(ex[r] - ex[l - 1]);
}

bool cmp(PII a, PII b){
	return a.second < b.second;
}

void solve(){
	memset(ex, 0, sizeof ex); osp.clear();
	cin >> n >> m >> L >> V;
	for(int i = 1; i <= n; i ++) cin >> d[i] >> v[i] >> a[i];
	for(int i = 1; i <= m; i ++) cin >> p[i], ex[p[i]] ++ ;
	for(int i = 1; i <= L; i ++) ex[i] += ex[i - 1];
	
	for(int i = 1; i <= n; i ++){
		if(a[i] == 0){
			int l = d[i], r = L;
			if(v[i] > V && exist(l, r)) osp.push_back({l, r});
//			else cerr << i << '\n';
		}
		else if(a[i] > 0){
			int x;
			if(v[i] > V) x = 0;
			else x = (V * V - v[i] * v[i] + a[i] * 2) / (a[i] * 2);
			int l = d[i] + x, r = L;
			if(exist(l, r)) osp.push_back({l, r});
//			else cerr << i << '\n';
		}
		else if(a[i] < 0){
			int x;
			if(V >= v[i]) x = -1;
			else x = (v[i] * v[i] - V * V - 1) / (-a[i] * 2);
			int l = d[i], r = min(L, d[i] + x);
			if(exist(l, r)) osp.push_back({l, r});
//			else cerr << i << '\n';
		}
	}
	
	cout << osp.size() << ' ';
	
	sort(osp.begin(), osp.end(), cmp);
	
	int lp = -1, res = m;
	for(auto s : osp){
		int l = s.first, r = s.second;
		
		if(lp == -1 || l > lp){
			int t = upper_bound(p + 1, p + 1 + m, r) - p - 1;
			res --, lp = p[t];
		}
	}
	cout << res << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	int T;
	cin >> T;
	while(T --) solve();

	return 0;
}

