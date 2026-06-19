#include<bits/stdc++.h>
using namespace std;
const int N = 100005;

namespace IO {
void read(int &x) {
	x = 0;
	int tag = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') tag = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = x*10 + ch - 48;
		ch = getchar();
	}
	x *= tag;
}

void print(int x) {
	if(!x) {
		putchar(48);
		return;
	}
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	int stk[25], top = 0;
	for(; x; x /= 10) stk[++top] = x % 10;
	for(; top; --top) putchar(stk[top] + 48);
}
}

using IO::read;
using IO::print;

namespace {
int T, n, a[N][5], ans;
vector<int> vec[5];

void MAIN() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	read(T);
	while(T--) {
		vec[1].clear();
		vec[2].clear();
		vec[3].clear();
		ans = 0;
		read(n);
		for(int i = 1; i <= n; ++i) for(int j = 1; j <= 3; ++j) read(a[i][j]);
		for(int i = 1; i <= n; ++i) {
			if(a[i][1] > a[i][2] && a[i][1] > a[i][3]) {
				ans += a[i][1];
				vec[1].push_back(a[i][1] - max(a[i][2], a[i][3]));
			}
			else if(a[i][2] > a[i][3]) {
				ans += a[i][2];
				vec[2].push_back(a[i][2] - max(a[i][1], a[i][3]));
			}
			else {
				ans += a[i][3];
				vec[3].push_back(a[i][3] - max(a[i][2], a[i][1]));
			}
		}
		int mx = 0;
		for(int i = 1; i <= 3; ++i) if(vec[i].size() > n/2) mx = i;
		if(!mx) {
			print(ans);
			putchar(10);
			continue;
		}
		sort(vec[mx].begin(), vec[mx].end());
		for(int i = 0; i < vec[mx].size() - n/2; ++i) ans -= vec[mx][i];
		print(ans);
		putchar(10);
	}
}
}

int main() {
	MAIN();
	return 0;
}
