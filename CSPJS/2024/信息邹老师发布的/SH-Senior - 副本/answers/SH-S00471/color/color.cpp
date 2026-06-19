#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005];
bool c[10005];
int f[10005];
int ans;

int calc() {
	int ret = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++)
			if(c[i] == c[j] && a[i] == a[j])
				{ f[i] = a[i]; continue; }
	}
	for(int i = 1; i <= n; i++) ret += f[i];
	return ret;
}

void generate() {
	for(int i = 0; i < (2 << (n - 1)); i++) {
		int ii = i;
		for(int j = 1; j <= n; j++)
			c[j] = ii % 2, ii /= 2;
		ans = max(ans, calc());
	}
} 

void Main() {
	memset(f, 0, sizeof f);
	ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	generate();
	cout << ans << endl;
	return ;
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int Q;
	cin >> Q;
	while(Q--) {
		Main();
	}
	return 0;
} 
