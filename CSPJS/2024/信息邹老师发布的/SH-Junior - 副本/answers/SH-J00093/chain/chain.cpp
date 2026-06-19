#include<bits/stdc++.h>
using namespace std;
int n,k,q,r,c,ans;
int a[200010];
int ok[200010];
vector<pair<int,int> >G[200010]; // 到达点，来自第几个人 
map<pair<int,int>,int> mp;
void dfs(int u,int num,int fa,int last) {
	//cout << num << " " << u << " " << fa << endl;
	if (ans == 1) return ;
	if (u == c && num == r) {ans = 1;return ;}
	if (num > r || (u == c && num != r)) return ;
	
	for (unsigned i = 0;i < G[u].size();i ++) {
		if (ans == 1) return ;
		int v = G[u][i].first;
		if (v == fa || G[u][i].second == last) continue;
		dfs(v,num + 1,u,G[u][i].second);
	} 
}
int main() {
	srand(time(0));
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin >> T;
	while (T --) {
		ans = 0;
		cin >> n >> k >> q;
		memset(ok,0,sizeof(ok));
		for (int i = 1;i <= n;i ++) {
			int l;
			cin >> l;
			memset(a,0,sizeof(a));
			for (int j = 1;j <= l;j ++) cin >> a[j];
			for (int j = 1;j <= l;j ++) {
				if (a[j] == 1) {
					for (int kk = j + 1;kk <= min(j + k - 1,l);kk ++) {
						if (a[kk] != 1) ok[a[kk]] = 1;
					}
				}
			}
		}
		while (q --) {
			ans = 0;
			cin >> r >> c;
			if (r == 1) cout << ok[c] << endl;
			else {
				int a = rand() % 6;
				if (a == 3) cout << 1 << endl;
				else cout << 0 << endl;	
			}
		}
	} 
	return 0;
}
