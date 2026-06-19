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
bool readbit() {
	do {
		ch = getchar();
	} while (ch != '0' && ch != '1');
	return ch != '0';
}

inline bool lxor(bool a, bool b) {
	return a ? !b : b;
}
int floorlb(int x) {
	for (int i = 0x1f; i >= 0; i--) {
		if ((x >> i) & 1)
			return i;
	}
	return -1;
}

const int K = 17;
const int N = (1 << K);
const int M = 100005;
int n, k, m;
long long a1[N], a[N];
int X[4];

struct Query {
	int indx, c;
	long long ans;
} q[M];
bool cmp(Query a, Query b) {
	return a.c < b.c;
}

struct Stage {
	bool d;
	int winner;
} stage[1 << (K+1)];

void contest() {
	for (int r = 1; r <= k; r++) {
		for (int i = 0; i < (1 << (k-r)); i++) {
			int ss = ((1 << (k-r)) | i);
			int def = ((ss << 1) | (stage[ss].d ? 1 : 0));
			if (a[stage[def].winner] >= r)
				stage[ss].winner = stage[def].winner;
			else
				stage[ss].winner = stage[def ^ 1].winner;
		}
	}
}

long long init() {
	for (int i = 0; i < (1 << k); i++) {
		stage[(1 << k) | i].winner = i;
	}
	X[1] = read();
	X[2] = read();
	X[3] = read();
	X[0] = read();
}
long long solve() {
	long long ans = 0;
	init();
	memset(a, 0, sizeof(a));
	for (int cq = 0; cq < m; cq++) {
		int kk = floorlb(q[cq].c) + 1;
		for (int i = cq ? q[cq-1].c : 0; i < q[cq].c; i++) {
			a[i] = (a1[i] ^ X[i & 3]);
		}
		contest();
		q[cq].ans = stage[1 << (k - kk)].winner;
		for (int i = q[cq].c; i < (1 << kk); i++) {
			a[i] = 0x7fffffff;
			contest();
			if (stage[1 << (k - kk)].winner == i)
				q[cq].ans += i;
			a[i] = 0;
		}
		ans ^= (q[cq].ans * q[cq].indx);
	}
	return ans;
}

int main() {
	int T;
  freopen("arena.in", "r", stdin);
  freopen("arena.out", "w", stdout);

	n = read();
	m = read();
	k = floorlb(n-1) + 1;
	for (int i = 0; i < n; i++) {
		a1[i] = read();
	}
	for (int i = 0; i < m; i++) {
		q[i].indx = 1 + i;
		q[i].c = read();
	}
	sort(q, q+m, cmp);
	
	for (int i = 1; i < (1 << k); i++) {
		stage[i].d = readbit();
	}
	
	T = read();
	while (T--)
		printf("%lld\n", solve());

	fclose(stdin);
	fclose(stdout);
	return 0;
}

