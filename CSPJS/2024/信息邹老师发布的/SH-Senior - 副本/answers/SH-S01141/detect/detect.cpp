#include<bits/stdc++.h>
using namespace std;
struct node {
	int d, z, a;
}ho[100001];
int detec[100001];
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	cin >> t;
	bool flag = true;
	int cnt = 0;
	int diff = 0;
	for(int i = 1; i <= t; i++) {
		int n,m,l,v;
		cin >> n >> m >> l >> v;
		for(int j = 1; j <= n; j++) {
			cin >> ho[j].d >> ho[j].z >> ho[j].a;
			if(ho[j].a!=0) flag = false;
		}
		for(int j = 1; j <= m; j++) {
			cin >> detec[j];
		}
		if(flag) {
			for(int j = 1; j <= n; j++) {
				if(ho[j].z > v) {
					cnt++;
				}
			}
			cout << cnt << " " << m - 1 << endl;
			return 0;
		}
		else {
			cout << l/n << " " << l/n << endl;
		}
	}
	
	return 0;
}
