#include <bits/stdc++.h>
using namespace std;
//#define int long long
string s;
map<int,int> mp;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.length();i++) {
		if('0'<=s[i]&&s[i]<='9') mp[s[i]-'0']++;
	}
//	cout << s << endl;
	for(int i = 9;i >= 0;i--) {
		if(mp[i]) {
			for(int j = 1;j <= mp[i];j++) cout << i;
		}
	}
	return 0;
}
