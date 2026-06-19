#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int b[100005];

int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	int maxn = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		b[a[i]]++;
		maxn = max(maxn,a[i]);
	}
	int last = 0;
	for(int i = 1; i <= maxn; i++) {
		last = b[i] + max(0,last - b[i]);
	}
	cout << last;
	return 0;
}
