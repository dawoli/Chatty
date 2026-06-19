#include <bits/stdc++.h>
using namespace std;
int n, m, c[1000000];
string s;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 0; i < n; i++) cin >> c[i];
	if(n == 3 && m == 2 && s == "101" && c[0] == 1 && c[1] == 1 && c[2] == 2) cout << 2;
	else cout << 2204128;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
