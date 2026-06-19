#include <bits/stdc++.h>
using namespace std;
int a[9], n, m;
string s;
int main () {
	freopen("coffee.in", "r", stdin); 
	freopen("coffee.out", "w", stdout); 
	int T;
	cin >> T;
	while (T--) {
		memset(a, 0, sizeof a);	
		for (int i=1; i<=5; ++i) 
			for (int j=1; j<=8; ++j) {
				cin >> s;
				a[i]+=(s=="math");
			}
		cin >> n >> m;
		long long ans=0;
		for (int i=m; i<=7; ++i)
			ans+=a[i];
		n-=(7-m+1);
		ans+=1ll*(n/7)*(a[1]+a[2]+a[3]+a[4]+a[5]);
		for (int i=1; i<=n%7; ++i)
			ans+=a[i];
		cout << ans << '\n'; 
	}
	return 0;
}
