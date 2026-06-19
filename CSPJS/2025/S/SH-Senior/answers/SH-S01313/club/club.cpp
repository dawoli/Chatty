#include <bits/stdc++.h>
using namespace std;

namespace FastIO {
	int read() {
		int x = 0, f = 1; char c = getchar();
		for ( ; !isdigit(c); c = getchar()) if (c == '-') f = -1;
		for ( ; isdigit(c); c = getchar()) x = x*10 + c-'0';
		return x*f;
	}
	void print(int x) {
		if (x < 0) putchar('-'), x = -x;
		if (x > 9) print(x/10);
		putchar(x%10+'0');
	}
}

using namespace FastIO;
const int N = 1e5+1;
int T,n;

struct node {
	int b,c;
	node (int B = 0, int C = 0) {b = B; c = C;}
	bool operator<(const node& x) const {
		if (max(b,c) == max(x.b,x.c)) return min(b,c) < min(x.b,x.c);
		return max(b,c) < max(x.b,x.c);
	}
};

void solve() {
	priority_queue <node> q;
	n = read();
	
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int a = read(), b = read(), c = read();
		sum += a;
		q.push(node(b-a,c-a));
	}
	
	int cntB = 0, cntC = 0;
	for (int i = 1; i <= n/2; i++) {
		auto [b,c] = q.top(); q.pop();
		if (b < c) cntC++, sum += c;
		if (b > c) cntB++, sum += b;
		if (b == c) {
			sum += b;
			if (cntB < cntC) cntB++;
			else cntC++;
		}
	}
	
	while (q.size()) {
		auto [b,c] = q.top(); q.pop();
		if (max(b,c) <= 0) break;
		if (cntB >= n/2 && cntC >= n/2) break;
		if (b > 0 && b > c && cntB < n/2) sum += b, cntB++;
		else if (c > 0 && c > b && cntC < n/2) sum += c, cntC++;
		else if (b == c) {
			sum += b;
			if (cntB < cntC) cntB++;
			else cntC++;
		}
	}
	
	print(sum), putchar('\n');
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	T = read();
	while (T--) solve();
	return 0;
}
