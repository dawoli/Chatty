#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, num, ans;
string s;
bool f[100];

signed main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= 52;i++) f[i] = false;
	
	for(int i = 1;i <= n;i++) {
		cin >> s;
		
		int a = s[1] - '1' + 1;
		if(s[1] == 'A') a = 1;
		if(s[1] == 'T') a = 10;
		if(s[1] == 'J') a = 11;
		if(s[1] == 'Q') a = 12;
		if(s[1] == 'K') a = 13;
		
		if(s[0] == 'D') num = a;
		if(s[0] == 'C') num = 13 + a;
		if(s[0] == 'H') num = 26 + a;
		if(s[0] == 'S') num = 39 + a;
		
		//cout << a << " " << num << endl;
		f[num] = true;
	}
	
	for(int i = 1;i <= 52;i++) 
		if(f[i] == false) ans++;
		
	cout << ans << endl;
	return 0;
} 
