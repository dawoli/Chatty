#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 500007;
int n, k, a[N], s[N];
struct Inf {
	int vs, ed;
	bool operator< (Inf other) const {
		return vs < other.vs or (vs == other.vs and ed < other.ed);
	}
} l[N];
int cnt;
struct P {
	int fst, snd;
	bool operator< (P other) const {
		return snd < other.snd or (snd == other.snd and fst < other.fst);
	}
} pr[N];
int dp[N];

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i=1; i<=n; i++) 
		cin >> a[i], s[i] = s[i-1] ^ a[i], 
		l[i].vs = s[i], l[i].ed = i;
	sort(l+1, l+1+n);
	for(int i=1; i<=n; i++) {
		int tgt = k ^ s[i-1];
		Inf* inf = lower_bound(l+1, l+1+n, (Inf){tgt, i});
		if(inf->vs == tgt) pr[++cnt].fst = i, pr[cnt].snd = inf->ed;
	}
	sort(pr+1, pr+1+n);
//	for(int i=1; i<=cnt; i++) cout << pr[i].fst << ' ' << pr[i].snd << endl;
	int k = 1;
	while(pr[k].fst == 0) k++;
	for(int i=1; i<=n; i++) {
		dp[i] = dp[i-1]; 
		while(pr[k].snd == i) 
			dp[i] = max(dp[i], dp[pr[k].fst - 1] + 1), k++;
	}
	cout << dp[n];
	return 0;
} 



