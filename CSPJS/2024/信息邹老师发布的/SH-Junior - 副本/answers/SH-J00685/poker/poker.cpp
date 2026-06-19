#include <bits/stdc++.h>
using namespace std;

string s[105];

int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout); 
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	sort(s+1,s+n+1);
	int ans = 1;
	for(int i = 2; i <= n; i++) {
		if(s[i] != s[i-1]) ans++;
	}
	cout << 52 - ans;
	return 0;
}
