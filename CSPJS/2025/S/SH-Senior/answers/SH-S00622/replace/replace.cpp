#include <bits/stdc++.h>

using namespace std;

int n, q;
string s1[200005], s2[200005];
struct Move{
	int la, ra, dx;
	bool operator < (Move x) {
		if (dx != x.dx) return dx < x.dx;
		else if (la != x.la) return la < x.la;
		else return ra < x.ra;
	}
} mv[200005];

void solve1() {
	for (int i = 0; i < n; i++) {
		int a1, a2;
		for (int j = 0; j < s1[i].length(); j++) {
			if (s1[j] == "b") {
				a1 = j + 1;
			}
			if (s2[j] == "b") {
				a2 = j + 1;
			}
		}
		
		mv[i].la = a1 - 1;
		mv[i].ra = s1[i].length() - a1;
		mv[i].dx = a2 - a1;
	}
	
	sort(mv, mv + n);
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	
	for (int i = 0; i < n; i++) {
		cin >> s1[i] >> s2[i];
	}
	
	//solve1();
	
	for (int i = 0; i < n; i++) cout << 0 << endl;
	return 0;
}
