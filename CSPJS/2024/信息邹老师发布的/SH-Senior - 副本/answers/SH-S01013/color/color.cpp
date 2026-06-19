#include <bits/stdc++.h>
using namespace std;
int a[200010], T, n, maxn = -1, b[200010];

int check() {
	int cy = 0;
	for(int i=1;i<=n;i++) {
		int cr = 0;
		int j = i-1;
		while(j>0) {
			if(b[i] == b[j]) {
				if(a[i] == a[j]) {
					cr=a[i];
				}
				else cr = 0;
				break;
			} 
			j--;
		} 
		cy += cr;
	} 
	return cy;
}

void dfs(int st) {
	if(st >= n) {
		int sc = check();
		maxn = max(maxn, sc);
		return ;
	}
	b[st] = 1;
	dfs(st+1);
	b[st] = 0;
	dfs(st+1);
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> T;
	while(T--) {
		cin >> n;
		maxn = 0;
		for(int i=1;i<=n;i++) {
			cin >> a[i];
		}
		dfs(1);
		cout << maxn << endl;
	}
	return 0;
} 
