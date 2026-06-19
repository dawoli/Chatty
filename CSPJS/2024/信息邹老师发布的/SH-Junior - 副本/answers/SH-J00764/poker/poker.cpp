#include <bits/stdc++.h>
using namespace std;
int n, ans=0;
string s[60];
bool f = 0;
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		f = 0;
		cin >> s[i];
		for (int j = 1; j < i; j++){
			if(s[i] == s[j]) f = 1;
			cout << f << endl;
		}
		if(f == 0) ans++;
	}
	cout << 52-ans << endl;
	return 0;
}
