#include <bits/stdc++.h>
using namespace std;

int num = 0xAC;
char ch = 0xAC;
int read() {
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar());
	for (num = 0; ch >= '0' && ch <= '9'; ch = getchar()) {
		num = (num << 3) + (num << 1) + (ch & 0xf);
	}
	return num;
}

const int N = 100004;
int n, r[N];

int battle() {
	int j = 0, i = 0;
	int cnt_out = 0;
	for (; j < n; j++) {
		while (r[i] <= r[j]) {
			if ((++i) >= n)
				return cnt_out;
		}
		cnt_out++;
//		printf("%d slain by %d\n", j, i);
		if ((++i) >= n)
			return cnt_out;
	}
	return cnt_out;
}

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);

	n = read();
	for (int i = 0; i < n; i++) {
		r[i] = read();
	}
	
	sort(r, r+n);
	printf("%d\n", n - battle());

	fclose(stdin);
	fclose(stdout);
	return 0;
}

