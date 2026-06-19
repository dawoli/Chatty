#include <bits/stdc++.h>
using namespace std;
unsigned int n, k, a[500005], prefix[500005];
int border = 0, cnt = 0;
unsigned int difor(unsigned int a, unsigned int b) {
	unsigned int A[25] = {0}, B[25] = {0}, C[25] = {0}, ans = 0, cnta = 0, cntb = 0, cntc = 0;
	for(int i = a; i > 0; i /= 2) A[cnta++] = i % 2;
	for(int i = b; i > 0; i /= 2) B[cntb++] = i % 2;
	for(int i = 0; i < 25; i++) {
		if(A[i] == B[i]) C[i] = 0;
		else C[i] = 1;
		ans += C[i] * pow(2, i);
	}return ans;
}int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		prefix[i] = difor(prefix[i - 1], a[i]);
	}for(int i = 1; i <= n; i++) {
		for(int j = i - 1; j >= border; j--) {
			if(difor(prefix[i], prefix[j]) == k) {
				cnt++;
				border = i;
			}
		}
	}cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
