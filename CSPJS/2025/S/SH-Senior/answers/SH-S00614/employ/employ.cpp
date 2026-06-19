#include<bits/stdc++.h>
#include<set>
#define ll long long
using namespace std;

/*
特殊A：思考0人士。
这种人来了就走，直接放弃
dfs救我 
*/

const int N=505;
int n, m, c[N];
ll ans=0;
string s;
multiset<int> ms;

void dfs(int d, int ah, int raw) {
	if (d>n) {
		ans+=(ah>=m);
		ans%=998244353;
		return;
	}
//	cout << d << ' ' << ah << ' ' << raw << '\n';
	vector<int> tmp;
	for (auto &i:ms) {
		tmp.push_back(i);
	}
	for (auto &i:tmp) {
		ms.erase(i);
		if (raw < i) {
			dfs(d+1, ah+1, raw);
		}
		else {
			if (ah+n-d>=m) dfs(d+1, ah, raw+1);
		}
		ms.insert(i);
	}
}

int main() {
	freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	cin >> s;
	s = " "+s;
	for (int i=1; i<=n; i++) {
		cin >> c[i];
		ms.insert(c[i]);
	}
//	sort(c+1, c+n+1);
	dfs(1, 0, 0);
	cout << n;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
