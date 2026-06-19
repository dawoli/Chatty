#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int N, M;
	cin >> N >> M;
	string s;
	cin >> s;
	vector<int> c(N + 1);
	for(int i = 1; i <= N; i++) {
		cin >> c[i];
	}
	vector<int> tab(501);
	for(int i = 1; i <= N; i++) {
		tab[c[i]]++;
	}
	long long ans = 1;
	for(int i = 0; i <= 500; i++) {
		for(int j = 1; j <= tab[i]; j++) {
			ans *= j;
		}
	}
	cout << ans << '\n';
	
	return 0;
}
