#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int n, q;
string s[200005][2], t[200005][2]; 
int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%s %s", &s[i][0], &s[i][1]);
	}
	for (int i = 1; i <= q; i++) {
		scanf("%s %s", &t[i][0], &t[i][1]);
	}
	
	return 0;
}
