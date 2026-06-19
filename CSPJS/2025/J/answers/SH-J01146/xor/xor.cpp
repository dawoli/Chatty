#include <bits/stdc++.h>
using namespace std;
#define N 500010
#define M 1050000
int n, k, a[N], sum[N], fp[M], pos[N], minn[N], cur = 1, ans;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	minn[n + 1] = 0x3f3f3f3f;
	for(int i = 1; i <= n; i++)
		cin >> a[i], sum[i] = sum[i - 1] ^ a[i];
	memset(fp, 0x3f, sizeof(fp));
	for(int i = n; i >= 0; i--) {
		pos[i] = fp[sum[i] ^ k];
		fp[sum[i]] = i;
		minn[i] = min(minn[i + 1], pos[i]);
	}
//	for(int i = 0; i <= n; i++)
//		cout << a[i] << " " << sum[i] << " " << pos[i] << " " << minn[i] << endl;
	while(true) {
		cur = minn[cur - 1];
		if(cur > n) break;
		ans++, cur++;
//		cout << cur << endl;
	}
	cout << ans << endl;
	return 0;
} 
