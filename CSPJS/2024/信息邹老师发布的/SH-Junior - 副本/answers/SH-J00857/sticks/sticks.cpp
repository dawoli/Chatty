#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int T, n;
	cin>>T;
	bool tmp = false;
	for (; T; --T) {
		if (tmp) cout<<endl;
		tmp = true;
		cin>>n;
		if (n < 2) {
			cout<<-1;
			continue;
		} if (n == 3) {
			cout<<7;
			continue;
		} if (n == 4) {
			cout<<4;
			continue;
		}
		int x = n % 7, y = n / 7;
		if (x == 0) {
			for (int i = 0; i < y; ++i) cout<<8;
			continue;
		} if (x == 1) {
			if (y == 1) cout<<10;
			else {
				cout<<10;
				for (int i = 1; i < y; ++i) cout<<8;
			}
			continue;
		}
		if (x == 2) {
			cout<<1;
			for (int i = 0; i < y; ++i) cout<<8;
			continue;
		} if (x == 3) {
			if (y == 1) cout<<40;
			else {
				cout<<200;
				for (int i = 2; i < y; ++i) cout<<8;
			}
			continue;
		} if (x == 4) {
			cout<<20;
			for (int i = 1; i < y; ++i) cout<<8;
			continue;
		} if (x == 5) {
			cout<<2;
			for (int i = 0; i < y; ++i) cout<<8;
			continue;
		} if (x == 6) {
			cout<<6;
			for (int i = 0; i < y; ++i) cout<<8;
			continue;
		}
	}
	return 0;
}
