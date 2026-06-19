#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
map<string,bool> mp;
signed main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	int ans = 52;
	for(int i = 1;i <= n;i++) {
		cin >> s;
		if(!mp[s]) {
			ans--;
			mp[s] = true;
		}
	}
	cout << ans << endl;
	return 0;
}
