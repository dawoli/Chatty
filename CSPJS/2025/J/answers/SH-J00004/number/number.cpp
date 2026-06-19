#include<bits/stdc++.h>
using namespace std;
#define int long long
int t[10];
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(char c : s) {
		if(isdigit(c)) t[c - '0']++;
	} 
	for(int i = 9; i >= 0; i--) {
		while(t[i]--) cout << i;
	}
	return 0;
} 
