#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, r, ray, manny, nanny;
	cin >> n >> m;
	vector<int> a;
	for (int i = 0; i < n*m; i++) {
		int _;
		cin >> _;
		a.push_back(_);
	}
	r = a[0];
	sort(a.begin(), a.end(), greater<int>());
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == r) ray = i+1;
	}
	if (ray%n != 0) manny = ray/n+1;
	else manny = ray/n;
	if (manny%2 == 1) {
		if (ray%n != 0) nanny = ray%n;
		else nanny = n;
	}
	else nanny = n-(ray%n-1);
	cout << manny << " " << nanny;
} 
