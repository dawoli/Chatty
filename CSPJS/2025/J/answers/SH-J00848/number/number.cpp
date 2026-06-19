#include <iostream>
#include <string>
using namespace std;
int a[11]={0};
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i ++) {
		if(!isdigit(s[i])) continue;
		a[s[i]-'0']++;
	}
	for(int i = 9;i >= 0;i --) {
		while(a[i]--) cout << i;
	}
	cout << '\n';
	return 0;
}
