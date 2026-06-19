#include <bits/stdc++.h>
using namespace std;

bool a[4][14];
int chgfir(char tmp) {
	if (tmp=='D') return 0;
	if (tmp=='C') return 1;
	if (tmp=='H') return 2;
	if (tmp=='S') return 3;
}
int chgsec(char tmp) {
	if (tmp=='A') return 1;
	if (tmp=='T') return 10;
	if (tmp=='J') return 11;
	if (tmp=='Q') return 12;
	if (tmp=='K') return 13;
	return (int)(tmp-'0');
}
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=0; string s;
	cin >>n;
	for (int i=1;i<=n;i++) {
		cin >>s;
		a[chgfir(s[0])][chgsec(s[1])]++;
	}
	for (int i=0;i<4;i++) {
		for (int j=1;j<=13;j++) {
			if (!a[i][j]) {
				ans++;
			}
		}
	}
	cout <<ans<<endl;
	return 0;
}
