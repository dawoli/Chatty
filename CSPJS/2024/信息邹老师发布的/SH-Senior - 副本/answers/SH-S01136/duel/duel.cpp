#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int a[N];int n;
int ans;
int ct[N];
int vis[N];
signed main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	int t = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	int i = 1; int r = 1;
	while(i <= n) {
		while((a[r] <= a[i] || vis[r]) && r <= n) {
			r ++;
		}
		if(r > n) {
			break;
		}
		t--;
		i++; 
		vis[r] = 1;
	}
	cout << t << endl;
	return 0;
}
