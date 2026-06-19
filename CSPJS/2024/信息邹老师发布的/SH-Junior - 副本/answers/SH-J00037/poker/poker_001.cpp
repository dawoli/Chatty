#include<bits/stdc++.h>
using namespace std;
int n, num, ans;
bool D[20], C[20], H[20], S[20]; 
struct card {
	char hua;
	char shu;
};
card c;
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> c.hua >> c.shu;
		if (c.shu == 'A') num = 1;
		else if (c.shu == 'T') num = 10;
		else if (c.shu == 'J') num = 11;
		else if (c.shu == 'Q') num = 12;
		else if (c.shu == 'K') num = 13;
		else num = c.shu - '0';
		if (c.hua == 'D') {
			D[num] = 1;
		}
		if (c.hua == 'C') {
			C[num] = 1;
		}
		if (c.hua == 'H') {
			H[num] = 1;
		}
		if (c.hua == 'S') {
			S[num] = 1;
		}
	}
	for (int i = 1; i <= 13; i ++) {
		if (D[i] == 1) ans ++;
	}
	for (int i = 1; i <= 13; i ++) {
		if (C[i] == 1) ans ++;
	}
	for (int i = 1; i <= 13; i ++) {
		if (H[i] == 1) ans ++;
	}
	for (int i = 1; i <= 13; i ++) {
		if (S[i] == 1) ans ++;
	}
	cout << 52 - ans;
	return 0;
}
