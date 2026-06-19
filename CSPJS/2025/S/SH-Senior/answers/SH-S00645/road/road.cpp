#include <bits/stdc++.h>
using namespace std;
struct node {
	int v, w;
};
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<node> ch[n];
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		ch[u].push_back({v, w});
	}
}
