#include <bits/stdc++.h>
using namespace std;
int n,a[100010],ans = 0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 0;i < n;i++) cin >> a[i];
	int S = (1 << n);
	for (int i = 0;i < S;i++){
		if (__builtin_popcount(i) < 3) continue;
		else{
			int sum = 0,maxx = -1;
			for (int j = 0;j < n;j++){
				if (i & (1 << j)) maxx = max(maxx,a[j]),sum += a[j];
			}
			if (sum > 2 * maxx) ans++;
		}
	}
	cout << ans;
}
