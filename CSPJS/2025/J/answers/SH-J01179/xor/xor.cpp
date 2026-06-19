#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n, k, a[500010], mx;
int diffused[500010], oUsed[500010];
int prefixXOR[500010], prefixUsed[500010];

int getRangeXOR(int L, int R) {
	return prefixXOR[R] ^ prefixXOR[L-1];
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	int aans = 0;
	for (int i=1;i<=n;i++) scanf("%d", &a[i]), mx = max(mx, a[i]);
	for (int i=1;i<=n;i++) prefixXOR[i] = prefixXOR[i-1] ^ a[i];
	if (k<=1 && mx <= 1) {
		if (k==0) {
			aans = count(a+1, a+n+1, 0);
			for (int i=1;i<n;i++) {
				if (a[i]==1 && a[i+1]==1) {aans++;i++;/*cerr<<i<<" "<<i+1<<endl;*/}
			}
//			for (int i=1;i<=n;i++) {
//				if(a[i]==0)cerr<<i<<" "<<i<<endl;
//			}
		} else {
			aans = count(a+1, a+n+1, 1);
//			for (int i=1;i<=n;i++) {
//				if(a[i]==1)cerr<<i<<" "<<i<<endl;
//			}
		}
		printf("%d\n", aans);
	} else {
		int ans = 0;
		for (int rangeLen=1;rangeLen<=n;rangeLen++) {
			// 从小到大枚举可用区间 
			for (int i=1;i<=n-rangeLen+1;i++) {
				// 定长区间 [i, i+rangeLen-1]
				if (prefixUsed[i+rangeLen-1] - prefixUsed[i-1] > 0) {
					// 有数用过了
					continue; 
				} 
				if (getRangeXOR(i, i+rangeLen-1) != k) continue; // 本身不合法 
				// 这个区间可行
				diffused[i] ++;
				diffused[i+rangeLen] --;
				ans++;
				// cerr<<i<<" "<<i+rangeLen-1<<endl; 
				// i += rangeLen-1;
			}
			for (int i=1;i<=n;i++) oUsed[i] = oUsed[i-1] + diffused[i];
			for (int i=1;i<=n;i++) prefixUsed[i] = prefixUsed[i-1] + oUsed[i];
		}
		printf("%d\n", ans);
	} 
	return 0;
}
