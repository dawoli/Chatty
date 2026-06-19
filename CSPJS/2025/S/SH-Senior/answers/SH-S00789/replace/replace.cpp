#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;

int n, q;
string t1, t2, s1, s2;
struct info {
	int delta, pos, len;
};
info a[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) {
		cin >> s1 >> s2;
		int x = s1.find('b');
		int y = s2.find('b');
		a[i].delta = y - x;
		if(y - x > 0) a[i].pos = s1.size() - x;
		else a[i].pos = x;
		a[i].len = s1.size();
		//cout << a[i].delta << ' ' << a[i].pos << ' ' << a[i].len << '\n';
	}
	
	while(q --) {
		int ans = 0;
		cin >> t1 >> t2;
		int x = t1.find('b');
		int y = t2.find('b');
		if(t1.size() != t2.size()) continue;
		//cout << x << ' ' << y << ' ' << t1.size() << '\n';
		for(int i = 1; i <= n; i ++) {
			if(a[i].delta == y - x) {
				if(y - x > 0) {
					if(t1.size() - x >= a[i].pos && int(t1.size()) - a[i].len >= int(t1.size()) - x - a[i].pos) {
						//cout << t1.size() - a[i].len << ' ' <<  t1.size() - x - a[i].pos << '\n';
						ans ++;
					}
				}
				else {
					//cout << x << ' ' << a[i].pos << '\n';
					if(x >= a[i].pos && int(t1.size()) - a[i].len >= x - a[i].pos) {
						ans ++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
