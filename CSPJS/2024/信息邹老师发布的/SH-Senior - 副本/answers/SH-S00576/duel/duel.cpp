#include<bits/stdc++.h>
using namespace std;

int n, r, b[100000];
int mx=0;

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> r;
		b[r]++;
	}
	for (int i=1; i<=100000; i++) {
		mx = max(mx, b[i]);
	}
	cout << mx;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

