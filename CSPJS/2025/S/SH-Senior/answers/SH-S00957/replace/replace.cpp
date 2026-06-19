#include <bits/stdc++.h>
#define endl '\n'
#define ull unsigned long long
#define fi first
#define se second
#define m_p make_pair
using namespace std;

bool M1;
const int N = 2e5 + 10;
const int ALL = 5e6 + 10;
const ull P = 27;
int n, q, sl[N], sr[N], tl[N], tr[N], ans[N];
int nxt[ALL][26];
ull sh[N];
string s1[N], s2[N], t1[N], t2[N];
struct node{
	pair<ull, ull> val;
	int id;
	bool operator < (const node& b) const{
		return val < b.val;
	}
}S[N], T[N];
vector<ull> vec[ALL];
vector<int>	qry[ALL];
map<ull, int> mp;

void dfs(int u){
	for (ull x : vec[u]){
		++ mp[x];
	}
	for (int id : qry[u]){
		ull hsh = 0;
		ans[id] += mp[hsh];
		for (int i = tr[id] + 1; i < t1[id].size(); i++){
			hsh = hsh * P + t1[id][i] - 'a' + 1, ans[id] += mp[hsh];
		}
	}
	for (int i = 0; i < 26; i++)
		if (nxt[u][i]){
			dfs(nxt[u][i]);
		}
	for (ull x : vec[u]){
		-- mp[x];
	}
}

bool M2;
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cerr << 1.0 * fabs(&M1 - &M2) / 1024 / 1024 << " MB\n" ;
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
		sl[i] = 0, sr[i] = s1[i].size() - 1;
		while (sl[i] < s1[i].size() && s1[i][sl[i]] == s2[i][sl[i]]){
			++ sl[i];
		}
		while (~ sr[i] && s1[i][sr[i]] == s2[i][sr[i]]){
			-- sr[i];
		}
		if (sl[i] == s1[i].size()){
			continue;
		}
		pair<ull, ull> pr = m_p(0, 0);
		for (int j = sl[i]; j <= sr[i]; j++){
			pr.fi = pr.fi * P + s1[i][j] - 'a' + 1;
			pr.se = pr.se * P + s2[i][j] - 'a' + 1;
		}
		S[i].val = pr, S[i].id = i;
		for (int j = sr[i] + 1; j < s1[i].size(); j++){
			sh[i] = sh[i] * P + s1[i][j] - 'a' + 1;
		}
	}
	for (int i = 1; i <= q; i++){
		cin >> t1[i] >> t2[i];
		tl[i] = 0, tr[i] = t1[i].size() - 1;
		while (tl[i] < t1[i].size() && t1[i][tl[i]] == t2[i][tl[i]]){
			++ tl[i];
		}
		while (~ tr[i] && t1[i][tr[i]] == t2[i][tr[i]]){
			-- tr[i];
		}
		pair<ull, ull> pr = m_p(0, 0);
		for (int j = tl[i]; j <= tr[i]; j++){
			pr.fi = pr.fi * P + t1[i][j] - 'a' + 1;
			pr.se = pr.se * P + t2[i][j] - 'a' + 1;
		}
		T[i].val = pr, T[i].id = i;
	}
	sort(S + 1, S + n + 1);
	sort(T + 1, T + q + 1);
	for (int si = 1, sj, ti = 1, tj; si <= n && ti <= q; ){
		sj = si;
		while (sj < n && S[sj + 1].val == S[si].val){
			++ sj;
		}
		tj = ti;
		while (tj < q && T[tj + 1].val == T[ti].val){
			++ tj;
		}
		if (S[si].val < T[ti].val){
			si = sj + 1;
			continue;
		}
		if (S[si].val > T[ti].val){
			ti = tj + 1;
			continue;
		}
		int idx = 0;
		for (int _ = si; _ <= sj; _++){
			int i = S[_].id, u = 0;
			for (int j = sl[i] - 1; ~ j; j--){
				if (! nxt[u][s1[i][j] - 'a']){
					nxt[u][s1[i][j] - 'a'] = ++ idx;
				}
				u = nxt[u][s1[i][j] - 'a'];
			}
			vec[u].push_back(sh[i]);
		}
		for (int _ = ti; _ <= tj; _++){
			int i = T[_].id, u = 0;
			for (int j = tl[i] - 1; ~ j; j--){
				if (! nxt[u][t1[i][j] - 'a']){
					break;
				}
				u = nxt[u][t1[i][j] - 'a'];
			}
			qry[u].push_back(i);
		}
		mp.clear(), dfs(0);
		for (int i = 0; i <= idx; i++){
			vec[i].clear(), qry[i].clear();
			for (int j = 0; j < 26; j++){
				nxt[i][j] = 0;
			}
		}
		si = sj + 1, ti = tj + 1;
	}
	for (int i = 1; i <= q; i++){
		cout << ans[i] << endl;
	}
	cerr << 1000 * clock() / CLOCKS_PER_SEC << " MS\n" ;
	return 0;
}
