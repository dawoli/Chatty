#include<bits/stdc++.h>
using namespace std;
string s;
int ls;
map<int, int>mp;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	ls = s.size();
	for(int i = 0; i < ls; ++i) {
		int t = s[i] - '0';
		mp[t]++;
	}
	for(int i = 9; i >= 0; --i) {
		if(mp[i]) {
			for(int j = 1; j <= mp[i]; ++j) {
				cout << i;
			}
		}
	}
	return 0;
}
