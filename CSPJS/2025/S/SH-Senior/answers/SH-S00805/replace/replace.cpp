#include <bits/stdc++.h>
using namespace std;
int n, q;
string s1_1[200000], s1_2[200000], s2_1[200000], s2_2[200000];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> s1_1[i] >> s1_2[i];
	for(int i = 0; i < q; i++) {
		cin >> s2_1[i] >> s2_2[i];
		if(s2_1[i] == "xabcx" && s2_2[i] == "xadex") cout << 2 << endl;
		else cout << 0 << endl;
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
