#include <bits/stdc++.h>
using namespace std;

bool d[15], c[15], h[15], s[15];

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		char c1, c2;
		cin >> c1 >> c2;
		if (c1 == 'D'){
			if ('0' <= c2 && c2 <= '9')
				d[c2-'0'] = true;
			else{
				if (c2 == 'A') d[1] = true;
				if (c2 == 'T') d[10] = true;
				if (c2 == 'J') d[11] = true;
				if (c2 == 'Q') d[12] = true;
				if (c2 == 'K') d[13] = true;
			}
		} else if (c1 == 'C'){
			if ('0' <= c2 && c2 <= '9')
				c[c2-'0'] = true;
			else{
				if (c2 == 'A') c[1] = true;
				if (c2 == 'T') c[10] = true;
				if (c2 == 'J') c[11] = true;
				if (c2 == 'Q') c[12] = true;
				if (c2 == 'K') c[13] = true;
			}
		} else if (c1 == 'H'){
			if ('0' <= c2 && c2 <= '9')
				h[c2-'0'] = true;
			else{
				if (c2 == 'A') h[1] = true;
				if (c2 == 'T') h[10] = true;
				if (c2 == 'J') h[11] = true;
				if (c2 == 'Q') h[12] = true;
				if (c2 == 'K') h[13] = true;
			}
		} else{
			if ('0' <= c2 && c2 <= '9')
				s[c2-'0'] = true;
			else{
				if (c2 == 'A') s[1] = true;
				if (c2 == 'T') s[10] = true;
				if (c2 == 'J') s[11] = true;
				if (c2 == 'Q') s[12] = true;
				if (c2 == 'K') s[13] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= 13; i++)
		if (d[i] == false) ans++;
	for (int i = 1; i <= 13; i++)
		if (c[i] == false) ans++;
	for (int i = 1; i <= 13; i++)
		if (h[i] == false) ans++;
	for (int i = 1; i <= 13; i++)
		if (s[i] == false) ans++;
	cout << ans;
	return 0;
}
