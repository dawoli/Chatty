#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=2e5+5;
int n, a[MAXN], T;
void init() {
	n=0;
	memset (a, 0, sizeof(a));
}
long long calc (long long sel) {
	long long ans=0;
	bool c[n+1];
	for (int i=n; i>=1; i--) {
		c[i]=sel%2;
		sel>>1;
	}
	int pos[2]={0, 0};
	for (int i=1; i<=n; i++) {
		if (pos[c[i]]==0) pos[c[i]]=i;
		else {
			ans+=(a[i]==a[pos[c[i]]])?a[i]:0;
			pos[c[i]]=i;
		}
	}
	return ans;
}
long long dfs (int pos, long long sel) {
	if (pos<n) return max(dfs(pos+1, (sel<<1)+1), dfs(pos+1, sel<<1));
	else return calc(sel);
}
int main () {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> T;
	while (T--) {
		init();
		cin >> n;
		for (int i=1; i<=n; i++) cin >> a[i];
		cout << dfs (0, 0) << "\n";
	}
}
