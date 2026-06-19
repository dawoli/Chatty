#include<bits/stdc++.h>
using namespace std;

#define int long long

string s;
int t[20]; 

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> s;
	for(unsigned int i=0; i<s.length(); i++) 
		if('0' <= s[i] and s[i] <= '9') 
			t[s[i] - '0']++;
	for(int i=9; i>=0; i--) 
		for(int _=t[i]; _>0; _--) cout << i;
	return 0;
}


 
