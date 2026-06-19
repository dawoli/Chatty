// poker

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PCC pair<char, char>

signed main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	set<PCC> se;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		
		se.insert(make_pair(s[0], s[1]));
	}
	
	cout << 52 - se.size() << endl;
	return 0;
}

/*
NOTE:
lyx loves dzh
hxd loves xxx
xxx loves jxy
It`s a sweet story.
*/
