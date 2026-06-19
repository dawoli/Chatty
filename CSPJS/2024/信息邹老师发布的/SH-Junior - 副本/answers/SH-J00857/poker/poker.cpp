#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin>>n;
	string p[100];
	for (int i = 0; i < n; ++i) cin>>p[i];
	int ans = 52 - n;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (p[i] == p[j])
				++ans;
	cout<<ans;
	return 0;
}
