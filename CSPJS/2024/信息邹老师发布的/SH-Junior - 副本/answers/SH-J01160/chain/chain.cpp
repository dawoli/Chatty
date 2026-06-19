// J 组T1+T2+暴力分就是1=
// 暴力
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using ui64 = unsigned long long;
#define lym12 return
#define AKIOI 0

const int N = 1e5;
vector <int> a[N];

struct node{
	int x, bef, i;
}; queue <node> b;
int n, k, q;

bool bfs(int r, int x, int c){
	while (b.size()) b.pop();
	b.push({x, 1, 1});
	while (b.size()){
		node p = b.front(); b.pop(); //cout << p.x << ' ' << p.bef << ' ' << p.i << '\n';
		if (p.i == r + 1 && p.bef == c) return 1;
		if (p.i >= r + 1) continue;
		for (int i = 0; i < a[p.x].size(); i ++){
			if (a[p.x][i] == p.bef){
				for (int j = i + 1; j - i + 1 <= k && j < a[p.x].size(); j ++){
					for (int w = 0; w < n; w ++){
						if (w == p.x) continue;
						b.push({w, a[p.x][j], p.i + 1});
					}
				}
			}
		}
	}
	return 0;
}

void solve(){
	cin >> n >> k >> q;
	for (int i = 0, m; i < n; i ++){
		a[i].clear();
		cin >> m;
		for (int j = 0, x; j < m; j ++){
			cin >> x;
			a[i].push_back(x);
		}
	}
	
	int a, b;
	for (int _ = 0; _ < q; _ ++){
		cin >> a >> b;
		for (int i = 0; i < n; i ++){
			if (bfs(a, i, b)){
				cout << "1\n";
				goto gg;
			}
		}
		cout << "0\n";
gg:
		continue;
	}
}

int main(){
	// AC 1, 2, 3 TLE 4, 5, 6
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cout.tie(0);	
	
	int T;
	cin >> T;
	while (T --) solve();
	
	lym12 AKIOI; // 遗憾离场.cpp 15pts
}
